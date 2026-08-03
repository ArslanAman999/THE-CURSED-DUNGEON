#pragma once
#include <iostream>
using namespace std;
#include "Hero.h"
#include "Enemy.h"

/*
    BattleLogic
    -----------
    Controls the flow of combat between a Hero and an Enemy.
    Handles turns, attacks, abilities, and health checks.
*/

class BattleLogic
{
public:

    // Hero performs normal attack
    static void heroAttack(Hero* hero, Enemy* enemy)
    {
        int damage = hero->attack();
        enemy->takeDamage(damage);
        hero->addDamageDealt(damage);
        cout << hero->getName() << " attacks and deals " << damage << " damage.\n";
    }

    // Enemy performs normal attack
    static void enemyAttack(Enemy* enemy, Hero* hero)
    {
        if (hero->hasDodged())
        {
            cout << hero->getName() << " dodged the enemy attack!\n";
            hero->setDodged(false);
            return;
        }

        int damage = enemy->attack();
        hero->takeDamage(damage);
        cout << enemy->getName() << " attacks and deals " << damage << " damage.\n";
        hero->addDamageTaken(damage);



    }


    // Hero uses an ability
    static void heroUseAbility(Hero* hero, Enemy* enemy, int abilityIndex)
    {
        Ability* ability = hero->getAbility(abilityIndex);

        if (!ability)
        {
            return;
        }

        cout << hero->getName() << " uses " << ability->getName() << ".\n";
        ability->use(hero, enemy);

        if (abilityIndex == 0)
        {
            hero->setDodged(true);
        }
    }



    // Check if Hero is alive
    static bool isHeroAlive(Hero* hero)
    {
        return hero->getHealth() > 0;
    }

    // Check if Enemy is alive
    static bool isEnemyAlive(Enemy* enemy)
    {
        return enemy->getHealth() > 0;
    }
};
