#ifndef ROOMCPP_GUARD
#define ROOMCPP_GUARD 1


#include "playGame.h"

using namespace std;

void room::roomConnection(int i, int j){
    connections[i] = j;
}

int room:: freeRoom(){}

bool room:: checkConnecs(int x){}

int tRoom::freeRoom(){
    for(int i = 0; i < 3; i++){
        if(connections[i] == -1){
            return i;
        }
    }
}


bool tRoom::checkConnecs(int x){
    for(int i = 0; i < 3 ; i++) {
        if (connections[i] == x) {
            return false;
        }
    }
    for(int i = 0; i < 3; i++){
        if(connections[i] == -1){
            return true;
        }
    }
    return false;
}


//dRoom Definitions

int dRoom::freeRoom(){
    for(int i = 0; i < 4; i++){
        if(connections[i] == -1){
            return 1;
        }
    }
    return 0;
}

int dRoom:: whatFloor(){
    return connections[2];
}

bool dRoom::checkConnecs(int x , int y){
    for(int i = 0; i < 4 ; i++) {
        if (connections[i] == x) {
            return false;
        }
    }
    if(connections[y] == -1){
        return true;
    }
    return false;
}





#endif