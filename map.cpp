#ifndef MAPCPP_GUARD
#define MAPCPP_GUARD 1


#include "room.cpp"

wumpus wump;
bat caveBats;
borer bore;
pit bottomlessPits;

//functions
int map::buildMap(int scale){}

void map::setSize(){}
void map::placeHaz(){}
void map::checkHaz(){}

void map::printMap(){}
void map::printInfo(){}



//"Triangular" Map, every room has exactly three connections, 2d

void tMap::setSize(){
    cout << endl << "Enter Map Size (# of rooms): ";
    cin >> scale;
    if(scale < 10){
        scale = 10;
    }

    else if( scale > 50){
        scale = 50;
    }
    if(scale % 2 != 0){
        scale += 1;
    }
    cout << "Building Map... (" << scale << ")" << endl <<endl;
}



void tMap::placeHaz(){
    //1 wumpus
    //2 bat / 20 rooms
    //1 pit/ 20 rooms
    int randy;
    for(int i = 0; i < scale/10;){
        randy = rand() % totalRooms;
        if(!triRoomVec[randy].hasHazard && randy != 0){
            triRoomVec[randy].hasHazard = true;
            triRoomVec[randy].hasSomething++;
            triRoomVec[randy].hasPit = true;
            bottomlessPits.wherePits.push_back(randy);
            i++;
        }
    }
    randy = rand() % totalRooms - 1;
    wump.whereHaz = randy + 1;
    triRoomVec[randy + 1].hasSomething++;

    for(int i = 0; i < scale/10;){
        randy = rand() % totalRooms;
        if(!triRoomVec[randy].hasHazard  && randy != 0){
            caveBats.whereBats.push_back(randy);
            triRoomVec[randy].hasSomething++;
            triRoomVec[randy].hasBat = true;
            i++;
        }
    }


}

void tMap::printMap(){
    //print final map
    cout << endl;
    for(int g = 0; g < totalRooms; g++){
        cout << g + 1 << endl << triRoomVec[g].connections[0] + 1 << " " << triRoomVec[g].connections[1] + 1
             << " " << triRoomVec[g].connections[2] + 1 << "      hasSomething == " << triRoomVec[g].hasSomething <<   endl << endl;
    }

}

void tMap::printInfo(){
    cout <<"Wumpus location: " << wump.whereHaz + 1 << endl;

    for(int i = 0; i < caveBats.whereBats.size(); i++){
        cout << "Bat" << i+1 << " location: " << caveBats.whereBats[i] + 1 << endl;
    }

    for(int i = 0; i < bottomlessPits.wherePits.size(); i++){
        cout << "Pit" << i+1 << " location: " << bottomlessPits.wherePits[i] + 1 << endl;
    }
    cout << endl;
}


int tMap::buildMap() {
    //begin failure timer
    int begin;
    srand(time(0));

    setSize();
    //array of rooms, scale = # of rooms
    tRoom roomList[scale];

    for(int i = 0; i < scale; i++){
        triRoomVec.push_back(roomList[i]);
    }
    /*
    for(int g = 0; g < scale; g++){
        cout << endl << "room " << g + 1 <<  "  hasSomething == " << triRoomVec[g].hasSomething <<   endl << endl;
    }
     */

    totalConnections = 3;
    totalRooms = scale;

    //timer reset loop
    reset:
    begin = time(0);
    for (int i = 0; i < totalRooms; i++) {
        for (int j = 0; j < 3;) {
            //!!!!!!!!END OF TIMER, IF LOOP GOES FOR 1 SECOND IT WILL FAIL!!!!!!!!!
            int tooLong = time(0);
            if (tooLong - begin > 1) { //FAILED!! reset all rooms and return 0 so function is called again.
                for (int resetRoom = 0; resetRoom < totalRooms; resetRoom++) {
                    for (int resetConnections = 0; resetConnections < totalConnections; resetConnections++) {
                        triRoomVec[resetRoom].connections[resetConnections] = -1;
                    }
                }
                cout << "Patience is a virtue..." << endl;

                goto reset;
            }

            //if connection[j] is occupied, continue looping
            //else, connect randy to i through connection[j] (and vice versa)
            if (triRoomVec[i].connections[j] != -1) {
                j++;
            }
            else {
                int randy = (rand() % totalRooms);
                if (randy != i && triRoomVec[randy].checkConnecs(i) && triRoomVec[i].checkConnecs(randy)) {
                    triRoomVec[i].connections[j] = randy;
                    triRoomVec[i].actualConnecs.push_back(randy);

                    triRoomVec[randy].connections[triRoomVec[randy].freeRoom()] = i;
                    triRoomVec[randy].actualConnecs.push_back(i);
                    j++;
                }
            }
        }
    }

    placeHaz();
    /*
    //print final map
    for(int g = 0; g < totalRooms; g++){
        cout << g + 1 << endl << roomList[g].connections[0] + 1 << " " << roomList[g].connections[1] + 1
             << " " << roomList[g].connections[2] + 1 << " " <<  endl << endl;
    }
     */
    cout << endl << "Map Built." << endl << endl;
    //return 1;
}



