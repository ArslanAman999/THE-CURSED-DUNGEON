#include "StringUtility.h"
#pragma once
/*
		Entity(Abstract Base Class)		Represents any character in the game that has a name,
										health and attack power.This class serves as a base for Hero and Enemy.
*/
class Entity
{
protected:
    char* name;
    int health;
    int attackPower;

public:
    // constructor
    Entity(const char* name, int health, int attackPower)
    {
        this->name = StringUtility::copy(name);
        this->health = health;
        this->attackPower = attackPower;
    }

    // destructor
    virtual ~Entity()
    {
        StringUtility::destroy(name);
    }

    // Getter 
    int getHealth() const
    {
        return health;
    }
    char* getName() const
    {
        return name; 
    }

    void takeDamage(int amount)
    {
        health -= amount;
        if (health < 0)
        {
            health = 0;
        }
    }

    virtual int attack() = 0;
};

