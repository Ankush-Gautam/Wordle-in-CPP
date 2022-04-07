#include "Colors.h"
#include "dictionary.cpp"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <fstream>
using namespace std;

/* global variables */
static int guessCount = 0;
char word[6];
char todaysWord[6];
bool wordGuessed = false;
bool outOfGuess = false;
long int dictionarySize = 5757;

long long int randomGenerator()
{
    srand(time(0));
    long long int num = rand() % dictionarySize + 1;
    return num;
}
void loadWord()
{
    strcpy(todaysWord, dictionary[randomGenerator()]);
}

void pause()
{
    lightpurple();
    cout<<"\n\n\tPress Any to Key Continue...";
    getch();
    gray();
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void upperline(int length)
{
    //upper line
    for(int i = 0; i < length; i++)
    {
        cout << char(220);
    }
}

void verticalline(int x, int y, int length)
{
    for(int i = y; i < length; i++)
    {
        gotoxy(x, i);
        cout << char(219);
    }
}

void bottomline(int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << char(223); //this char touches upper line which makes block appears as joined
    }
}


void gameBoard()
{

    //for drawing row
    for(int i = 7; i < 24; i += 3) //i is vertical starting point
    {
        gotoxy(8, i);
        upperline(31);
    }

    //drawing columns
    for(int x = 8; x < 42; x += 6)
    {
        verticalline(x, 8, 23); //vacant spots for alphabets: (40,10);
    }
}

void displayWord(char* word)
{
    int x = 41; //starting coord of x
    int y; //coord of y

    //changing the position of row
    switch(guessCount)
    {
    case 0:
        y = 9;
        break;

    case 1:
        y = 12;
        break;

    case 2:
        y = 15;
        break;

    case 3:
        y = 18;
        break;

    case 4:
        y = 21;
        break;
    }

    for(int i = 0; i < 5; i++)
    {
        gotoxy(x, y);
        cout << char(toupper(word[i]));
        x += 6;
    }
}

void displayLetter(char ch, int i)
{

    /*       i = 0     1      2       3       4

    gc = 0       0     1      2       3       4
         1       5     6      7       8       9
         2      10    11     12      13      14
         3      15    16     17      18      19
         4      20    21     22      23      24

    */


    int x; //starting coord of x
    int y; //coord of y
    int index = (guessCount * 5) + i;

    //changing the position of column
    switch(index)
    {
    case 0:
    case 5:
    case 10:
    case 15:
    case 20:
        x = 11;
        break;

    case 1:
    case 6:
    case 11:
    case 16:
    case 21:
        x = 17;
        break;

    case 2:
    case 7:
    case 12:
    case 17:
    case 22:
        x = 23;
        break;

    case 3:
    case 8:
    case 13:
    case 18:
    case 23:
        x = 29;
        break;

    case 4:
    case 9:
    case 14:
    case 19:
    case 24:
        x = 35;
        break;
    }

    //changing position for row
    if(index <= 4)
        y = 9;
    else if(index <= 9)
        y = 12;
    else if(index <= 14)
        y = 15;
    else if(index <= 19)
        y = 18;
    else
        y = 21;


    gotoxy(x, y);
    cout << char(toupper(ch));
}

void HEADER()
{
    black();
    cout << GREEN;
    cout << "\n\n\t W ";
    cout << WHITE;
    cout << " ";
    cout << GREEN;
    cout << " O ";
    cout << WHITE;
    cout << " ";
    cout << GREEN;
    cout << " R ";
    cout << WHITE;
    cout << " ";
    cout << GREEN;
    cout << " D ";
    cout << WHITE;
    cout << " ";
    cout << GREEN;
    cout << " L ";
    cout << WHITE;
    cout << " ";
    cout << GREEN;
    cout << " E ";
    cout << WHITE;
    cout << " ";
    cout << "\n\n\t";

    cout << YELLOW;
    cout << " B ";
    cout << WHITE;
    cout << " ";
    cout << GREEN;
    cout << " Y ";
    cout << WHITE;
    cout << "  ";
    white();
    cout << RED;
    cout << " A ";
    cout << WHITE;
    cout << " ";
    cout << SKY;
    cout << " G ";
    cout << WHITE;
    cout << "\n\n";
    gray();
}

void sideMsg(string msg)
{
    gotoxy(69, 10);
    cout << msg;
}

bool includesLetter(char ch)
{
    //to check if the guessWord contains letters of today's word

    for(int j = 0; j < 5; j++)
    {
        if(ch == todaysWord[j])
            return true;
    }

    return false;
}

void checkWord()
{
    int dSize = 5;

    for(int i = 0; i < 5; i++)
    {

        for(int j = 0; j < 5; j++)
        {

            if(includesLetter(word[i]))
            {
                if(todaysWord[i] == word[i])
                {
                    lightgreen();
                    displayLetter(word[i], i); //if letter and position is correct

                    gray();
                    break;
                }
                else
                {
                    yellow();
                    displayLetter(word[i], i); //if letter is correct but position is wrong
                    gray();
                    break;
                }
            }
            else
            {
                lightred();
                displayLetter(word[i], i);  //if letter is wrong
                gray();
                break;
            }
        }
    }
}

