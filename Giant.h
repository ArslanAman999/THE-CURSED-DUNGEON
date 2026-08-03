#pragma once
#include "Enemy.h"

/*
    Giant
    -----
    Very high health, slow heavy attacks.
*/

class Giant : public Enemy
{
public:
    Giant()
        : Enemy("Giant", 180, 25, 3) {
    }

    int attack() override
    {
        return attackPower;
    }

    /*void specialMove() override
    {
        attackPower += 10;
        health += 10;
    }*/
};
