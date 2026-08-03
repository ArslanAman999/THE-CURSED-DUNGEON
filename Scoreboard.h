#pragma once
#include "ScoreEntry.h"
#include <fstream>
using namespace std;

/*
    Scoreboard

    Writes round results to a text file.
*/

class Scoreboard
{
private:
    const char* filename;

public:
    // constructor
    Scoreboard(const char* file)
    {
        filename = file;
    }

    // add entry (append)
    /*void addEntry(const ScoreEntry& entry)
    {
        ofstream out(filename, ios::app);

        if (!out)
        {
            return;
        }

        out << "Round " << entry.roundNumber
            << " | Enemy: " << entry.enemyName
            << " | Damage Dealt: " << entry.damageDealt
            << " | Damage Taken: " << entry.damageTaken
            << "\n";

        out.close();
    }*/

    void writeFinalResult(
        const char* playerName,
        int roundsSurvived,
        int damageDealt,
        int damageTaken
    )
    {
        ofstream out(filename, ios::app);

        out << "\n=== FINAL RESULT ===\n";
        out << "Player Name: " << playerName << "\n";
        out << "Rounds Survived: " << roundsSurvived << "\n";
        out << "Total Damage Dealt: " << damageDealt << "\n";
        out << "Total Damage Taken: " << damageTaken << "\n";

        out.close();
    }


};
