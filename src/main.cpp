#include <iostream>
#include <chrono> //for miliseconds
#include <thread> //for sleep function
#include <vector> //for enemies hardcoded path
#include <windows.h> //for replacing "system("cls")"
#include "Enemy.h"
#include "Tower.h"
#include "world.h"
#include "render.h"

using std::cin;
using std::cout;
using std::endl;
//map constants
const int ROWS = 10;
const int COLS = 10;
const char emptyGround = '.';
const char pathWall = '#';
const char enemy = 'E';
const char base = 'B';
//ANSI color codes
const char* RED   = "\x1b[1;31m";
const char* BLUE  = "\x1b[1;34m";
const char* RESET = "\x1b[0m";
//constant border, could be improved to work with every size of map
const char* topAndBottomBorder = "+---------------------+";

struct Point {
    int x;
    int y;
};

//enemies hardcoded path
std::vector<std::pair<int, int>> path = {
    {1,1}, {1,2}, {2,2}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6},
    {4,6}, {5,6}, {6,6}, {7,6}, {8,6}, {8,7}, {8,8}, {8,9}
};

//function to replace system("cls")"
void clearScreen() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {0, 0};
    SetConsoleCursorPosition(hOut, position);
}

//function to enable ANSI for colored text in windows console
void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

//function for erasing the console and printing the map again
void render(char map[ROWS][COLS]) {
    clearScreen(); //works only on windows
    //cout << "\x1b[2J\x1b[H"; //works everywhere but it flickers on windows
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

//function for slowing down the enemies movement so the enemy doesn't "teleport"
void timing() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

//function for updating the enemies coordinates along the hardcoded path
void updateEnemiesCoord(char map[ROWS][COLS], Enemy& en) {
    if (!en.alive) return;
    if (en.pathIndex + 1 < path.size()){
        map[en.x][en.y] = emptyGround;
        en.pathIndex++;
        en.x = path[en.pathIndex].first;
        en.y = path[en.pathIndex].second;
        map[en.x][en.y] = enemy;
        render(map);
        timing();
    }
    else {
        en.alive = 0;
        map[en.x][en.y] = emptyGround;
        cout <<"Enemy reached the base!" << endl;
        timing();
    }
}

int main() {
    enableANSI();
    char map[ROWS][COLS]= {
        {'.', '.', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'.', 'E', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'.', '.', '.', '#', '#', '#', '#', '#', '.', '#'},
        {'.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '.', '#', '.', '#'},
        {'.', '.', '.', '.', '.', '#', '.', '#', '.', '#'},
        {'.', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
        {'.', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'.', '#', '.', '#', '.', '#', '.', '.', '.', 'B'},
        {'.', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    //initial enemy coordinates
    Enemy enemy1;
    enemy1.x = 1;
    enemy1.y = 1;
    enemy1.health = 10;
    enemy1.strength = 1;
    enemy1.pathIndex = 0;
    enemy1.alive = 1;
    
    while(enemy1.alive) {
        updateEnemiesCoord(map, enemy1);
    }

    return 0;
}


