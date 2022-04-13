#include "Wordle.h"

//static variables
int Wordle::guessCount = 0;
int Wordle::currentWins = 0;
int Wordle::currentPlayed = 0;
int Wordle::currentStreak = 0;
bool Wordle::currentPlayerLose = false;

/* -------------------------------------------- WORDLE METHODS -------------------------------------------------- */
void Wordle::gameBoard()
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

void Wordle::sideMsg(const char* msg)
{
    gotoxy(69, 13);
    std::cout << msg;
}

void Wordle::loadWord()
{
    int randomNum = randomGenerator(dictionarySize);
    strcpy(todaysWord, dictionary[randomNum]);
}

bool Wordle::gameOver()
{
    if(outOfGuess)
        return true;
    else if(wordGuessed)
        return true;
    else
        return false;
}

void Wordle::askUser()
{
    bool valid = false;
    do
    {
        gotoxy(8, 25);
        cout << BLACK;
        cout << "Guess the word:                                                                      \n                                               ";
        cout << GREY;
        gotoxy(24, 25);
        cin >> word;
        //making the word lowercase for error prone
        strcpy(word, _strlwr(word));

        if(strlen(word) != 5 )
        {
            cout << RED;
            sideMsg("Word must be 5 letters!      ");
            cout << GREY;

        }
        else if(!isValidWord(word))
        {
            cout << RED;
            sideMsg("Word not found in Dictionary!");
            cout << GREY;
        }
        else
        {
            valid = true;
            sideMsg("                              "); //to remove the sidemsg if word is valid
        }
    }
    while(!valid);

    checkGameStatus();
    logic();
    ++guessCount;

}
void Wordle::displayLetter(char ch, int i)
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

bool Wordle::isValidWord(char* word)
{
    for(int i = 0; i < dictionarySize; i++)
    {
        if(strcmp(word, dictionary[i]) == 0)
            return true;
    }

    return false;
}

void Wordle::checkGameStatus()
{
    if(strcmp(word, todaysWord) == 0)
    {
        cout << GREEN;
        sideMsg("Marvelous. You won!");
        cout << GREY;
        wordGuessed = true;
        ++currentWins;
        ++currentStreak;
    }
    else if(guessCount >= 4)
    {
        cout << RED;
        sideMsg("The word was ");
        cout << GREEN;
        cout << todaysWord << ".";
        cout << GREY;
        outOfGuess = true;
        currentPlayerLose = true;
        currentStreak = 0;
    }
}

/* ---------------------------------------------------- MAIN LOGIC -------------------------------------------------------------- */
void Wordle::logic()
{

    for(int i = 0; i < 5; i++)
    {

        for(int j = 0; j < 5; j++)
        {

            if(includesLetter(word[i]))
            {
                if(todaysWord[i] == word[i])
                {
                    cout << GREEN;
                    displayLetter(word[i], i); //if letter and position is correct
                    displayLetterStatus(word[i]);
                    cout << GREY;
                    break;
                }
                else
                {
                    cout << YELLOW;
                    displayLetter(word[i], i); //if letter is correct but position is wrong
                    displayLetterStatus(word[i]);
                    cout << GREY;
                    break;
                }
            }
            else
            {
                cout << RED;
                displayLetter(word[i], i);  //if letter is wrong
                cout << WHITE;
                displayLetterStatus(word[i]);
                cout << GREY;
                break;
            }
        }
    }//end of i loop

}//end of logic()

bool Wordle::includesLetter(char ch)
{
    //to check if the guessWord contains letters of today's word
    for(int j = 0; j < 5; j++)
    {
        if(ch == todaysWord[j])
            return true;
    }
    return false;
}

/* -------------------------------------------- WORDLE-STRUCTURES ------------------------------------------------- */
void Wordle::HEADER()
{
    system("cls");

    cout << BLACK;
    const char title[7] = "WORDLE";

    //W O R D L E title
    cout << "\n\n\t";
    for(int i = 0; i < 6; i++)
    {
        cout << GREENBG;
        cout << " " << title[i] << " ";
        cout << WHITEBG;
        cout << " ";
    }
    cout << "\n\n\t";

    //B Y
    cout << YELLOWBG;
    cout << " B ";
    cout << WHITEBG;
    cout << " ";
    cout << GREENBG;
    cout << " Y ";
    cout << WHITEBG;
    cout << "  ";

    //A G
    cout << WHITE;
    cout << REDBG;
    cout << " A ";
    cout << WHITEBG;
    cout << " ";
    cout << SKYBG;
    cout << " G ";
    cout << WHITEBG;
    cout << "\n\n";
    cout << GREY;
}

void Wordle::displayAlphabets()
{
    gotoxy(69, 10);
    //displaying alphabets
    for(int i = 0; i < 26; i++)
    {
        cout << alphabets[i] << " ";
        if(i % 12 == 0 && i != 0 && i < 20)
            gotoxy(69, 11);
    }
}

