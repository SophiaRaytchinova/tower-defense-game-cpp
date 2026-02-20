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

    Tower tower {8, 9, 'B'};

    Enemy enemy1{0, 0, 100.0, 100.0, 0, 0, 'E', true};
    std::vector<Enemy> enemies = {enemy1};

    int defenseTowerCount;
    while (true) {
        std::cout << "Enter number of defense towers: ";
        std::cin >> defenseTowerCount;

        if (!std::cin.fail() && defenseTowerCount > 0) break;

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << "Invalid input. Try again.\n";
    }
    
    if (defenseTowerCount < 1) {
        defenseTowerCount = 1; 
        std::cout << "At least one tower is required. Setting defense tower count to 1." << std::endl;
    }
    else if (defenseTowerCount > 15) {
        defenseTowerCount = 15; 
        std::cout << "Too many towers! Setting defense tower count to maximum." << std::endl;
    }
    
    system("cls");
    hideCursor();

    std::vector<DefenseTower> defenses;
    placeRandomDefenseTowers(map, defenses, defenseTowerCount);
 
    while (!enemies.empty()) {

        attackEnemies(defenses, enemies);
        for (int i = enemies.size() - 1; i >= 0; i--) {
            if (!enemies[i].alive) enemies.erase(enemies.begin() + i);
        }

        for (Enemy& e : enemies) updateEnemiesCoord(map, e);

        // check if enemy reached the base position
        for (const Enemy& e : enemies) {
            if (e.x == tower.x && e.y == tower.y) {
                std::cout << "Enemy reached the base! Game Over!" << std::endl;
                return 0;
            }
        }

        render(map, enemies);
        sleep();
    }

    // if enemy reached base ...
    // else user wins

    return 0;
}