void checkGameStatus()
{
    if(strcmp(word, todaysWord) == 0)
    {
        lightgreen();
        sideMsg("Marvelous. You won!");
        gray();
        wordGuessed = true;
    }
    else if(guessCount == 4)
    {
        lightred();
        sideMsg("The word was ");
        cout << _strupr(todaysWord) << ".";
        gray();
        outOfGuess = true;
    }
}
bool isValidWord(char* word)
{
    for(int i = 0; i < dictionarySize; i++)
    {
        if(strcmp(word, dictionary[i]) == 0)
            return true;
    }

    return false;
}
void askUser()
{
    bool valid = false;
    do
    {
        gotoxy(8, 25);
        black();
        cout << "Guess the word:                        ";
        gray();
        gotoxy(24, 25);
        cin >> word;
        if(strlen(word) != 5 )
        {
            lightred();
            sideMsg("Word must be 5 letters!      ");
            gray();

        }
        else if(!isValidWord(word))
        {
            lightred();
            sideMsg("Word not found in Dictionary!");
            gray();
        }
        else
        {
            valid = true;
            sideMsg("                              "); //to remove the sidemsg if word is valid
        }
    }
    while(!valid);

    checkGameStatus();
    checkWord();
    guessCount++;

}


bool gameOver()
{
    if(outOfGuess)
        return true;
    else if(wordGuessed)
        return true;
    else
        return false;
}
void startGame()
{
    system("cls");
    HEADER();
    guessCount = 0;
    outOfGuess = false;
    wordGuessed = false;

    //side logs display
    gotoxy(69, 8);
    lightblue();
    cout << ">> Logs <<";
    gray();

    //loading todays word
    loadWord();

    gameBoard();
    while(!gameOver())
    {
        askUser();
    }

    gotoxy(69, 11);
    purple();
    cout<<"Press Any Key to Continue...";
    getch();
    gray();
}
void howToPlay()
{
    system("cls");
    HEADER();

    black();
    cout << "\n\tHOW TO PLAY";
    gray();
    cout << "\n\tGuess the WORDLE in 5 tries.\n";
    cout << "\tEach guess must be a valid five-letter word."
         << " Write the word and Hit enter to submit";
    cout << "\n\tAfter each guess, the color of the letter"
         << " will change to show\n\thow close your guess was to the word.";

    black();
    cout << "\n\n\n\tEXAMPLES\n\n";
    gray();

    green();
    cout << "\tW ";
    gray();
    cout << " E A R Y";
    cout << "\n\tThe letter W is in the word and in the correct spot.\n\n";

    cout << "\tP ";
    yellow();
    cout << "I";
    gray();
    cout << " L L S";
    cout << "\n\tThe letter I is in the word but in the wrong spot.\n\n";

    cout << "\tV A G ";
    red();
    cout << "U";
    gray();
    cout << " E";
    cout << "\n\tThe letter U is not in the word in any spot.";

    pause();
}

void about()
{
    system("cls");
    HEADER();

    black();
    cout<<"\n\tABOUT THE ORIGNINAL GAME\n";
    gray();
    cout<<"\tWordle is a web-based word game created and developed by Welsh software engineer Josh Wardle"
        <<",\n\tand owned and published by The New York Times Company since 2022."
        <<" The game gained a large \n\tamount of popularity in December 2021 after Wardle added the ability "
        <<"for players to copy \n\ttheir daily results as emoji squares, which were widely shared on Twitter.\n\n";

        black();
        cout<<"\n\tABOUT THIS GAME\n";
        gray();
        cout<<"\tThis Game is Developed by Ankush Gautam (Ag). I love this game and was my go to partner\n\tduring the lockdown period,"
        <<"Me and my friend Keeran used to play this daily.\n\n\tI'm currently studying Bachelor in Computer Application and "
        <<" we are learning C++ in the \n\tcourse so I thought can I make the game which I play daily as it has simple logic \n\tand interface "
        <<"comparing to other games. So I started to create thisgame and well this \n\tis the progress I have made till now.";


        pause();
}
void Menu()
{
    int choice;
    do
    {
        system("cls");
        lightblue();
        HEADER();

        black();
        cout<<"\n\tWELCOME TO MAIN MENU\n\n";
        gray();
        cout << "\tPress 1 to Start the Game.\n";
        cout << "\tPress 2 for Leaderboard\n";
        cout << "\tPress 3 to Learn How to Play\n";
        cout << "\tPress 4 for About the Game.\n";
        cout << "\tPress 0 to Exit\n\n";

        cout << "\tEnter your choice:\n\t>> ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            startGame();
            break;

        case 2:
            system("cls");
            HEADER();
            black();
            cout << "\n\tLEADERBOARD";
            gray();

            cout<<"\n\tAg =  10streaks";

            pause();
            break;

        case 3:
            howToPlay();
            break;

        case 4:
            about();
            break;
        }
    }
    while(choice != 0);
}


int main()
{
    system("color f8");


    Menu();

    gotoxy(8, 27); //only while coding
    return 0;
}
