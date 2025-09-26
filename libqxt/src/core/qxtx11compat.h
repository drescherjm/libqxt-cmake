#ifndef QXTX11COMPAT_H
#define QXTX11COMPAT_H

#include <QtGlobal>

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    #include <QGuiApplication>
    #include <QPlatformNativeInterface>
#else
    #include <QX11Info>
#endif

#include <X11/Xlib.h>

inline Display* qxtX11Display() {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    return static_cast<Display*>(
        QGuiApplication::platformNativeInterface()->nativeResourceForWindow("display", nullptr));
#else
    return QX11Info::display();
#endif
}

inline Window qxtX11RootWindow() {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    return static_cast<Window>(
        QGuiApplication::platformNativeInterface()->nativeResourceForWindow("rootwindow", nullptr));
#else
    return QX11Info::appRootWindow();
#endif
}

#endif // QXTX11COMPAT_H
