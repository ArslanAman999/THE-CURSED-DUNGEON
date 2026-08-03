#pragma once
#include "Hero.h"
#include "HealAbility.h"
#include "PowerStrike.h"

/*
    Healer
    ------
    Low attack, high healing power.
*/

class Healer : public Hero
{
public:
    Healer()
        : Hero("Healer", 120, 15)
    {
        abilities[0] = new HealAbility("Divine Heal", 40);
        abilities[1] = new PowerStrike("Holy Strike", 15);
    }

    ~Healer()
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
        increaseHealth(25);
        return 0;
    }
};
