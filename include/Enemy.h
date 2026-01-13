#pragma once

struct Enemy{
    int x;
    int y;
    int health;
    int strength;
    int pathIndex;
    char symbol;
    bool alive; //1 alive, 0 dead
};