void Wordle::displayLetterStatus(char ch)
{
    switch(ch)
    {
        case 'a':
            gotoxy(69, 10);
            cout << 'a';
            break;
        case 'b':
            gotoxy(71, 10);
            cout << 'b';
            break;
        case 'c':
            gotoxy(73, 10);
            cout << 'c';
            break;
        case 'd':
            gotoxy(75, 10);
            cout << 'd';
            break;
        case 'e':
            gotoxy(77, 10);
            cout << 'e';
            break;
        case 'f':
            gotoxy(79, 10);
            cout << 'f';
            break;
        case 'g':
            gotoxy(81, 10);
            cout << 'g';
            break;
        case 'h':
            gotoxy(83, 10);
            cout << 'h';
            break;
        case 'i':
            gotoxy(85, 10);
            cout << 'i';
            break;
        case 'j':
            gotoxy(87, 10);
            cout << 'j';
            break;
        case 'k':
            gotoxy(89, 10);
            cout << 'k';
            break;
        case 'l':
            gotoxy(91, 10);
            cout << 'l';
            break;
        case 'm':
            gotoxy(93, 10);
            cout << 'm';
            break;
        case 'n':
            gotoxy(69, 11);
            cout << 'n';
            break;
        case 'o':
            gotoxy(71, 11);
            cout << 'o';
            break;
        case 'p':
            gotoxy(73, 11);
            cout << 'p';
            break;
        case 'q':
            gotoxy(75, 11);
            cout << 'q';
            break;

        case 'r':
            gotoxy(77, 11);
            cout << 'r';
            break;
        case 's':
            gotoxy(79, 11);
            cout << 's';
            break;
        case 't':
            gotoxy(81, 11);
            cout << 't';
            break;
        case 'u':
            gotoxy(83, 11);
            cout << 'u';
            break;
        case 'v':
            gotoxy(85, 11);
            cout << 'v';
            break;
        case 'w':
            gotoxy(87, 11);
            cout << 'w';
            break;
        case 'x':
            gotoxy(89, 11);
            cout << 'x';
            break;
        case 'y':
            gotoxy(91, 11);
            cout << 'y';
            break;
        case 'z':
            gotoxy(93, 11);
            cout << 'z';
            break;
    }
}

/* -------------------------------------------- MENU- ITEMS ------------------------------------------------- */
void Wordle::startGame()
{
    HEADER();

    //initializing & setting up the new game
    guessCount = 0;
    outOfGuess = false;
    wordGuessed = false;
    ++currentPlayed;

    //side logs display
    gotoxy(69, 8);
    cout << BLUE;
    cout << ">> Logs";
    cout << GREY;

    displayAlphabets();

    //loading todays word
    gameBoard();
    loadWord();

    while(!gameOver())
    {
        askUser();
    }

    //saving the data in the file
    wins += currentWins;
    played += currentPlayed;
    if(currentPlayerLose)
    {
        Streak = 0;
    }
    else
    {
        Streak += currentStreak;
    }
    saveStats();

    //resetting the current wins to total stats don't get compound
    currentWins = 0;
    currentPlayed = 0;
    currentStreak = 0;
    currentPlayerLose = false;

    //not using pause() because that has \n\n\t
    gotoxy(69, 14);
    cout << MAGENTA;
    cout << "Press Any to Key Continue...";
    cout << GREY;
    getch();
}

void Wordle::statistics()
{
    HEADER();
    cout << BLACK;
    cout << "\n\tSTATISTICS\n\n";
    cout << GREY;

    readStats();
    displayStats();

    pause();
}

void Wordle::howToPlay()
{
    HEADER();

    cout << BLACK;
    cout << "\n\tHOW TO PLAY";
    cout << GREY;

    cout << "\n\tGuess the WORDLE in 5 tries.\n";
    cout << "\tEach guess must be a valid five-letter word."
         << " Write the word and Hit enter to submit";
    cout << "\n\tAfter each guess, the color of the letter"
         << " will change to show\n\thow close your guess was to the word.";

    cout << BLACK;
    cout << "\n\n\n\tEXAMPLES\n\n";
    cout << GREY;

    cout << GREEN;
    cout << "\tW ";
    cout << GREY;
    cout << " E A R Y";
    cout << "\n\tThe letter W is in the word and in the correct spot.\n\n";

    cout << "\tP ";
    cout << YELLOW;
    cout << "I";
    cout << GREY;
    cout << " L L S";
    cout << "\n\tThe letter I is in the word but in the wrong spot.\n\n";

    cout << "\tV A G ";
    cout << RED;
    cout << "U";
    cout << GREY;
    cout << " E";
    cout << "\n\tThe letter U is not in the word in any spot.";

    pause();
}

void Wordle::about()
{
    HEADER();

    cout << BLACK;
    cout << "\n\tABOUT THE ORIGNINAL GAME\n";
    cout << GREY;
    cout << "\tWordle is a web-based word game created and developed by Welsh software engineer Josh Wardle"
         << ",\n\tand owned and published by The New York Times Company since 2022."
         << " The game gained a large \n\tamount of popularity in December 2021 after Wardle added the ability "
         << "for players to copy \n\ttheir daily results as emoji squares, which were widely shared on Twitter.\n\n";

    cout << BLACK;
    cout << "\n\tABOUT THIS GAME\n";
    cout << GREY;
    cout << "\tThis Game is Developed by Ankush Gautam (Ag). I love this game and was my go to partner\n\tduring the lockdown period,"
         << "Me and my friend Keeran used to play this daily.\n\n\tI'm currently studying Bachelor in Computer Application and "
         << " we are learning C++ in the \n\tcourse so I thought can I make the game which I play daily as it has simple logic \n\tand interface "
         << "comparing to other games. So I started to create thisgame and well this \n\tis the progress I have made till now.";


    pause();
}
