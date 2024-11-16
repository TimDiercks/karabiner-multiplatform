#ifdef _WIN32
#include "getKeyEvent.h"
#include <windows.h>
#include <vector>

static std::vector<char> pressedKeys;

// Keyboard hook procedure
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION)
    {
        KBDLLHOOKSTRUCT *pKeyboard = (KBDLLHOOKSTRUCT *)lParam;
        int vkCode = pKeyboard->vkCode;
        int size = pressedKeys.size();

        if (wParam == WM_KEYDOWN)
        {
            if ((size > 0 && std::find(pressedKeys.begin(), pressedKeys.end(), vkCode) == pressedKeys.end()) || vkCode == VK_CAPITAL)
            {
                pressedKeys.push_back(vkCode);
            }
            if (pressedKeys.size() > 0)
            {
                return 1;
            }
        }
        else if (wParam == WM_KEYUP)
        {
            if (vkCode == VK_CAPITAL)
            {
                pressedKeys.clear();
                if (size == 1)
                {
                    INPUT input[2] = {};

                    // First, simulate key press (VK_ESCAPE)
                    input[0].type = INPUT_KEYBOARD;
                    input[0].ki.wVk = VK_ESCAPE; // Virtual key code for ESC
                    input[0].ki.dwFlags = 0;     // 0 means key down

                    // Now, simulate key release (VK_ESCAPE)
                    input[1].type = INPUT_KEYBOARD;
                    input[1].ki.wVk = VK_ESCAPE;           // Virtual key code for ESC
                    input[1].ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP means key release

                    // Send the key press and key release events
                    SendInput(2, input, sizeof(INPUT));
                }
                return 1;
            }
            else
            {
                pressedKeys.erase(std::remove(pressedKeys.begin(), pressedKeys.end(), vkCode), pressedKeys.end());
            }
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void getKeyEvent()
{
    HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (hHook == NULL)
    {
        std::cerr << "Failed to set hook!" << std::endl;
        return;
    }

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    // Cleanup
    UnhookWindowsHookEx(hHook);
}
#endif