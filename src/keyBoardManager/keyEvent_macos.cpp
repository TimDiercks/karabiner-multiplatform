#ifdef __APPLE__
// NOT TESTED
#include <ApplicationServices/ApplicationServices.h>
#include <keyEvent.h>

CGEventRef eventCallback(CGEventTapProxy proxy, CGEventType type,
                         CGEventRef event, void *userInfo) {
    if (type == kCGEventKeyDown) {
        CGKeyCode keycode =
            CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

        if (keycode == kVK_Command) {
            std::cout << "Super (Command) Key Pressed!" << std::endl;
        }
    }
    return event;
}

void getKeyEvent() {
    CGEventMask eventMask = CGEventMaskBit(kCGEventKeyDown);
    CFMachPortRef eventTap = CGEventTapCreate(
        kCGSessionEventTap, kCGHeadInsertEventTap, kCGEventTapOptionListenOnly,
        eventMask, eventCallback, NULL);

    if (!eventTap) {
        std::cerr << "Failed to create event tap!" << std::endl;
        return;
    }

    CFRunLoopSourceRef runLoopSource =
        CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource,
                       kCFRunLoopCommonModes);
    CGEventTapEnable(eventTap, true);
    CFRunLoopRun();
}
#endif
