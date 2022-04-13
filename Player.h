#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "myfunctions.h"


class Player
{
protected:
    string playerName;
    int wins;
    int played;
    int Streak;
    int maxStreak;
    double winPercent;

public:

    Player(): playerName("NO TITLE"), wins(0), played(0), Streak(0), maxStreak(0), winPercent(0)
    {
    }

    void getName()
    {
        cout << "\tEnter Player Name: ";
        cin >> playerName;
    }

    void calcStats();
    void readStats();
    void saveStats();
    void displayStats();

};

#endif // PLAYER_H_INCLUDED
