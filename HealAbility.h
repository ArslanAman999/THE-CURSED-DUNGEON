#pragma once
#include "Ability.h"
#include "Hero.h"
/*
    HealAbility

    A concrete ability that restores Hero health.
    Inherits from Ability.
*/

class HealAbility : public Ability
{
protected:
    int healPower;
public:
    // Constructor
    HealAbility(const char* name, int healPower): Ability(name), healPower(healPower) {}
    
    /*void use(Hero* hero, Enemy* enemy)
    {
        int healAmount = (hero->getMaxHealth() * power) / 100;
        hero->increaseHealth(healAmount);
    }*/

    void use(Hero* hero, Enemy* enemy) override
    {
        hero->increaseHealth(healPower);
    }

    // Optional getter for documentation/debugging
    int getHealPower() const
    {
        return healPower;
    }
};
