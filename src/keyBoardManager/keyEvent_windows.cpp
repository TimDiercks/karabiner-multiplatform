#ifdef _WIN32
#include <hotKeyManager.h>
#include <keyEvent.h>
#include <keySender.h>
#include <windows.h>

#include <vector>

// Keyboard hook procedure
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT *pKeyboard = (KBDLLHOOKSTRUCT *)lParam;
        int vkCode = pKeyboard->vkCode;

        bool blockInput = handleKeyEvent(vkCode, wParam == WM_KEYDOWN);
        if (blockInput) {
            return 1;
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void getKeyEvent() {
    HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (hHook == NULL) {
        std::cerr << "Failed to set hook!" << std::endl;
        return;
    }

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    // Cleanup
    UnhookWindowsHookEx(hHook);
}
#endif