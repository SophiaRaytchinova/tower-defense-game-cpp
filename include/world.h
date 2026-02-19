#pragma once

constexpr int ROWS = 10;
constexpr int COLS = 10;

#include <vector>
#include <utility>

#include "entities.h"

extern const char emptyGround;
extern const char pathWall;
extern const char enemy;
extern const char base;
extern const char* topAndBottomBorder;

extern std::vector<std::pair<int, int>> path;

void render(char map[ROWS][COLS]);
void updateEnemiesCoord(char map[ROWS][COLS], Enemy& en);
void placeRandomDefenseTowers(char map[ROWS][COLS], std::vector<DefenseTower>& defenseTowers, int count);
bool isValidDefenseTowerPlacement(char map[ROWS][COLS], int x, int y);
void drawHPBar(const Enemy& enemy);
void damageEnemy(Enemy& enemy, double damage);
void attackEnemies(std::vector<DefenseTower>& defenseTowers, std::vector<Enemy>& enemies);
void widenPath(char map[ROWS][COLS]);

