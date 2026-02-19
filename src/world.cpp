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

void updateEnemiesCoord(char map[ROWS][COLS], Enemy &en) {
    if (!en.alive) return;
    if (en.pathIndex + 1 < path.size()) {
        map[en.y][en.x] = emptyGround;
        en.pathIndex++;
        en.y = path[en.pathIndex].first;
        en.x = path[en.pathIndex].second;
        map[en.y][en.x] = enemy;
        //render(map);
        //timing();
    }
    else {
        en.alive = false; // it was 0 before, but it should be false to be consistent with the Enemy struct
        map[en.y][en.x] = emptyGround;
        cout <<"Enemy reached the base!" << endl;
        timing();
    } 
}

bool isValidDefenseTowerPlacement(char map[ROWS][COLS], int x, int y) {
    
    if (map[y][x] != pathWall) return false;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS) {
                if (map[ny][nx] == 'D') return false;
                //if (map[ny][nx] == pathWall) return false;
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
        int x = rand() % COLS;
        int y = rand() % ROWS;

        if (isValidDefenseTowerPlacement(map, x, y)) {
            DefenseTower t;
            t.x = x;
            t.y = y;
            t.range = 1;
            t.symbol = 'D';

            defenseTowers.push_back(t);
            map[y][x] = t.symbol;
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

        for (auto& d : defenseTowers) {
            int dx = d.x - enemy.x;
            int dy = d.y - enemy.y;

            distance = std::sqrt(dx * dx + dy * dy);

            if (distance <= d.range) {
                cout << "tower hit enemy" << endl;
                damageEnemy(enemy, 10);
            }
        }
    }
}

void widenPath(char map[ROWS][COLS]) {

    for (size_t i = 0; i < path.size(); i++) {

        int y = path[i].first;
        int x = path[i].second;

        map[y][x] = emptyGround;

        if (i > 0) {

            int prevY = path[i - 1].first;
            int prevX = path[i - 1].second;

            // ако движението е вертикално
            if (prevX == x) {
                for (int dx = -1; dx <= 1; dx++) {
                    int nx = x + dx;
                    if (nx >= 0 && nx < COLS)
                        map[y][nx] = emptyGround;
                }
            }

            // ако движението е хоризонтално
            if (prevY == y) {
                for (int dy = -1; dy <= 1; dy++) {
                    int ny = y + dy;
                    if (ny >= 0 && ny < ROWS)
                        map[ny][x] = emptyGround;
                }
            }
        }
    }
}

void drawHPBar(const Enemy& enemy) {
    std::cout << "Enemy HP: " << enemy.health << "%" << std::endl;
}
