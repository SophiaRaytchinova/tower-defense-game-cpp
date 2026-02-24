#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "../include/world.h"
#include "../include/displayUtils.h"
#include "../include/entities.h"

using std::cout;
using std::endl;

// y, x
std::vector<std::pair<int, int>> path = {
    {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {5,1}, {6,1},
    {7,1}, {8,1}, {8,2}, {8,3}, {7,3}, {6,3}, {5,3}, {4,3}, 
    {4,2}, {3,2}, {2,2}, {1,2}, {1,3}, {1,4}, {2,4}, {3,4}, 
    {3,5}, {4,5}, {5,5}, {6,5}, {7,5}, {8,5}, {9,5}, {9,6}, 
    {9,7}, {8,7}, {7,7}, {6,7}, {5,7}, {4,7}, {3,7}, {2,7}, 
    {2,6}, {1,6}, {0,6}, {0,7}, {0,8}, {0,9}, {1,9}, {2,9}, 
    {3,9}, {4,9}, {5,9}, {6,9}, {7,9}, {8,9}
};

void updateEnemiesCoord(char map[ROWS][COLS], Enemy &enemy) {
    if (enemy.pathIndex + 1 < path.size()) {
        // move enemy fowrard on the path
        map[enemy.x][enemy.y] = emptyGround;
        enemy.pathIndex++;
        enemy.x = path[enemy.pathIndex].first;
        enemy.y = path[enemy.pathIndex].second;
        map[enemy.x][enemy.y] = enemy.symbol;

        return;
    }

    // enemy reached base
    // map[enemy.x][enemy.y] = emptyGround;
}

bool isValidDefenseTowerPlacement(char map[ROWS][COLS], int x, int y) {
    
    if (map[y][x] != pathWall) return false;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS) {
                if (map[ny][nx] == 'D') return false;
            }
        }
    }
    return true;
}

void placeRandomDefenseTowers(char map[ROWS][COLS], std::vector<DefenseTower>& defenseTowers, int count) {

    srand(time(0));
    int placed = 0;
    int maxAttemps = 500;
    int attemps = 0;

    while (placed < count && attemps < maxAttemps) {
        int x = rand() % ROWS;
        int y = rand() % COLS;

        if (isValidDefenseTowerPlacement(map, x, y)) {
            DefenseTower tower;
            tower.x = x;
            tower.y = y;
            tower.range = 1;
            tower.symbol = 'D';

            defenseTowers.push_back(tower);
            map[y][x] = tower.symbol;
            placed++;
        }
        attemps++;
    }
}

void damageEnemy(Enemy& enemy, double damage) {

    if (!enemy.alive) return;

    enemy.health -= damage;
    
    if (enemy.health <= 0) {
        enemy.alive = false;
        enemy.health = 0;
        cout << "Enemy killed!" << endl;
    }
}

void attackEnemies(std::vector<DefenseTower>& defenseTowers, std::vector<Enemy>& enemies) {
    double distance;
    for (Enemy& enemy : enemies) {
        if (!enemy.alive) continue;

        for (auto& defense : defenseTowers) {
            int dx = defense.x - enemy.x;
            int dy = defense.y - enemy.y;

            distance = std::sqrt(dx * dx + dy * dy);

            if (distance <= defense.range) {
                // cout << "tower hit enemy" << endl;
                damageEnemy(enemy, 10);
            }
        }
    }
}

