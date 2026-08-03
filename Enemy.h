#pragma once
#include "Entity.h"

/*
    Enemy (Abstract Base Class)         Represents any enemy encountered during a round.
*/

class Enemy : public Entity
{
protected:
    int maxHealth;
    int typeID;

public:
    // constructor
    Enemy(const char* name, int health, int attackPower, int typeID): Entity(name, health, attackPower)
    {
        this->typeID = typeID;
        maxHealth = health;
    }
    // destroctor
    virtual ~Enemy() {}

    // getter
    int getTypeID() const
    {
        return typeID;
    }
    // getter
    int getMaxHealth() const
    {
        return maxHealth;
    }

   
};
