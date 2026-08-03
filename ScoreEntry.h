#pragma once
#include "StringUtility.h"

/*
    ScoreEntry

    Stores the result of a single battle round.
    This is a simple data container class.
*/

class ScoreEntry
{
public:
    int roundNumber;
    //char* enemyName;
    int damageDealt;
    int damageTaken;

    // constructor
    ScoreEntry()
    {
        roundNumber = 0;
        damageDealt = 0;
        damageTaken = 0;
    }

    // deep copy constructor
    //ScoreEntry(int round, const char* name, int dealt, int taken)
    //{
    //    roundNumber = round;
    //    //enemyName = StringUtility::copy(name);
    //    damageDealt = dealt;
    //    damageTaken = taken;
    //}

    // destructor
   /* ~ScoreEntry()
    {
        StringUtility::destroy(enemyName);
    }*/
};
