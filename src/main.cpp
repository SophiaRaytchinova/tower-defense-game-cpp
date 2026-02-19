#include "../include/displayUtils.h"
#include "../include/world.h"
#include "../include/entities.h"
#include <iostream>

int main() {
    enableANSI();

    char map[ROWS][COLS]= {
        {'E', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', 'B'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    widenPath(map);

    Enemy enemy1{0, 0, 100.0, 100.0, 0, 0, 'E', true};
    std::vector<Enemy> enemies = {enemy1};

    int defenseTowerCount;
    std::cout << "Enter number of defense towers: ";
    std::cin >> defenseTowerCount;
    if (defenseTowerCount > 15) defenseTowerCount = 15;

    std::vector<DefenseTower> defenses;
    placeRandomDefenseTowers(map, defenses, defenseTowerCount);
 
    while (!enemies.empty()) {

        attackEnemies(defenses, enemies);
        for (auto& e : enemies) updateEnemiesCoord(map, e);

        for (auto& e : enemies) drawHPBar(e);

        for (int i = enemies.size() - 1; i >= 0; i--) {
            if (!enemies[i].alive) enemies.erase(enemies.begin() + i);
        }
        render(map);
        timing();
    }

    return 0;
}


