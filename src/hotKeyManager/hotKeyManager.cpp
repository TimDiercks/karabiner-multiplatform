#include <hotKeyManager.h>
#include <keyCodes.h>
#include <keySender.h>

#include <iostream>
#include <vector>

static std::vector<int> pressedKeys;
bool hotKeyActive = false;

void addActiveKey(int keyCode) {
    if (std::find(pressedKeys.begin(), pressedKeys.end(), keyCode) ==
        pressedKeys.end())
        pressedKeys.push_back(keyCode);
}

void removeActiveKey(int keyCode) {
    pressedKeys.erase(
        std::remove(pressedKeys.begin(), pressedKeys.end(), keyCode),
        pressedKeys.end());
}

bool handleKeyEvent(int keyCode, bool isPressed) {
    int size = pressedKeys.size();
    if (hotKeyActive) {
        return false;
    }

    if (isPressed) {
        if (size > 0 || keyCode == KEY_CAPS_LOCK) {
            addActiveKey(keyCode);
        }
        // Check for hotkey
        if (size == 2) {
            if (pressedKeys[1] == 'V') {
                if (keyCode == 'H') {
                    hotKeyActive = true;
                    sendKeyList({KEY_LEFT}, false);
                    removeActiveKey(keyCode);
                    hotKeyActive = false;
                } else if (keyCode == 'J') {
                    hotKeyActive = true;
                    sendKeyList({KEY_DOWN}, false);
                    hotKeyActive = false;
                    removeActiveKey(keyCode);
                } else if (keyCode == 'K') {
                    hotKeyActive = true;
                    sendKeyList({KEY_UP}, false);
                    removeActiveKey(keyCode);
                    hotKeyActive = false;
                } else if (keyCode == 'L') {
                    hotKeyActive = true;
                    sendKeyList({KEY_RIGHT}, false);
                    removeActiveKey(keyCode);
                    hotKeyActive = false;
                }

                return true;
            }
        }
        if (pressedKeys.size() > 0) {
            return true;
        }
    } else {
        if (keyCode == KEY_CAPS_LOCK) {
            pressedKeys.clear();
            if (size == 1) {
                sendKeyList({KEY_ESCAPE}, false);
            }
            return true;
        } else {
            removeActiveKey(keyCode);
        }
    }

    return false;
}