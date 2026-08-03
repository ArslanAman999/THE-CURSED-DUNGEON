#pragma once
#include "Enemy.h"

/*
    Goblin
    ------
    Weak enemy with fast attacks.
*/

class Goblin : public Enemy
{
public:
    Goblin()
        : Enemy("Goblin", 60, 15, 1) {
    }

    int attack() override
    {
        return attackPower;
    }

    /*void specialMove() override
    {
        attackPower += 5;
    }*/
};
