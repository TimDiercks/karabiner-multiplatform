#include "hotKeyManager.h"

// using Shortcut = std::vector<char>;

// std::unordered_map<Shortcut, std::function<void()>,
//                    std::hash<std::string>, std::equal_to<>>
//     shortcutActions;

// void registerShortcut(const Shortcut &shortcut, std::function<void()> action)
// {
//     shortcutActions[shortcut] = action;
// }

// void setupShortcuts()
// {
//     // Define some example shortcuts
//     registerShortcut({'o', 'a'}, []() { // SUPER + O + A
//         std::cout << "SUPER + O + A Shortcut Activated!" << std::endl;
//     });
//     registerShortcut({'a', 'o'}, []() { // SUPER + A + O (different order)
//         std::cout << "SUPER + A + O Shortcut Activated!" << std::endl;
//     });
//     // Add more shortcuts as needed
// }

// void checkShortcuts()
// {
//     for (const auto &[shortcut, action] : shortcutActions)
//     {
//         if (shortcut == pressedKeys) // If the order matches this shortcut
//         {
//             action(); // Execute the associated action
//             break;    // Exit loop to prevent multiple matches (optional)
//         }
//     }
// }