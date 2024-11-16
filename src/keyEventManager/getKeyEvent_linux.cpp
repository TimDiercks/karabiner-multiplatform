#ifdef __linux__
// NOT TESTED
#include "getKeyEvent.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>

int getKeyCode

    void
    getKeyEvent()
{
    Display *display = XOpenDisplay(NULL);
    if (!display)
    {
        std::cerr << "Unable to open X display" << std::endl;
        return;
    }

    Window root = DefaultRootWindow(display);
    XGrabKey(display, XKeysymToKeycode(display, XK_Super_L), Mod4Mask, root, True, GrabModeAsync, GrabModeAsync);
    XSelectInput(display, root, KeyPressMask);

    while (true)
    {
        XEvent event;
        XNextEvent(display, &event);

        if (event.type == KeyPress)
        {
            std::cout << "Super Key Pressed!" << std::endl;
        }
    }

    XCloseDisplay(display);
}
#endif
