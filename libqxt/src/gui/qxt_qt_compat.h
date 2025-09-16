#ifndef QXT_QT_COMPAT_H
#define QXT_QT_COMPAT_H

#include <QtGlobal>
#include <QPixmapCache>
#include <QPixmap>
#include <QString>
#include <QTextDocument>

namespace QxtCompat {

	// In Qt6 , QPixmapCache::find re
	inline bool findPixmap(const QString& key, QPixmap& outPixmap) {
		return QPixmapCache::find(key, &outPixmap);
	}

	// Replacement for Qt::mightBeRichText
	inline bool mightBeRichText(const QString& text) {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
		// Heuristic or QTextDocument-based check
		return text.contains('<') && text.contains('>');
#else
		return Qt::mightBeRichText(text);
#endif
	}

} // namespace QxtCompat

#endif // QXT_QT_COMPAT_H
