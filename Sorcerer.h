#pragma once
#include "Enemy.h"

/*
    Sorcerer
    --------
    Magic-based enemy with moderate stats.
*/

class Sorcerer : public Enemy
{
public:
    Sorcerer()
        : Enemy("Sorcerer", 100, 20, 4) {
    }

    int attack() override
    {
        return attackPower;
    }

    /*void specialMove() override
    {
        attackPower += 20;
    }*/
};
