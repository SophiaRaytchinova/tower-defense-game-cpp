#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

const int ROWS = 10;
const int COLS = 10;

const char emptyGround = '.';
const char pathWall = '#';
const char enemy = 'E';
const char base = 'B';

std::vector<std::pair<int, int>> path = {
    {1,1}, {1,2}, {2,2}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6},
    {4,6}, {5,6}, {6,6}, {7,6}, {8,6}, {8,7}, {8,8}, {8,9}
};

void render(char map[ROWS][COLS]) {
    system("cls");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++){
            if (map[i][j] == 'E') {
                cout << "\x1b[1;31m" << map[i][j] << "\x1b[0m ";
            }
            else if (map[i][j] == 'B') {
                cout << "\x1b[1;34m" << map[i][j] << "\x1b[0m ";
            }
            else cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void timing() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void update(char map[ROWS][COLS], int &enemyX, int &enemyY) {
    for (int i = 0; i < path.size(); i++) {
        if (path[i].first == enemyX && path[i].second == enemyY) {
            if (i + 1 < path.size()) {
                map[enemyX][enemyY] = '.';
                enemyX = path[i + 1].first;
                enemyY = path[i + 1].second;
                map[enemyX][enemyY] = 'E';
                render(map);
                timing();
            }
        }
    }
}

int main(){
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

    int enemyX = 1;
    int enemyY = 1;

    while(true) {
        update(map, enemyX, enemyY);
        render(map);
        timing();
    }

    return 0;
}


