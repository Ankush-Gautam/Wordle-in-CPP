#ifndef WORDLE_H_INCLUDED
#define WORDLE_H_INCLUDED

#include "Player.h"

class Wordle : public Player
{
private:
    static int guessCount;
    long int dictionarySize = 5756;

    const char alphabets[27] =
    {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'
    };

    char word[6];
    char todaysWord[6];
    bool wordGuessed;
    bool outOfGuess;

public:

    //variables for statistics for the current run
    static int currentWins;
    static int currentPlayed;
    static int currentStreak;
    static bool currentPlayerLose;

    Wordle(): word(""), todaysWord(""), wordGuessed(false), outOfGuess(false)
    {

    }

    //Logic
    void loadWord();                //loads word of the day
    void checkGameStatus();         //checks if out of guess or won
    bool gameOver();                // checkGameStatus to return gameOver
    void askUser();                 //asks the user for words and also checks for win/loss
    bool isValidWord(char*);        // checks if the word is in the dictionary
    void logic();                   //checks letter is correct or wrong postion wise
    bool includesLetter(char);      //checks if the wordle include that letter

    //Wordle Structure
    void HEADER();                  //title wordle by Ag in fancy way
    void gameBoard();               //drawing gameBoard of matrix
    void sideMsg(const char*);      //side logs message
    void displayLetter(char, int);  //to display letters inside of the board
    void displayAlphabets();        //side a-z logs
    void displayLetterStatus(char);     //changes the letter color of the log

    //Menu-items
    void startGame();
    void statistics();
    void howToPlay();
    void about();

    //friends
    friend void Menu();
};

#endif // WORDLE_H_INCLUDED
