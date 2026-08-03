#include "Entity.h"
#include "Ability.h"
#pragma once
/*
    Hero (Abstract Class):          Represents the character controlled by user.
                                    A Hero is chosen once and remains active until the end of program =.
*/
class Hero : public Entity
{

protected:
    int totalDamageDealt;
    int totalDamageTaken;
    bool dodged;
    int maxHealth;
    Ability* abilities[2];

public:
    // constructor
    Hero(const char* name, int maxHealth, int attackPower): Entity(name, maxHealth, attackPower)
    {
        this->maxHealth = maxHealth;
        abilities[0] = nullptr;
        abilities[1] = nullptr;
        dodged = false;
        totalDamageDealt = 0;
        totalDamageTaken = 0;

    }

    // destructor
    virtual ~Hero() {}

    // getter
    int getMaxHealth() const
    {
        return maxHealth;
    }

    void setDodged(bool value)
    {
        dodged = value;
    }

    bool hasDodged() const
    {
        return dodged;
    }

    void addDamageDealt(int dmg)
    {
        totalDamageDealt += dmg;
    }

    void addDamageTaken(int dmg)
    {
        totalDamageTaken += dmg;
    }

    int getTotalDamageDealt() const
    {
        return totalDamageDealt;
    }

    int getTotalDamageTaken() const
    {
        return totalDamageTaken;
    }


    Ability* getAbility(int index)
    {
        if (index < 0 || index > 1)
        {
            return nullptr;
        }

        return abilities[index];
    }
    int getAttackPower() const
    {
        return attackPower;
    }

    /*
        Increases Hero health without exceeding maxHealth.
    */
    void increaseHealth(int amount)
    {
        health += amount;
        if (health > maxHealth)
        {
            health = maxHealth;
        }
    }

    virtual int specialMove() = 0;
};

