#include <iostream>
#include "Hero.h"
#include "Knight.h"
#include "Healer.h"
#include "Archer.h"
#include "Shadow.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Assassin.h"

#include "Giant.h"
#include "Sorcerer.h"
#include "Round.h"
#include "BattleLogic.h"
#include "Scoreboard.h"

using namespace std;

int main()
{
    int roundsSurvived = 0;
    char playerName[50];
    cout << "Enter Player Name: ";
    //cin.ignore();
    cin.getline(playerName, 50);


    cout << "=== Hero Selection ===\n";
    cout << "1. Knight\n2. Healer\n3. Archer\n4. Shadow\n";
    int choice;
    Hero* hero = nullptr;

    while (true)
    {
        cout << "Choose your hero (1-4): ";
        cin >> choice;
        if (choice == 1) 
        { hero = new Knight(); break; }
        if (choice == 2) 
        { hero = new Healer(); break; }
        if (choice == 3)
        { hero = new Archer(); break; }
        if (choice == 4)
        { hero = new Shadow(); break; }

        cout << "Invalid choice. Try again.\n";
    }

    cout << "\nYou chose: " << hero->getName() << "\n";

    // Create enemies
    Enemy* enemies[4];
    enemies[0] = new Goblin();
    enemies[1] = new Assassin();
    enemies[2] = new Giant();
    enemies[3] = new Sorcerer();

    Scoreboard scoreboard("game_results.txt");

    // Loop through all enemies
    for (int i = 0; i < 4; i++)
    {
        cout << "\n=== Round " << i + 1 << ": " << enemies[i]->getName() << " ===\n";

        Round round(i + 1, hero, enemies[i]);

        int iteration = 0;
        while (BattleLogic::isHeroAlive(hero) && BattleLogic::isEnemyAlive(enemies[i]))
        {
            iteration++;
            cout << "\nIteration " << iteration << "\n";
            cout << "Hero Health: " << hero->getHealth() << " | Enemy Health: " << enemies[i]->getHealth() << "\n";

            int action = -1;
            if (iteration == 3)
            {
                cout << "Choose Action:\n0. Use Heal Ability\n1. Use Power Attack\n2. Special Move\n";
            }
            else
            {
                cout << "Choose Action:\n0. Use Heal Ability\n1. Use Power Attack\n";
            }

            cin >> action;

            if (action == 0 || action == 1)
            {
                BattleLogic::heroUseAbility(hero, enemies[i], action);
            }
            else if (action == 2 && iteration == 3)
            {
                int damage = hero->specialMove();

                if (damage > 0)
                {
                    enemies[i]->takeDamage(damage);
                    hero->addDamageDealt(damage);
                    cout << hero->getName() << " uses SPECIAL MOVE and deals " << damage << " damage.\n";
                }
                else
                {
                    cout << hero->getName() << " uses SPECIAL MOVE.\n";
                }
            }
            else
            {
                cout << "Invalid action. Skipping turn.\n";
            }

            if (!BattleLogic::isEnemyAlive(enemies[i]))
            {
                cout << enemies[i]->getName() << " defeated!\n";
                break;
            }

            // Enemy attacks
            BattleLogic::enemyAttack(enemies[i], hero);

            if (!BattleLogic::isHeroAlive(hero))
            {
                cout << hero->getName() << " has been defeated!\n";
                break;
            }
        }
        if (BattleLogic::isHeroAlive(hero))
        {
            roundsSurvived++;
        }
        else
        {
            break;
        }


        // Create and save score entry
        ScoreEntry entry = round.createScoreEntry();
       // scoreboard.addEntry(entry);
    }

    cout << "\n=== Game Over ===\n";
    cout << "Final Hero Health: " << hero->getHealth() << "\n";

    
    for (int i = 0; i < 4; i++)
    {
        delete enemies[i];
    }

    cout << "Results saved to game_results.txt\n";
    cout << "\n=== FINAL SCORE ===\n";
    cout << "Player: " << playerName << endl;
    cout << "Rounds Survived: " << roundsSurvived << endl;
    cout << "Total Damage Dealt: " << hero->getTotalDamageDealt() << endl;
    cout << "Total Damage Taken: " << hero->getTotalDamageTaken() << endl;

    scoreboard.writeFinalResult(
        playerName,
        roundsSurvived,
        hero->getTotalDamageDealt(),
        hero->getTotalDamageTaken()
    );
// Clean up
    delete hero;

    return 0;
}
