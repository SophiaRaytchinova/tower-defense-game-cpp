#pragma once
#include <cstddef>
struct Enemy{
    int x;
    int y;
    int health;
    int strength;
    size_t pathIndex;
    char symbol;
    bool alive; //1 alive, 0 dead
};

struct Tower{
    int x;
    int y;
    int health;
    int energy;
    char symbol;
};