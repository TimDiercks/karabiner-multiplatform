#pragma once

#include <string>
#include <unordered_map>

// Special keys
#define KEY_BACKSPACE 8
#define KEY_TAB 9
#define KEY_SHIFT 16
#define KEY_CAPS_LOCK 20
#define KEY_ESCAPE 27
#define KEY_SPACE 32
#define KEY_PAGE_UP 33
#define KEY_PAGE_DOWN 34
#define KEY_INSERT 45
#define KEY_DELETE 46

// Function keys
#define KEY_F1 112
#define KEY_F2 113
#define KEY_F3 114
#define KEY_F4 115
#define KEY_F5 116
#define KEY_F6 117
#define KEY_F7 118
#define KEY_F8 119
#define KEY_F9 120
#define KEY_F10 121
#define KEY_F11 122
#define KEY_F12 123

// Arrow keys
#define KEY_LEFT 37
#define KEY_UP 38
#define KEY_RIGHT 39
#define KEY_DOWN 40

// Mouse keys
#define KEY_LEFT_MOUSE_BUTTON 1
#define KEY_RIGHT_MOUSE_BUTTON 2
#define KEY_MIDDLE_MOUSE_BUTTON 4

// Media keys
#define KEY_MEDIA_VOLUME_MUTE 173
#define KEY_MEDIA_VOLUME_DOWN 174
#define KEY_MEDIA_VOLUME_UP 175
#define KEY_MEDIA_NEXT_TRACK 176
#define KEY_MEDIA_PREV_TRACK 177
#define KEY_MEDIA_STOP 178
#define KEY_MEDIA_PLAY_PAUSE 179

std::unordered_map<std::string, int> keyMap = {
    {"BACKSPACE", KEY_BACKSPACE},
    {"TAB", KEY_TAB},
    {"SHIFT", KEY_SHIFT},
    {"CAPS_LOCK", KEY_CAPS_LOCK},
    {"ESCAPE", KEY_ESCAPE},
    {"SPACE", KEY_SPACE},
    {"PAGE_UP", KEY_PAGE_UP},
    {"PAGE_DOWN", KEY_PAGE_DOWN},
    {"INSERT", KEY_INSERT},
    {"DELETE", KEY_DELETE},
    {"F1", KEY_F1},
    {"F2", KEY_F2},
    {"F3", KEY_F3},
    {"F4", KEY_F4},
    {"F5", KEY_F5},
    {"F6", KEY_F6},
    {"F7", KEY_F7},
    {"F8", KEY_F8},
    {"F9", KEY_F9},
    {"F10", KEY_F10},
    {"F11", KEY_F11},
    {"F12", KEY_F12},
    {"LEFT", KEY_LEFT},
    {"UP", KEY_UP},
    {"RIGHT", KEY_RIGHT},
    {"DOWN", KEY_DOWN},
    {"LEFT_MOUSE_BUTTON", KEY_LEFT_MOUSE_BUTTON},
    {"RIGHT_MOUSE_BUTTON", KEY_RIGHT_MOUSE_BUTTON},
    {"MIDDLE_MOUSE_BUTTON", KEY_MIDDLE_MOUSE_BUTTON},
    {"MEDIA_VOLUME_MUTE", KEY_MEDIA_VOLUME_MUTE},
    {"MEDIA_VOLUME_DOWN", KEY_MEDIA_VOLUME_DOWN},
    {"MEDIA_VOLUME_UP", KEY_MEDIA_VOLUME_UP},
    {"MEDIA_NEXT_TRACK", KEY_MEDIA_NEXT_TRACK},
    {"MEDIA_PREV_TRACK", KEY_MEDIA_PREV_TRACK},
    {"MEDIA_STOP", KEY_MEDIA_STOP},
    {"MEDIA_PLAY_PAUSE", KEY_MEDIA_PLAY_PAUSE}};

// Access the key code using the string name
int getKeyCode(const std::string& keyName) {
    auto it = keyMap.find(keyName);
    if (it != keyMap.end()) {
        return it->second;
    } else {
        return -1;  // Return -1 if key is not found
    }
}
