#pragma once
#include "StringUtility.h"

class Hero;
class Enemy;

/*
    Ability (Abstract Base Class)      Represents a special skill that a Hero can use during battle.
                                       Each ability has a name and a power value.
                                       This class enforces abstraction through a pure virtual function.
*/

class Ability
{
protected:
    char* abilityName;

public:
    // Constructor
    Ability(const char* name)
    {
        abilityName = StringUtility::copy(name);
    }
    // destructor
    virtual ~Ability()
    {
        StringUtility::destroy(abilityName);
    }

    // Getter
    char* getName() const
    {
        return abilityName;
    }

    virtual void use(Hero* hero, Enemy* enemy) = 0;
};