//----------------------------------------------------------------------------------------------------------------------
//Dungeon Map, connects rooms in a semi-linear fashion, 3d
//connections = [N, E, S, W] coordinates = [x, y, z]
void dMap::setSize(){
    cout << endl << "Enter Map Size (# of rooms): ";
    cin >> scale;
    if(scale < 5){
        scale = 5;
    }

    else if( scale > 600){
        scale = 600;
    }

    cout << "Building Map... (" << scale << ")" << endl <<endl;
}

void dMap::checkHaz(){
    for(int i = 0; i < scale; i++){
    }
}


void dMap::placeHaz(){
    //1 wumpus
    //1 bat/15 rooms
    //1 borer
    //1 pit/20 rooms
    int randy;
    for(int i = 0; i < (scale/40) + 1;){
        randy = rand() % totalRooms;
        if(!roomVector[randy].hasHazard && roomVector[randy].coords[2] <= 0 && randy > 0){
            roomVector[randy].hasHazard = true;
            roomVector[randy].hasSomething++;
            roomVector[randy].hasPit = true;
            bottomlessPits.wherePits.push_back(randy);
            i++;
        }
    }
    randy = rand() % totalRooms - 1;
    wump.whereHaz = randy + 1;
    roomVector[randy + 1].hasSomething++;

    for(int i = 0; i < scale/15;){
        randy = rand() % totalRooms;
        if(!roomVector[randy].hasHazard  && randy > 0){
            caveBats.whereBats.push_back(randy);
            roomVector[randy].hasSomething++;
            roomVector[randy].hasBat = true;
            i++;
        }
    }


}


void dMap::floorTrack(int i){
    //Northmost
    if(roomVector[i].coords[1] > mapDimensions[0]){
        mapDimensions[0] = roomVector[i].coords[1];
    }
    //Southmost
    else if(roomVector[i].coords[1] < mapDimensions[2]){
        mapDimensions[2] = roomVector[i].coords[1];
    }
    //Eastmost
    if(roomVector[i].coords[0] > mapDimensions[1]){
        mapDimensions[1] = roomVector[i].coords[0];
    }
    //Westmost
    else if(roomVector[i].coords[0] < mapDimensions[3]){
        mapDimensions[3] = roomVector[i].coords[0];
    }
    //Highest
    if(roomVector[i].coords[2] > mapDimensions[4]){
        mapDimensions[4] = roomVector[i].coords[2];
    }
    //Lowest
    else if(roomVector[i].coords[2] < mapDimensions[5]){
        mapDimensions[5] = roomVector[i].coords[2];
    }

    for(int j = 0; j < floorVector.size(); j++){
        if(floorVector[j][0] == roomVector[i].coords[2]){
            floorVector[j].push_back(i);
            return;
        }
    }
    floorVector.push_back({roomVector[i].coords[2], i});
    return;
}


