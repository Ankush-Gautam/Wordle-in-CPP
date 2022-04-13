#include "myfunctions.h"

long long int randomGenerator(int maxSize)
{
    srand(time(NULL));
    long long int num = rand() % maxSize + 1;
    return num;
}

void pause()
{
    std::cout<<MAGENTA;
    std::cout << "\n\n\tPress Any to Key Continue...";
    getch();
    std::cout<<GREY;
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
        std::cout << char(220);
    }
}

void verticalline(int x, int y, int length)
{
    for(int i = y; i < length; i++)
    {
        gotoxy(x, i);
        std::cout << char(219);  //for bottom char(223);
    }
}


