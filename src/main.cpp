#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

const int ROWS=10;
const int COLS=10;

std::vector<std::pair<int, int>> path = {
        {1,1}, {1,2}, {2,2}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6},
        {4,6}, {5,6}, {6,6}, {7,6}, {8,6}, {8,7}, {8,8}, {8,9}
    };

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


