/****************************************************************************
 **
 ** Copyright (C) Qxt Foundation. Some rights reserved.
 **
 ** This file is part of the QxtGui module of the Qxt library.
 **
 ** This library is free software; you can redistribute it and/or modify it
 ** under the terms of the Common Public License, version 1.0, as published
 ** by IBM, and/or under the terms of the GNU Lesser General Public License,
 ** version 2.1, as published by the Free Software Foundation.
 **
 ** This file is provided "AS IS", without WARRANTIES OR CONDITIONS OF ANY
 ** KIND, EITHER EXPRESS OR IMPLIED INCLUDING, WITHOUT LIMITATION, ANY
 ** WARRANTIES OR CONDITIONS OF TITLE, NON-INFRINGEMENT, MERCHANTABILITY OR
 ** FITNESS FOR A PARTICULAR PURPOSE.
 **
 ** You should have received a copy of the CPL and the LGPL along with this
 ** file. See the LICENSE file and the cpl1.0.txt/lgpl-2.1.txt files
 ** included with the source distribution for more information.
 ** If you did not receive a copy of the licenses, contact the Qxt Foundation.
 **
 ** <http://libqxt.org>  <foundation@libqxt.org>
 **
 ****************************************************************************/
#include "qxtprogresslabel.h"
#include <QProgressBar>
#include <QBasicTimer>
#include <QElapsedTimer>
#include <QTime>

class QxtProgressLabelPrivate : public QxtPrivate<QxtProgressLabel>
{
public:
    QXT_DECLARE_PUBLIC(QxtProgressLabel)
    QxtProgressLabelPrivate();

    QElapsedTimer start;
    int interval;
    int cachedMin;
    int cachedMax;
    int cachedVal;
    QString cformat;
    QString tformat;
    QBasicTimer timer;
};

QxtProgressLabelPrivate::QxtProgressLabelPrivate()
        : interval(-1), cachedMin(0), cachedMax(0), cachedVal(0)
{}

/*!
    \class QxtProgressLabel
    \inmodule QxtGui
    \brief The QxtProgressLabel widget is a label showing progress related time values.

    QxtProgressLabel is a label widget able to show elapsed and remaining
    time of a progress. Usage is as simple as connecting signal
    QProgressBar::valueChanged() to slot QxtProgressLabel::setValue().

    Example usage:
    \code
    QProgressBar* bar = new QProgressBar(this);
    QxtProgressLabel* label = new QxtProgressLabel(this);
    connect(bar, SIGNAL(valueChanged(int)), label, SLOT(setValue(int)));
    \endcode

    \image qxtprogresslabel.png "QxtProgressLabel in action."
 */

/*!
    Constructs a new QxtProgressLabel with \a parent and \a flags.
 */
QxtProgressLabel::QxtProgressLabel(QWidget* parent, Qt::WindowFlags flags)
        : QLabel(parent, flags)
{
    QXT_INIT_PRIVATE(QxtProgressLabel);
    refresh();
}

/*!
    Constructs a new QxtProgressLabel with \a text, \a parent and \a flags.
 */
QxtProgressLabel::QxtProgressLabel(const QString& text, QWidget* parent, Qt::WindowFlags flags)
        : QLabel(text, parent, flags)
{
    QXT_INIT_PRIVATE(QxtProgressLabel);
    refresh();
}

/*!
    Destructs the progress label.
 */
QxtProgressLabel::~QxtProgressLabel()
{}

/*!
    \property QxtProgressLabel::contentFormat
    \brief the content format of the progress label

    The content of the label is formatted according to this property.
    The default value is an empty string which defaults to \bold "ETA: %r".

    The following variables may be used in the format string:
    \table
    \header \o Variable \o Output
    \row \o \%e \o elapsed time
    \row \o \%r \o remaining time
    \endtable

    \sa timeFormat
 */
QString QxtProgressLabel::contentFormat() const
{
    return qxt_d().cformat;
}

void QxtProgressLabel::setContentFormat(const QString& format)
{
    if (qxt_d().cformat != format)
    {
        qxt_d().cformat = format;
        refresh();
    }
}

/*!
    \property QxtProgressLabel::timeFormat
    \brief the time format of the progress label

    Time values are formatted according to this property.
    The default value is an empty string which defaults to \bold "mm:ss".

    \sa contentFormat, QTime::toString()
 */
