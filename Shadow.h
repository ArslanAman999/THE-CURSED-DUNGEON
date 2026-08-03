#pragma once
#include "Hero.h"
#include "HealAbility.h"
#include "PowerStrike.h"

/*
    Shadow
    ------
    High burst damage, low health.
*/

class Shadow : public Hero
{
public:
    Shadow()
        : Hero("Shadow", 90, 35)
    {
        abilities[0] = new HealAbility("Life Drain", 10);
        abilities[1] = new PowerStrike("Backstab", 45);
    }

    ~Shadow()
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
        return attackPower * 2;
    }
};
