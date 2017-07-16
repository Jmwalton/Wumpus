#ifndef MAP_GUARD
#define MAP_GUARD 1

using namespace std;

#include "room.h"

//#include "character.h"

#include <vector>
#include <string>
#include<ctime>

class map{
public:
    vector<dRoom> roomVector;
    //variables
    int totalConnections;
    int totalRooms;
    int scale;


    vector<vector<int>> floorVector = {{0, 0}};
    //functions
    virtual int buildMap(int scale);
    virtual void setSize();
    virtual void placeHaz();
    virtual void printMap();
    virtual void checkHaz();
};


//"Triangular" Map, every room has exactly three connections, 2d
class tMap : public map{
public:
    void setSize();

    int buildMap();
};

//Dungeon Map, connects rooms in a semi-linear fashion, 3d
//connections = [N, E, S, W] coordinates = [x, y, z]
class dMap : public map{
public:

    vector<int> floors;
    int lowFloor = 0;
    int highFloor = 0;

    //tracks maximum dimensions {N, E, S, W, High, Low}
    vector<int> mapDimensions = {0, 0, 0, 0, 0, 0};

    void setSize();


    void floorTrack();
    //place hazards on map
    void placeHaz();

    void checkHaz();

    void printMap();

    void printInfo();

    void setCompass(int i);

    void floorTrack(int i);

    void connectRooms();

    void setCoords();


    int buildMap();

};
#endif