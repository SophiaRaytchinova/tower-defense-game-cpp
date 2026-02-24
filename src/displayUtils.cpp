#include "../include/displayUtils.h"
#include "../include/world.h"

#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <sstream>

using std::cout;
using std::endl;

const char* RED   = "\x1b[1;31m";
const char* BLUE  = "\x1b[1;34m";
const char* GREEN = "\x1b[38;5;82m";
const char* RESET = "\x1b[0m";

const char emptyGround = '.';
const char pathWall = '#';
const char enemy = 'E';
const char base = 'B';
const char* topAndBottomBorder = "+---------------------+";

void render(char map[ROWS][COLS], std::vector<Enemy>& enemies) {
    // Double buffering: build entire frame in memory first
    std::ostringstream buffer;
    buffer << topAndBottomBorder << endl;
    for (int i = 0; i < ROWS; i++) {
        buffer << "| ";
        for (int j = 0; j < COLS; j++){
            if (map[i][j] == 'E') {
                buffer << RED << map[i][j] << RESET << " ";
            }
            else if (map[i][j] == 'B') {
                buffer << BLUE << map[i][j] << RESET << " ";
            }
            else if (map[i][j] == 'T') {
                buffer << GREEN << map[i][j] << RESET << " ";
            }
            else buffer << map[i][j] << " ";
        }
        buffer << "|" << endl;
    }
    buffer << topAndBottomBorder << endl;
    if (!enemies.empty()) {
        buffer << "Enemy HP: " << enemies[0].health << "%" << std::endl;
    }
    
    // Clear screen once and display entire buffer at once
    clearScreen();
    cout << buffer.str();
    cout.flush();
    hideCursor();  // Hide cursor after all output
}

void clearScreen() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {0, 0};
    SetConsoleCursorPosition(hOut, position);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void sleep() {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
