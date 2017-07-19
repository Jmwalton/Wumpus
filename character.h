#ifndef CHAR_GUARD
#define CHAR _GUARD 1

#include "map.h"

using namespace std;


class character{
public:
    int where = 0;
    int arrows = 5;
};

class hazard{
public:
    //what room is the hazard in?
    int whereHaz = -1;
    //player is in a room connecting to this hazard
    virtual void isNear();
    virtual void action();
};

//Dungeon Bat
//carries player to a random room, same floor in dungeon, andy safe room in triangle
class bat : public hazard{
public:
    void isNear();

    void tBatAction();
    void action();


    vector<int> whereBats;

};

//bottomless pit
//player has chance to fall in
class pit: public hazard{
public:
    void isNear();
    vector<int> wherePits;
};

//WUMPUS
//kills player
class wumpus: public hazard{
public:
    void isNear();

    void tWander();
    void wumpWander();
};

//Borer
//bores holes through walls of a dungeon, creating new connections (sometimes), and (harmlessly) carrying the player with it if they converge
//?only underground?
class borer: public hazard{
public:
    void isNear();
    vector<int> boreCoords = {0,0,-10};
};

#endif