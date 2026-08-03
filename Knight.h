#pragma once
#include "Hero.h"
#include "HealAbility.h"
#include "PowerStrike.h"

/*
    Knight
    ------
    Balanced hero with high health and strong melee attack.
*/

class Knight : public Hero
{
public:
    Knight()
        : Hero("Knight", 150, 25)
    {
        abilities[0] = new HealAbility("Shield Heal", 20);
        abilities[1] = new PowerStrike("Heavy Slash", 30);
    }

    ~Knight()
    {
        delete abilities[0];
        delete abilities[1];
    }

    int attack() override
    {
        return attackPower;
    }

    int specialMove() override
    {
        return attackPower + 10;
    }
};
