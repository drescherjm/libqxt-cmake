#ifndef QXTX11COMPAT_H
#define QXTX11COMPAT_H

// This file was generated with the help of Microsoft Copilot. 

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    #include <QGuiApplication>
    #include <QString>
    #include <QScreen>
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
        return nullptr; // Wayland doesn't expose X11 Display
    }
    auto* native = qGuiApp->nativeInterface<QNativeInterface::QX11Application>();
    return native->display();
#else
    return QX11Info::display();
#endif
}

inline Window qxtX11RootWindow() {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    if (qxtIsWayland()) {
        return 0; // No root window in Wayland
    }
    auto* native = qGuiApp->nativeInterface<QNativeInterface::QX11Application>();

    Display* dpy = native->display();


    // Get the primary screen (or any QScreen you want)
    QScreen* screen = QGuiApplication::primaryScreen();
    if (!screen) {
        return 0;
    }


    QPlatformNativeInterface  = screen->pla

    auto x11Screen = screen->nativeInterface<QNativeInterface::QX11Screen>();
    if (!x11Screen) {
        return 0;
    }

    int screenNumber = x11Screen->screen();

    return RootWindow(dpy,screenNumber);

#else
    return QX11Info::appRootWindow();
#endif
}

#endif // QXTX11COMPAT_H

