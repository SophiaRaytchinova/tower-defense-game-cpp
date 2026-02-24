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

// fix name to be base entity
struct BaseEntity {
    int x;
    int y;
    char symbol;
};

// make symbol to be T not D
struct DefenseTower {
    int x;
    int y;
    int range;
    char symbol;
};