QString QxtProgressLabel::timeFormat() const
{
    return qxt_d().tformat;
}

void QxtProgressLabel::setTimeFormat(const QString& format)
{
    if (qxt_d().tformat != format)
    {
        qxt_d().tformat = format;
        refresh();
    }
}

/*!
    \property QxtProgressLabel::updateInterval
    \brief the update interval of the progress label

    The content of the progress label is updated according to this interval.
    A negative interval makes the content to update only during value changes.
    The default value is \c -1.
 */
int QxtProgressLabel::updateInterval() const
{
    return qxt_d().interval;
}

void QxtProgressLabel::setUpdateInterval(int msecs)
{
    qxt_d().interval = msecs;
    if (msecs < 0)
    {
        if (qxt_d().timer.isActive())
            qxt_d().timer.stop();
    }
    else
    {
        if (!qxt_d().timer.isActive())
            qxt_d().timer.start(msecs, this);
    }
}

/*!
    Sets the current value to \a value.

    \bold {Note:} Calling this slot by hand has no effect.
    Connect this slot to QProgressBar::valueChange().
 */
void QxtProgressLabel::setValue(int value)
{
    QProgressBar* bar = qobject_cast<QProgressBar*>(sender());
    if (bar)
    {
        if (!qxt_d().start.isValid())
            restart();

        qxt_d().cachedMin = bar->minimum();
        qxt_d().cachedMax = bar->maximum();
        qxt_d().cachedVal = value;

        refresh();
    }
}

/*!
    Restarts the calculation of elapsed and remaining times.
 */
void QxtProgressLabel::restart()
{
    qxt_d().cachedMin = 0;
    qxt_d().cachedMax = 0;
    qxt_d().cachedVal = 0;
    qxt_d().start.restart();
    refresh();
}


static QString formatDuration(int totalSeconds, const QString& tformat)
{
	if (totalSeconds < 0)
		totalSeconds = 0;

	int days = totalSeconds / 86400;
	int hours = (totalSeconds % 86400) / 3600;
	int minutes = (totalSeconds % 3600) / 60;
	int seconds = totalSeconds % 60;

	// If a day-aware format is requested, handle %d as a days token
	// before falling through to QTime for the time portion.
	// Supported tformat tokens: "dd hh:mm:ss", "hh:mm:ss", "mm:ss"
	if (days > 0 || tformat.contains("dd"))
	{
		// Build a human-readable string that always shows days when non-zero
		if (tformat.contains("dd"))
		{
			// User explicitly asked for the dd token — honour the full format
			QString result = tformat;
			result.replace("dd", QString::number(days));
			result.replace("hh", QString("%1").arg(hours, 2, 10, QChar('0')));
			result.replace("mm", QString("%1").arg(minutes, 2, 10, QChar('0')));
			result.replace("ss", QString("%1").arg(seconds, 2, 10, QChar('0')));
			return result;
		}
		else
		{
			// Overflow: prepend the day count automatically
			QTime t(hours, minutes, seconds);
			return QString("%1d %2").arg(days).arg(t.toString(tformat));
		}
	}

	// Under 24 hours — delegate to QTime exactly as the original code did
	QTime t(0, 0);
	t = t.addSecs(totalSeconds);
	return t.toString(tformat);
}

/*!
    Refreshes the content.
 */
void QxtProgressLabel::refresh()
{
	// elapsed
	qreal elapsed = 0;
	if (qxt_d().start.isValid())
		elapsed = qxt_d().start.elapsed() / 1000.0;

	// percentage
	qreal percent = 0;
	if (qxt_d().cachedMax != 0)
		percent = (qxt_d().cachedVal - qxt_d().cachedMin) / static_cast<qreal>(qxt_d().cachedMax);
	qreal total = 0;
	if (percent != 0)
		total = elapsed / percent;

	// remaining
	qreal remaining = total - elapsed;

	// format
	QString tformat = qxt_d().tformat;
	if (tformat.isEmpty())
		tformat = tr("mm:ss");
	QString cformat = qxt_d().cformat;
	if (cformat.isEmpty())
		cformat = tr("ETA: %r");

	QString result = QString(cformat).replace("%e", formatDuration(static_cast<int>(elapsed), tformat));
	result = result.replace("%r", formatDuration(static_cast<int>(remaining), tformat));
	setText(result);
}

/*!
    \reimp
 */
void QxtProgressLabel::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event);
    refresh();
}
