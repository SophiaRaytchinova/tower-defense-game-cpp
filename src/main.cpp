#include "../include/displayUtils.h"
#include "../include/world.h"
#include "../include/entities.h"
#include <iostream>

int main() {
    enableANSI();

    char map[ROWS][COLS]= {
        {'E', '#', '#', '#', '#', '#', '.', '.', '.', '.'},
        {'.', '#', '.', '.', '.', '#', '.', '#', '#', '.'},
        {'.', '#', '.', '#', '.', '#', '.', '.', '#', '.'},
        {'.', '#', '.', '#', '.', '.', '#', '.', '#', '.'},
        {'.', '#', '.', '.', '#', '.', '#', '.', '#', '.'},
        {'.', '.', '#', '.', '#', '.', '#', '.', '#', '.'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.'},
        {'#', '.', '.', '.', '#', '.', '#', '.', '#', 'B'},
        {'#', '#', '#', '#', '#', '.', '.', '.', '#', '#'}
    };

    Enemy enemy1{0, 0, 100.0, 100.0, 0, 0, 'E', true};
    std::vector<Enemy> enemies = {enemy1};

    int defenseTowerCount;
    std::cout << "Enter number of defense towers: ";
    std::cin >> defenseTowerCount;
    if (defenseTowerCount > 15) defenseTowerCount = 15; // max number of towers so they dont get stuck due to the limit not being next to each other

    std::vector<DefenseTower> defenses;
    placeRandomDefenseTowers(map, defenses, defenseTowerCount);
 
    while (!enemies.empty()) {

        attackEnemies(defenses, enemies);
        for (auto& e : enemies) updateEnemiesCoord(map, e);

        //render(map);
        //timing(); //added for slowing down
        for (auto& e : enemies) drawHPBar(e);

        for (int i = enemies.size() - 1; i >= 0; i--) {
            if (!enemies[i].alive) enemies.erase(enemies.begin() + i);
        }
        render(map);
        timing();
    }

    return 0;
}


