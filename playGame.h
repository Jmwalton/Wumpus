#ifndef PLAY_GUARD
#define PLAY_GUARD 1

#include "character.h"

#include<iostream>
#include <limits>
using namespace std;
//dungeon map called "dung"
dMap dung;
//triangle map called "tri"
tMap tri;

bool gameOver;

character playerChar;



char char1, char2;
int actionInt;
unsigned int int1, int2, int3;
bool victory = false;
int tryAgain;
bool validAction;




#endif