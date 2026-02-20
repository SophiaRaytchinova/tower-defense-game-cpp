#include "../include/displayUtils.h"
#include "../include/world.h"

#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

using std::cout;
using std::endl;

const char* RED   = "\x1b[1;31m";
const char* BLUE  = "\x1b[1;34m";
const char* RESET = "\x1b[0m";

const char emptyGround = '.';
const char pathWall = '#';
const char enemy = 'E';
const char base = 'B';
const char* topAndBottomBorder = "+---------------------+";

void render(char map[ROWS][COLS]) {
    clearScreen();
    cout << topAndBottomBorder << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "| ";
        for (int j = 0; j < COLS; j++){
            if (map[i][j] == 'E') {
                cout << RED << map[i][j] << RESET << " ";
            }
            else if (map[i][j] == 'B') {
                cout << BLUE << map[i][j] << RESET << " ";
            }
            else cout << map[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << topAndBottomBorder << endl;
}

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
