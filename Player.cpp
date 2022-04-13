#include "Player.h"
const char* filename = "data.dll";

void Player::saveStats()
{
    ofstream file(filename, ios::out | ios::binary);
    file << playerName << " " << played << " " << wins << " " << winPercent << " " << Streak << " " << maxStreak;
    file.close();
}

void Player::calcStats()
{
    winPercent = (double(wins) / double(played)) * 100;

    if(Streak >= maxStreak)
    {
        maxStreak = Streak;
    }
}

void Player::readStats()
{
    ifstream file(filename, ios::in | ios::binary);
    file.seekg(0, ios::beg);
    if(!file.is_open())
    {
        getName();
        wins = 0;
        played = 0;
        Streak = 0;
        maxStreak = 0;
        winPercent = 0;
    }
    else
    {
        file >> playerName >> played >> wins >> winPercent >> Streak >> maxStreak;
    }

    file.close();
}

void Player::displayStats()
{
    calcStats();
    if(playerName == "NO TITLE")
    {
        getName();
    }
    cout << "\tPlayer Name      :   " << playerName << endl;
    cout << "\tPlayed           :   " << played << endl;
    cout << "\tWins             :   " << wins << endl;
    cout << "\tWin %            :   " << winPercent << " %" << endl;
    cout << "\tCurrent Streak   :   " << Streak << endl;
    cout << "\tMax Streak       :   " << maxStreak << endl;
}
