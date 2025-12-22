#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

const int ROWS=10;
const int COLS=10;

int main(){

    const char* map[ROWS][COLS]={
        {".", ".", ".", "#", "#", "#", "#", "#", "#", "#"},
        {".", "E", ".", ".", ".", ".", ".", ".", ".", "#"},
        {".", ".", ".", "#", "#", "#", "#", "#", ".", "#"},
        {".", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
        {"#", "#", "#", "#", "#", "#", ".", "#", ".", "#"},
        {".", ".", ".", ".", ".", "#", ".", "#", ".", "#"},
        {".", "#", "#", "#", ".", "#", ".", "#", ".", "#"},
        {".", ".", ".", "#", ".", "#", ".", "#", ".", "#"},
        {".", "#", ".", "#", ".", "#", ".", ".", ".", "B"},
        {".", "#", "#", "#", "#", "#", "#", "#", "#", "#"}
    };

    const char emptyGround='.';
    const char pathWall='#';
    const char enemy='E';
    const char base='B';

    int enemyX=1;
    int enemyY=1;

    return 0;
}


