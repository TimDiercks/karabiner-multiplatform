cmake_minimum_required(VERSION 3.10)
project(KeyEventListener)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    "include/"
    "include/hotKeyManager"
    "include/keyBoardManager"
)

set(COMMON_SOURCES main.cpp src/hotKeyManager/hotKeyManager.cpp)

# Add source files based on the operating system
if (WIN32)
    add_executable(KeyEventListener ${COMMON_SOURCES} src/keyBoardManager/keyEvent_windows.cpp src/keyBoardManager/keySender_windows.cpp)
elseif (APPLE)
    add_executable(KeyEventListener ${COMMON_SOURCES} src/keyBoardManager/keyEvent_macos.cpp)
    target_link_libraries(KeyEventListener "-framework ApplicationServices")
elseif (UNIX)
    add_executable(KeyEventListener ${COMMON_SOURCES} src/keyBoardManager/keyEvent_linux.cpp)
    target_link_libraries(KeyEventListener X11)
endif()
