#include "../include/utils.h"
#include <windows.h>
#include <chrono>
#include <thread>

//ANSI color codes
const char* RED   = "\x1b[1;31m";
const char* BLUE  = "\x1b[1;34m";
const char* RESET = "\x1b[0m";

void clearScreen() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {0, 0};
    SetConsoleCursorPosition(hOut, position);
}

void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void timing() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

