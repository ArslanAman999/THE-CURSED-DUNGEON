#pragma once
#include "Enemy.h"

/*
    Assassin
    --------
    High damage, low health enemy.
*/

class Assassin : public Enemy
{
public:
    Assassin()
        : Enemy("Assassin", 80, 30, 2) {
    }

    int attack() override
    {
        return attackPower;
    }

    /*void specialMove() override
    {
        attackPower += 15;
    }*/
};


