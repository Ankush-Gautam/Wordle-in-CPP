#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED

#include "dictionary.h"
#include "Colors.h"     //my colors
#include <iostream>
#include <conio.h>     //for getch
#include <ctime>     //for srand
#include <windows.h> //for gotoxy
#include <random>    //for random
#include <fstream>
using namespace std;

long long int randomGenerator(int);
void pause();
void gotoxy(int,int);
void upperline(int);
void verticalline(int,int,int);

#endif // MYFUNCTIONS_H_INCLUDED