void dMap:: connectRooms(){
    //i is to room to be connected to
    //h is room to be placed
    //j is connection index
    for(int i = 0, h = 1; h < totalRooms; i++ ){
        //has this room made at least 1 connection?
        bool connecMade = false;
        //does this room have all four connections filled?
        if(roomVector[i].freeRoom() == 0){
            //setCompass(i);
            i++;
        }
        //insure h and i dont match up
        if(i >= h){
            h = i + 1;
        }
        //cycle through j until at least one connection is made and j goes through another full cycle
        // j % 4 will be the index of j, even when j > 3
        for(int j = 0; j % 4 < 3 || !connecMade ;){
            if (roomVector[i].connections[j % 4] != -1){
                j++;
            }
                //if randy is greater than 8 (20% chance), connection with h will be made (and vice versa)
            else{
                int randy = (rand() % 10) + 1;
                if(randy > 8){
                    roomVector[i].connections[j % 4] = h;
                    roomVector[i].actualConnecs.push_back(h);

                    roomVector[h].connections[(j + 2) % 4] = i;
                    roomVector[h].actualConnecs.push_back(i);
                    //CONNECTION MADE
                    //cout << i <<  " ----> " << h << endl;
                    //increment j (connections), h (room to be connected)
                    //and flip connecMade to true
                    j++;
                    h++;
                    connecMade = true;
                    //cout << "i = " << i + 1 <<  " --- h = " << h + 1 << endl << endl;
                }
                    //no connection, increment j and continue loop
                else{
                    j++;
                }
            }
        }
    }
}

void dMap:: setCoords(){
    //COORDS
    //sets room coordinates (After they have already been connected)
    //starting at [0, 0, 0] for roomList[0], add coordinates with respect to the previous room
    //i = this room's coordinates are being set
    //j = index in coord array being set
    //k = room# connected to i whose coords are being used to set i's coords
    for(int i = 1; i < totalRooms; i++){
        for(int j = 0; j < 4; j++){
            //the connection at j is filled and lower than i
            if(roomVector[i].connections[j] != -1 && roomVector[i].connections[j] < i){
                int k = roomVector[i].connections[j];
                //connection is north
                if(j == 0){
                    //x coordinate
                    roomVector[i].coords[0] = roomVector[ k ].coords[0];
                    //y coordinate
                    roomVector[i].coords[1] = roomVector[ k ].coords[1] - 1;
                    //z coordinate
                    roomVector[i].coords[2] = roomVector[ k ].coords[2];

                }
                    //connection is east
                else if(j == 1){
                    //x coordinate
                    roomVector[i].coords[0] = roomVector[ k ].coords[0] -1;
                    //y coordinate
                    roomVector[i].coords[1] = roomVector[ k ].coords[1];
                    //z coordinate
                    roomVector[i].coords[2] = roomVector[ k ].coords[2];
                }
                    //connection is south
                else if(j == 2){
                    //x coordinate
                    roomVector[i].coords[0] = roomVector[ k ].coords[0];
                    //y coordinate
                    roomVector[i].coords[1] = roomVector[ k ].coords[1] + 1;
                    //z coordinate
                    roomVector[i].coords[2] = roomVector[ k ].coords[2];
                }
                    //connection is west
                else if(j == 3){
                    //x coordinate
                    roomVector[i].coords[0] = roomVector[ k ].coords[0] + 1;
                    //y coordinate
                    roomVector[i].coords[1] = roomVector[ k ].coords[1];
                    //z coordinate
                    roomVector[i].coords[2] = roomVector[ k ].coords[2];
                }
            }
        }
        //'direc' is implemented in order to keep overlapping moving up or down, not both
        //  1 = up, -1 = down
        int direc = 0;
        //'h' is room (lower than i) that is being checked for exact matching coordinates
        //'upDown' is the number of rooms currently overlapping
        //  z coordinate is incremented by upDown
        flag:
        int upDown = 0;
        for(int h = 0; h < i; h++){
            //check if room has matching coordinates
            if(roomVector[i].coords[0] == roomVector[h].coords[0] && roomVector[i].coords[1] == roomVector[h].coords[1] && roomVector[i].coords[2] == roomVector[h].coords[2]){
                upDown++;
            }
        }
        //'randyH' determines whether room moves up or down
        int randyH = (rand() % 10) + 1;
        //move room up
        if(upDown > 0 && (randyH > 5 || direc == 1)){
            roomVector[i].coords[2] = roomVector[i].coords[2] + upDown;
            direc = 1;
            //loop through again, make sure move didnt just put i overlapping another room
            goto flag;
        }
        //move room down
        else if(upDown > 0 && (randyH < 6 || direc == -1)){
            roomVector[i].coords[2] = roomVector[i].coords[2] - upDown ;
            direc = -1;
            //loop through again, make sure move didnt just put i overlapping another room
            goto flag;
        }

        floorTrack(i);
    }

}

