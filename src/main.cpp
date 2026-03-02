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
        {'#', '.', '.', '.', '#', '.', '#', '.', '#', '.'},
        {'#', '#', '#', '#', '#', '.', '.', '.', '#', 'B'}
    };

    BaseEntity base {9, 9, 'B'};

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
 
    bool enemyKilled = false;
    bool gameOver = false;
    std::string endMessage = "";

    while (!gameOver) {

        attackEnemies(defenses, enemies);
        
        for (int i = enemies.size() - 1; i >= 0; i--) {
            if (!enemies[i].alive) {
                enemies.erase(enemies.begin() + i);
                enemyKilled = true;
            }
        }

        if (enemies.empty()) {
            endMessage = "Congratulations! You killed the enemy!";
            gameOver = true;
        }    
        else {
            for (Enemy& enemy : enemies) updateEnemiesCoord(map, enemy);
            for (const Enemy& enemy : enemies) {
                if (enemy.x == base.x && enemy.y == base.y) {
                    endMessage = "Enemy reached the base! Game Over!";
                    gameOver = true;
                }
            }
        }

        render(map, enemies, enemyKilled);

        if (gameOver && endMessage == "Congratulations! You killed the enemy!") {
            std::cout << "\n" << BLUE << endMessage << RESET << std::endl;
        }
        else if (gameOver && endMessage == "Enemy reached the base! Game Over!") {
            std::cout << "\n" << RED << endMessage << RESET << std::endl;
        }

        else sleep();
    }


    std::cout<<"\nPress enter to exit..."<<std::endl;
    std::cin.ignore();
    std::cin.get();
    return 0;
}


