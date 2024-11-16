#include <iostream>
#include "keyEventManager/getKeyEvent.h"

int main()
{
    std::cout << "Starting key event listener..." << std::endl;

    // Start capturing key events
    getKeyEvent();

    return 0;
}
