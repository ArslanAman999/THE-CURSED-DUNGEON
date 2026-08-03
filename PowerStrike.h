#pragma once
#include "Ability.h"
#include "Hero.h"
#include "Enemy.h"

/*
    PowerStrike
    A concrete ability that deals extra damage to Enemy.
*/

class PowerStrike : public Ability
{
protected:
    int strikePower; 
public:
    // constructor 
    PowerStrike(const char* name, int strikePower): Ability(name), strikePower(strikePower) {}

   /*void use(Hero* hero, Enemy* enemy)
    {
        int damage = (hero->getAttackPower() * power) / 100;
        if (enemy) 
        {
            enemy->takeDamage(damage);
        }

    }*/
    void use(Hero* hero, Enemy* enemy) override
    {
        if (enemy)
        {
            enemy->takeDamage(strikePower);
            hero->addDamageDealt(strikePower);
        }
    }


    int getStrikePower() const
    {
        return strikePower;
    }
};