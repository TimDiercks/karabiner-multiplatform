#include <keySender.h>
#include <windows.h>

#include <iostream>

int getUpIndex(int index, int size, bool reverseRelease) {
    if (reverseRelease) {
        return (size - index - 1) % size;
    } else {
        return index * 2 + 1;
    }
}

int getDownIndex(int index, int size, bool reverseRelease) {
    if (reverseRelease) {
        return index;
    } else {
        return index * 2;
    }
}

void sendKeyList(std::vector<int> keys, bool reverseRelease) {
    int size = keys.size();
    if (keys.size() == 0) {
        return;
    }
    INPUT *input = new INPUT[size * 2];
    for (int i = 0; i < size; ++i) {
        // Key down event
        int downIndex = getDownIndex(i, size * 2, reverseRelease);
        input[downIndex].type = INPUT_KEYBOARD;
        input[downIndex].ki.wVk = keys[i];
        input[downIndex].ki.dwFlags = 0;

        // Key up event
        int upIndex = getUpIndex(i, size * 2, reverseRelease);
        input[upIndex].type = INPUT_KEYBOARD;
        input[upIndex].ki.wVk = keys[i];
        input[upIndex].ki.dwFlags = KEYEVENTF_KEYUP;
    }

    SendInput(size * 2, input, sizeof(INPUT));
}
