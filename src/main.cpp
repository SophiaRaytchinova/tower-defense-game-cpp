#include "../include/utils.h"
#include "../include/world.h"
#include "../include/gameObjects.h"
#include "../include/symbolConstants.h"
#include "../include/colorConstants.h"
#include "../include/sizeConstants.h"
#include "../include/render.h"
#include "../include/path.h"

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

    Enemy enemy1{1, 1, 10, 1, 0, 'E', true};
    while(enemy1.alive) {
        updateEnemiesCoord(map, enemy1);
    }

    return 0;
}


