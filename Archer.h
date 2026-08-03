#pragma once
#include "Hero.h"
#include "HealAbility.h"
#include "PowerStrike.h"

/*
    Archer
    ------
    Medium health, high precision damage.
*/

class Archer : public Hero
{
public:
    Archer()
        : Hero("Archer", 110, 30)
    {
        abilities[0] = new HealAbility("Quick Recovery", 15);
        abilities[1] = new PowerStrike("Piercing Arrow", 35);
    }

    ~Archer()
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
        return attackPower + 15;
    }
};
