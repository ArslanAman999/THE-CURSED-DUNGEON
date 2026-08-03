#pragma once

#include "Hero.h"
#include "Enemy.h"
#include "BattleLogic.h"
#include "ScoreEntry.h"

/*
    Round

    Represents a single battle round between one Hero and one Enemy.
    Controls turn flow and battle progression.
*/

class Round
{
private:
    int roundNumber;
    Hero* hero;
    Enemy* enemy;
    int startDamageDealt;
    int startDamageTaken;


public:
    // Constructor
    Round(int number, Hero* h, Enemy* e)
    {
        roundNumber = number;
        hero = h;
        enemy = e;

        startDamageDealt = hero->getTotalDamageDealt();
        startDamageTaken = hero->getTotalDamageTaken();
    }


    // Starts the battle loop for this round
   /* void startBattle()
    {
        while (BattleLogic::isHeroAlive(hero) &&
            BattleLogic::isEnemyAlive(enemy))
        {
            BattleLogic::heroAttack(hero, enemy);

            if (!BattleLogic::isEnemyAlive(enemy))
            {
                break;
            }

            BattleLogic::enemyAttack(enemy, hero);
        }
    }*/
    // Creates a score entry after the round ends

    ScoreEntry createScoreEntry()
    {
        ScoreEntry entry;

        entry.roundNumber = roundNumber;
        entry.damageDealt =
            hero->getTotalDamageDealt() - startDamageDealt;
        entry.damageTaken =
            hero->getTotalDamageTaken() - startDamageTaken;

        return entry;
    }

};
