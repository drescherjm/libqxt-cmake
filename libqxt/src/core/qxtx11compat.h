#ifndef QXTX11COMPAT_H
#define QXTX11COMPAT_H

// This file was generated with the help of Microsoft Copilot. 

#include <X11/Xlib.h>

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    #include <QGuiApplication>
    #include <QString>
#else
    #include <QX11Info>
#endif

inline bool qxtIsWayland() {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    return QGuiApplication::platformName().startsWith("wayland", Qt::CaseInsensitive);
#else
    return false;
#endif
}

inline Display* qxtX11Display() {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    if (qxtIsWayland()) {
        return nullptr; // Wayland doesn't expose X11 Display
    }
    auto* native = QGuiApplication::nativeInterface();
    return static_cast<Display*>(native->nativeResourceForWindow("display", nullptr));
#else
    return QX11Info::display();
#endif
}

inline Window qxtX11RootWindow() {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    if (qxtIsWayland()) {
        return 0; // No root window in Wayland
    }
    auto* native = QGuiApplication::nativeInterface();
    return static_cast<Window>(native->nativeResourceForWindow("rootwindow", nullptr));
#else
    return QX11Info::appRootWindow();
#endif
}

#endif // QXTX11COMPAT_H

