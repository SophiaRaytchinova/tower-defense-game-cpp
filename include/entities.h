#pragma once

#include <cstddef>

struct Enemy {
    int x;
    int y;
    double health;
    double maxHealth;
    int strength;
    size_t pathIndex;
    char symbol;
    bool alive;
};

struct Tower {
    int x;
    int y;
    char symbol;
};

struct DefenseTower {
    int x;
    int y;
    int range;
    char symbol;
};
