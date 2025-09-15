#pragma once

// This code was written wirh the help of ChatGPT

#include <QtGlobal>
#include <QSortFilterProxyModel>

#if QT_VERSION < QT_VERSION_CHECK(6,0,0)
#include <QRegExp>
#else
#include <QRegularExpression>
#endif

namespace qxtQtCompatFilterUtils {

#if QT_VERSION < QT_VERSION_CHECK(6,0,0)

    inline void setProxyFilterRegExp(QSortFilterProxyModel* proxy,
        const QString& pattern,
        Qt::CaseSensitivity caseSensitivity = Qt::CaseInsensitive,
        QRegExp::PatternSyntax syntax = QRegExp::RegExp)
    {
        QRegExp regExp(pattern, caseSensitivity, syntax);
        if (regExp.isValid())
            proxy->setFilterRegExp(regExp);
        else
            proxy->setFilterRegExp(QString());
    }

#else

    inline QString convertToRegex(const QString& pattern, QRegExp::PatternSyntax syntax)
    {
        switch (syntax) {
        case QRegExp::FixedString:
            return QRegularExpression::escape(pattern);
        case QRegExp::Wildcard: {
            QString rx = QRegularExpression::escape(pattern);
            rx.replace("\\*", ".*");
            rx.replace("\\?", ".");
            return "^" + rx + "$";
        }
        case QRegExp::RegExp2: // closest: just treat like a normal regex
        case QRegExp::RegExp:
        case QRegExp::W3CXmlSchema11:
        default:
            return pattern;
        }
    }

    inline void setProxyFilterRegExp(QSortFilterProxyModel* proxy,
        const QString& pattern,
        Qt::CaseSensitivity caseSensitivity = Qt::CaseInsensitive,
        QRegExp::PatternSyntax syntax = QRegExp::RegExp)
    {
        QString translated = convertToRegex(pattern, syntax);

        QRegularExpression::PatternOptions options = QRegularExpression::NoPatternOption;
        if (caseSensitivity == Qt::CaseInsensitive)
            options |= QRegularExpression::CaseInsensitiveOption;

        QRegularExpression regExp(translated, options);

        if (regExp.isValid())
            proxy->setFilterRegularExpression(regExp);
        else
            proxy->setFilterRegularExpression(QRegularExpression());
    }

#endif

} // namespace qxtQtCompatFilterUtils

