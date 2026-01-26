#pragma once

#include <vector>
#include <utility>

#include "entities.h"

constexpr int ROWS = 10;
constexpr int COLS = 10;

extern const char emptyGround;
extern const char pathWall;
extern const char enemy;
extern const char base;
extern const char* topAndBottomBorder;

void render(char map[ROWS][COLS]);

extern std::vector<std::pair<int, int>> path;

void updateEnemiesCoord(char map[ROWS][COLS], Enemy& en);
