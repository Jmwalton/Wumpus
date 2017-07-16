#ifndef ROOM_GUARD
#define ROOM_GUARD 1

using namespace std;

#include <vector>
#include <string>
#include<ctime>

class room{
public:
    int connections[];
    void roomConnection(int i, int j);

    bool hasHazard = false;
    int hasSomething = 0;
    bool hasBat = false;
    bool hasPit = false;

    //needs to be called in vice versa as well
    virtual int freeRoom();

    virtual bool checkConnecs(int x);

};


class tRoom : public room {
public:
    int connections[3] = {-1, -1, -1};


    //needs to be called in vice versa as well
    int freeRoom();


    bool checkConnecs(int x);

};

class dRoom : public room {
public:

    vector<int> coords = {0, 0, 0};
    //int N, E, S, W = -1;

    vector<int> connections = {-1, -1, -1, -1};
    vector<int> extraConnections = {-1, -1, -1 , -1};
    vector<int> actualConnecs;
    //int connections[4] = {-1, -1, -1, -1};
    //int dualConnections[4] = {-1, -1, -1, -1};
    //int shootsAndLadders[2] = {-1, -1};
    //needs to be called in vice versa as well

    int freeRoom();

    int whatFloor();

    bool checkConnecs(int x , int y);

};

#endif