void dMap::printMap(){
    //prints map
    //int g is index of room in roomList[] array
    for(int g = 0; g < totalRooms; g++){
        cout <<"- " << g + 1 << " --- [" << roomVector[g].coords[0] << " , " << roomVector[g].coords[1] << " , "
             << roomVector[g].coords[2] << "] " << endl << roomVector[g].connections[0] + 1 << " "
             << roomVector[g].connections[1] + 1 << " " << roomVector[g].connections[2] + 1 << " "
             << roomVector[g].connections[3] + 1 << "             hasSomething == " << roomVector[g].hasSomething  << endl << endl;
    }

    /*
    //prints room if they are the exact same...... !!!SHOULD NOT PRINT ANYTHING!!!
    //int y == higher# room
    //int z == lower# room
    for(int y = 1; y < totalRooms; y++){
        for(int z = 0; z < y; z++){
            if(roomVector[y].coords[0] == roomVector[z].coords[0] && roomVector[y].coords[1] == roomVector[z].coords[1]
               && roomVector[y].coords[2] == roomVector[z].coords[2])
            {
                cout << y + 1 << " = " << z + 1 <<endl << endl;
            }
        }
    }
    */
}

void dMap::printInfo(){
    cout <<"Floors: " << floorVector.size() << endl
         <<"Top Floor: " << mapDimensions[4] << endl
         <<"Bottom Floor: " << mapDimensions[5] << endl << endl
         <<"North limit: " << mapDimensions[0] << endl
         <<"East limit: " << mapDimensions[1] << endl
         <<"South limit: " << mapDimensions[2] << endl
         <<"West limit: " << mapDimensions[3] << endl << endl
         <<"Wumpus location: " << wump.whereHaz + 1 << endl
         <<"Borer Coords: {" << bore.boreCoords[0] << ", " << bore.boreCoords[1] << ", " << bore.boreCoords[2] << "}" << endl;

    for(int i = 0; i < caveBats.whereBats.size(); i++){
        cout << "Bat" << i+1 << " location: " << caveBats.whereBats[i] + 1 << endl;
    }

    for(int i = 0; i < bottomlessPits.wherePits.size(); i++){
        cout << "Pit" << i+1 << " location: " << bottomlessPits.wherePits[i] + 1 << endl;
    }
    cout << endl;
}

//TODO: make rooms that are touching but not connected have a chance at connecting
//TODO: make rooms that are above or below one another have a chance at connecting (shoots and laddeers)
int dMap::buildMap(){
    srand(time(0));

    //SET SIZE
    setSize();

    //array of rooms, scale is # of rooms
    dRoom roomList[scale];

    for(int i = 0; i < scale; i++){
        roomVector.push_back(roomList[i]);
    }

    totalRooms = scale;

    connectRooms();

    setCoords();
    placeHaz();

    //Prints Map
    //printMap();
    //printInfo();

    cout << "Map Built." << endl << endl << endl;
    return 1;
}

#endif