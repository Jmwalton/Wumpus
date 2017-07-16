#ifndef CHARCPP_GUARD
#define CHARCPP_GUARD 1

#include "map.cpp"


void hazard::isNear(){}
void hazard::action(){}

//-BAT
//----------------------------------------------------------------------------------------------------------------------
void bat::isNear(){
    cout <<  endl
         << "**********************************************************************" << endl
         << "************ You hear the faint shriek of a nearby Bat... ************" << endl
         << "**********************************************************************" << endl;
}

//TODO: bat disappears after move
void bat::action(){
    bool succMove = false;
    while(!succMove){
        int randy = rand() % dung.scale;
        if(!dung.roomVector[randy].hasHazard){
            //remove bat befroe moving player
            dung.roomVector[playerChar.where].hasBat = false;
            dung.roomVector[playerChar.where].hasSomething--;

            playerChar.where = randy;
            cout << endl << "A BAT!" << endl
                 << "Before you even know is happening, a bat swoops you up and carries you to room " << randy + 1 << endl <<endl;
            succMove = true;

            //'move' bat to new room (make new bat)
            randy = rand() % dung.totalRooms;
            //if randy happens to equal the current room or a room with a bat already, forget about it... bats dead.
            if(!dung.roomVector[randy].hasBat && randy != playerChar.where){
                whereBats.push_back(randy);
                dung.roomVector[randy].hasSomething++;
                dung.roomVector[randy].hasBat = true;
            }
        }
    }

}

//-PIT
//----------------------------------------------------------------------------------------------------------------------
void pit::isNear(){
    cout << endl
         << "**********************************************************************" << endl
         << "************ You feel a breeze... ************************************" << endl
         << "**********************************************************************" << endl;
}


//-WUMPUS
//----------------------------------------------------------------------------------------------------------------------
void wumpus::isNear(){
    cout << endl
         << "**********************************************************************" << endl
         << "************ Foul smells abound! the Wumpus is near... ***************" << endl
         << "**********************************************************************" << endl;
}

void wumpus::wumpWander(){
    int randy = rand() % 4;
    if(randy > 2){
        randy = rand() % dung.roomVector[whereHaz].actualConnecs.size();
        //cout <<endl << endl << "WUMP WANDER FROM " << whereHaz + 1 << " TO " << dung.roomVector[whereHaz].actualConnecs[randy] + 1 << endl << endl;
        dung.roomVector[whereHaz].hasSomething--;
        whereHaz = dung.roomVector[whereHaz].actualConnecs[randy];
        dung.roomVector[whereHaz].hasSomething++;
    }
}


//-BORER
//----------------------------------------------------------------------------------------------------------------------
void borer::isNear(){
    cout << "You hear the thunderous demolition of earth and stone roll through a nearby room..." << endl;
}

#endif