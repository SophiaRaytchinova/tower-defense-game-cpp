#include <iostream>

#include "../include/world.h"
#include "../include/display_utils.h"
#include "../include/entities.h"

using std::cout;
using std::endl;

std::vector<std::pair<int, int>> path = {
    {1,1}, {1,2}, {2,2}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6},
    {4,6}, {5,6}, {6,6}, {7,6}, {8,6}, {8,7}, {8,8}, {8,9}
};

void updateEnemiesCoord(char map[ROWS][COLS], Enemy &en) {
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
