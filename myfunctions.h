#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED

#include "Colors.h"     //my colors
#include <iostream>
#include <conio.h>     //for getch
#include <ctime>     //for srand
#include <windows.h> //for gotoxy
#include <random>    //for random

long long int randomGenerator(int);
void pause();
void gotoxy(int,int);
void upperline(int);
void verticalline(int,int,int);

#endif // MYFUNCTIONS_H_INCLUDED
