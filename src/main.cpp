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
    

    std::vector<DefenseTower> defenses;
    placeRandomDefenseTowers(map, defenses, defenseTowerCount);
 
    while (!enemies.empty()) {

        attackEnemies(defenses, enemies);
        for (auto& e : enemies) updateEnemiesCoord(map, e);
        
        for (int i = enemies.size() - 1; i >= 0; i--) {
            if (!enemies[i].alive) enemies.erase(enemies.begin() + i);
        }
        render(map, enemies);
        timing();
    }

    return 0;
}


