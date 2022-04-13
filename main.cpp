#include "myfunctions.h"
#include "Wordle.h"

/* =================================================== MENU ================================================================= */
void Menu()
{
    int choice;
    Wordle game;

    do
    {
        system("cls");
        cout << BLUE;
        game.HEADER();

        cout << BLACK;
        cout << "\n\tWELCOME TO MAIN MENU\n";
        cout << GREY;
        cout << "\n\t1" << char(249) << " Start The Game";
        cout << "\n\t2" << char(249) << " Statistics";
        cout << "\n\t3" << char(249) << " How To Play";
        cout << "\n\t4" << char(249) << " About The Game";
        cout << "\n\t0" << char(249) << " Quit";

        cout << "\n\n\tEnter your choice:\n\t>> ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                game.startGame();
                break;

            case 2:
                game.statistics();
                break;

            case 3:
                game.howToPlay();
                break;

            case 4:
                game.about();
                break;
        }
    }
    while(choice != 0);
}

/* =================================================== MAIN FUNCS ================================================================= */
int main()
{
    system("title Wordle By Ag");
    system("color f8");

    Menu();

    gotoxy(8, 16); //only while coding
    return 0;
}
