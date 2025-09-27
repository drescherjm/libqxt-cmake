#pragma once
#ifndef QXTX11COMPAT_H
#define QXTX11COMPAT_H

// This file was generated with the help of Microsoft Copilot. 

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    #include <QGuiApplication>
    #include <QDebug>
    #include <X11/Xlib.h>
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
        qWarning() << "Wayland detected — X11 access not available.";
        return nullptr; // Wayland doesn't expose X11 Display
    }
    #if QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)
        auto* native = qGuiApp->nativeInterface<QNativeInterface::QX11Application>();
        return native->display();
    #else
        qWarning() << "Qt 6.0 to 6.4 is not supported.";
        return nullptr;
    #endif
#else
    return QX11Info::display();
#endif
}

inline Window qxtX11RootWindow() {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    if (qxtIsWayland()) {
        return 0; // No root window in Wayland
    }
    #if QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)
        auto* x11App = qGuiApp->nativeInterface<QNativeInterface::QX11Application>();
        if (!x11App)
            return 0;

        Display* display = x11App->display();
        if (!display)
            return 0;

        return RootWindow(display, DefaultScreen(display));
    #else
        qWarning() << "Qt 6.0 to 6.4 is not supported.";
        return 0;
    #endif
#else
    return QX11Info::appRootWindow();
#endif
}

#endif // QXTX11COMPAT_H

