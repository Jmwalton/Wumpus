#ifndef PLAYCPP_GUARD
#define PLAYCPP_GUARD 1

#include "character.cpp"

void tMove(){
    while (!validAction) {
        int moveTo;
        while (cout << "Where to? " && !(cin >> moveTo)) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input; please re-enter.\n\n";
        }

        if (moveTo - 1 == tri.triRoomVec[playerChar.where].connections[0] ||
                 moveTo - 1 == tri.triRoomVec[playerChar.where].connections[1] ||
                 moveTo - 1 == tri.triRoomVec[playerChar.where].connections[2])
        {
            playerChar.where = moveTo - 1;
            //MAP.wumpWander();
            validAction = true;

        }
        else {
            cout << endl << "---INVALID INPUT!---" << endl
                 << "please choose from the rooms connected to this one"
                 << endl << endl;
        }

        wump.tWander();

    }
}

void moveCommand(){
    while (!validAction) {
        int moveTo;

        while (cout << "Where to? " && !(cin >> moveTo)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input; please re-enter.\n\n";
        }
        if(moveTo == 0){
            cout << endl << "---INVALID INPUT!---" << endl
                 << "0 indicates no room connection in that direction," << endl
                 << "please choose a non-0 value" <<endl << endl;

        }

        else if (moveTo - 1 == dung.roomVector[playerChar.where].connections[0] ||
            moveTo - 1 == dung.roomVector[playerChar.where].connections[1] ||
            moveTo - 1 == dung.roomVector[playerChar.where].connections[2] ||
            moveTo - 1 == dung.roomVector[playerChar.where].connections[3])
        {
            playerChar.where = moveTo - 1;
            //MAP.wumpWander();
            validAction = true;
        }
        else {
            cout << endl << "---INVALID INPUT!---" << endl
                 << "please choose from the rooms connected to this one"
                 << endl << endl;
        }
        wump.wumpWander();
    }
}



int tShoot(){
    while (!validAction) {
        while (cout << "Choose flight-path (example: 1-2-3) " &&
               !(cin >> int1 >> char1 >> int2 >> char2 >> int3))
        {
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n\n";
        }
        if (char1 == '-' && char2 == '-' && int1 < tri.scale + 1 && int2 < tri.scale + 1) {
            if ((int1 - 1 == tri.triRoomVec[playerChar.where].connections[0] ||
                 int1 - 1 == tri.triRoomVec[playerChar.where].connections[1] ||
                 int1 - 1 == tri.triRoomVec[playerChar.where].connections[2])
                &&
                (int2 - 1 == tri.triRoomVec[int1-1].connections[0] ||
                 int2 - 1 == tri.triRoomVec[int1-1].connections[1] ||
                 int2 - 1 == tri.triRoomVec[int1-1].connections[2])
                &&
                (int3 - 1 == tri.triRoomVec[int2-1].connections[0] ||
                 int3 - 1 == tri.triRoomVec[int2-1].connections[1] ||
                 int3 - 1 == tri.triRoomVec[int2-1].connections[2]))
            {

                if (wump.whereHaz == int1 - 1 || wump.whereHaz == int2 - 1 || wump.whereHaz == int3 - 1) {
                    cout << endl
                         << "You listen to your arrow whistle through the cave until it *thunks* against a fleshy target"
                         << endl << endl
                         << "WAAAARRRRRRRRGGGGGGHHHHHHHHHHHHHHHHHHHHHH" << endl << endl << "You have slain the Wumpus" <<endl << "YOU WIN!";
                    return 2;
                }
                else if (((int1 - 1 == tri.triRoomVec[wump.whereHaz].connections[0] ||
                           int1 - 1 == tri.triRoomVec[wump.whereHaz].connections[1] ||
                           int1 - 1 == tri.triRoomVec[wump.whereHaz].connections[2])
                          ||
                          (int2 - 1 == tri.triRoomVec[wump.whereHaz].connections[0] ||
                           int2 - 1 == tri.triRoomVec[wump.whereHaz].connections[1] ||
                           int2 - 1 == tri.triRoomVec[wump.whereHaz].connections[2]  )
                          ||
                          (int3 - 1 == tri.triRoomVec[wump.whereHaz].connections[0] ||
                           int3 - 1 == tri.triRoomVec[wump.whereHaz].connections[1] ||
                           int3 - 1 == tri.triRoomVec[wump.whereHaz].connections[2])) ){
                    cout << endl << "You hear the Wumpus scatter as she charges between rooms." << endl;
                    int iHeardThat = (rand() % 10);
                    if (iHeardThat < 2) {
                        int wumpCharge = (rand() % 4);
                        wump.whereHaz = tri.roomVector[wump.whereHaz].connections[wumpCharge];
                    }
                    //MAP.wumpWander();
                    playerChar.arrows -= 1;
                }

                else {
                    cout << endl
                         << "You hear only the whistle of your arrow as it soars through and hits nothing..."
                         << endl;
                    //MAP.wumpWander();
                    playerChar.arrows -= 1;
                }
                validAction = true;
            }
            else {
                cout << "1---INVALID INPUT!---" << endl << "please choose three rooms that are connected!"
                     << endl << endl
                     << "Try shooting again? " << endl
                     << "type   1   for   \"YES\"   and anything else for \"NO\"" << endl;
                cin >> tryAgain;
                if (tryAgain != 1) {
                    validAction = true;
                }
            }
        }
        else {
            cout << "2---INVALID INPUT!---" << endl << "please choose three rooms that are connected!"
                 << endl << endl
                 << "Try shooting again? " << endl
                 << "type   1   for   \"YES\"   and anything else for \"NO\"" << endl;
            cin >> tryAgain;
            if (tryAgain != 1) {
                validAction = true;
            }
        }
        wump.tWander();
    }
}

int shootCommand(){
    while (!validAction) {
        while (cout << "Choose flight-path (example: 1-2-3) " &&
               !(cin >> int1 >> char1 >> int2 >> char2 >> int3))
        {
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n\n";
        }
        if (char1 == '-' && char2 == '-' && int1 < dung.scale + 1 && int2 < dung.scale + 1) {
            if ((int1 - 1 == dung.roomVector[playerChar.where].connections[0] ||
                 int1 - 1 == dung.roomVector[playerChar.where].connections[1] ||
                 int1 - 1 == dung.roomVector[playerChar.where].connections[2] ||
                 int1 - 1 == dung.roomVector[playerChar.where].connections[3])
                &&
                (int2 - 1 == dung.roomVector[int1-1].connections[0] ||
                 int2 - 1 == dung.roomVector[int1-1].connections[1] ||
                 int2 - 1 == dung.roomVector[int1-1].connections[2] ||
                 int2 - 1 == dung.roomVector[int1-1].connections[3])
                &&
                (int3 - 1 == dung.roomVector[int2-1].connections[0] ||
                 int3 - 1 == dung.roomVector[int2-1].connections[1] ||
                 int3 - 1 == dung.roomVector[int2-1].connections[2] ||
                 int3 - 1 == dung.roomVector[int2-1].connections[3]))
            {

                if (wump.whereHaz == int1 - 1 || wump.whereHaz == int2 - 1 || wump.whereHaz == int3 - 1) {
                    cout << endl
                         << "You listen to your arrow whistle through the cave until it *thunks* against a fleshy target"
                         << endl << endl
                         << "WAAAARRRRRRRRGGGGGGHHHHHHHHHHHHHHHHHHHHHH" << endl << endl << "You have slain the Wumpus" <<endl << "YOU WIN!";
                    return 2;
                }
                else if (((int1 - 1 == dung.roomVector[wump.whereHaz].connections[0] ||
                           int1 - 1 == dung.roomVector[wump.whereHaz].connections[1] ||
                           int1 - 1 == dung.roomVector[wump.whereHaz].connections[2] ||
                           int1 - 1 == dung.roomVector[wump.whereHaz].connections[3]   )
                          ||
                          (int2 - 1 == dung.roomVector[wump.whereHaz].connections[0] ||
                           int2 - 1 == dung.roomVector[wump.whereHaz].connections[1] ||
                           int2 - 1 == dung.roomVector[wump.whereHaz].connections[2] ||
                           int2 - 1 == dung.roomVector[wump.whereHaz].connections[3]   )
                          ||
                          (int3 - 1 == dung.roomVector[wump.whereHaz].connections[0] ||
                           int3 - 1 == dung.roomVector[wump.whereHaz].connections[1] ||
                           int3 - 1 == dung.roomVector[wump.whereHaz].connections[2] ||
                           int3 - 1 == dung.roomVector[wump.whereHaz].connections[3])) ){
                    cout << endl << "You hear the Wumpus scatter as she charges between rooms." << endl;
                    int iHeardThat = (rand() % 100);
                    if (iHeardThat < 20) {
                        int wumpCharge = (rand() % 4);
                        wump.whereHaz = dung.roomVector[wump.whereHaz].connections[wumpCharge];
                    }
                    //MAP.wumpWander();
                    playerChar.arrows -= 1;
                }

                else {
                    cout << endl
                         << "You hear only the whistle of your arrow as it soars through and hits nothing..."
                         << endl;
                    //MAP.wumpWander();
                    playerChar.arrows -= 1;
                }
                validAction = true;
            }
            else {
                cout << "1---INVALID INPUT!---" << endl << "please choose three rooms that are connected!"
                     << endl << endl
                     << "Try shooting again? " << endl
                     << "type   1   for   \"YES\"   and anything else for \"NO\"" << endl;
                cin >> tryAgain;
                if (tryAgain != 1) {
                    validAction = true;
                }
            }
        }
        else {
            cout << "2---INVALID INPUT!---" << endl << "please choose three rooms that are connected!"
                 << endl << endl
                 << "Try shooting again? " << endl
                 << "type   1   for   \"YES\"   and anything else for \"NO\"" << endl;
            cin >> tryAgain;
            if (tryAgain != 1) {
                validAction = true;
            }
        }
        wump.wumpWander();
    }

}



void tDebug(){
    cout << endl <<  "-------------------------- DEBUG INFO -------------------------------------------------------------" << endl<< endl;
    tri.printMap();
    tri.printInfo();
    cout << "------------------- No Turn Taken." << endl << "As a reminder, You are still in...     ------------------------------------------------------";
}

void debugCommand(){
    cout << endl <<  "-------------------------- DEBUG INFO -------------------------------------------------------------" << endl<< endl;
    dung.printMap();
    dung.printInfo();
    cout << "------------------- No Turn Taken." << endl << "As a reminder, You are still in...     ------------------------------------------------------";
}



int tCommand(){
    validAction = false;
    string actionType;
    while ( cout << "Move (m) or Shoot (s):"
            && !(cin >> actionType)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "Invalid input; please re-enter.\n";
    }

    if(actionType.length() == 1) {
        //MOVE COMMAND
        if (actionType == "m" || actionType == "M") {
            tMove();
        }

            //SHOOT COMMAND
        else if (actionType == "s" || actionType == "S") {
            if(tShoot() == 2){
                return 3;
            }
        }
            //DEBUG COMMAND

        else if (actionType == "d" || actionType == "D") {
            tDebug();
            return 2;
            /*
            cout << endl <<  "-------------------------- DEBUG INFO -------------------------------------------------------------" << endl<< endl;
            dung.printMap();
            dung.printInfo();
            cout << "------------------- No Turn Taken." << endl << "As a reminder, You are still in...     ------------------------------------------------------";
             */
        }
    }
    else{
        cout << endl << endl
             << "     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
             << "      Please enter a valid action:  m (Move), s (Shoot) or d (Debug)  " << endl
             << "                                   No Turn Taken                     " << endl
             << "     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< endl;
    }

}

int command(){
    validAction = false;
    string actionType;
    while ( cout << " _Compass_" << endl
                 << "|    " << dung.roomVector[playerChar.where].connections[0] + 1<< "    |" << endl
                 <<"|  " <<dung.roomVector[playerChar.where].connections[3] + 1 << "-|-" << dung.roomVector[playerChar.where].connections[1] + 1 <<"  |" <<endl
                 << "|___ " << dung.roomVector[playerChar.where].connections[2] + 1 <<" ___|" <<"     Move (m) or Shoot (s):"
            && !(cin >> actionType)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "Invalid input; please re-enter.\n";
    }

    if(actionType.length() == 1) {
        //MOVE COMMAND
        if (actionType == "m" || actionType == "M") {
            moveCommand();
        }

        //SHOOT COMMAND
        else if (actionType == "s" || actionType == "S") {
            if(shootCommand() == 2){
                return 3;
            }
        }
            //DEBUG COMMAND

        else if (actionType == "d" || actionType == "D") {
            debugCommand();
            return 2;
            /*
            cout << endl <<  "-------------------------- DEBUG INFO -------------------------------------------------------------" << endl<< endl;
            dung.printMap();
            dung.printInfo();
            cout << "------------------- No Turn Taken." << endl << "As a reminder, You are still in...     ------------------------------------------------------";
             */
        }
    }
    else{
        cout << endl << endl
             << "     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
             << "      Please enter a valid action:  m (Move), s (Shoot) or d (Debug)  " << endl
             << "                                   No Turn Taken                     " << endl
             << "     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< endl;
    }

}


bool roomWithPit(){
    cout<< endl << "You step ahead and..." << endl;
    int deadAF = rand() % 10;
    if(deadAF < 4){
        cout << "fall into a bottomless pit to your DEATH!!!!" << endl << endl;
        return true;
    }
    else{
        cout << "fall forward into a pit, but quickly grab the ledge... phew!" << endl;
        return false;
    }
}




void tCheckNear(){
    for(int i = 0; i < 3; i++){
        int j = tri.triRoomVec[playerChar.where].actualConnecs[i];
        if(tri.triRoomVec[j].hasSomething > 0){
            if(tri.triRoomVec[j].hasBat){
                caveBats.isNear();
            }
            if(tri.triRoomVec[j].hasPit){
                bottomlessPits.isNear();
            }
            if(j == wump.whereHaz){
                wump.isNear();
            }
        }

    }
}

void checkNear(){
    for(int i = 0; i < dung.roomVector[playerChar.where].actualConnecs.size() ; i++){
        int j = dung.roomVector[playerChar.where].actualConnecs[i];
        if(dung.roomVector[j].hasSomething > 0){
            if(dung.roomVector[j].hasBat){
                caveBats.isNear();
            }
            if(dung.roomVector[j].hasPit){
                bottomlessPits.isNear();
            }
            if(j == wump.whereHaz){
                wump.isNear();
            }
        }

    }
}


//D-MAP -----------------------------------------------------------------------------------------------------------------

void playGameD(){
    bool gameOver = false;

    dung.buildMap();
    //dung.printMap();
    //dung.printInfo();
    //flavor
    cout << "  --------------------------------------------------WELCOME TO WUMPUS--------------------------------------------------"  << endl
         << "         You have hunted the Wumpus tirelessly and now find yourself in her home; a dark and cavernous labyrinth. "       << endl
         << "       You are certain the Wumpus lurks around here somewhere. She is a deadly foe and will eat you if she sees you."     << endl
         << "               Luckily, you are equipped with 5 Arrows that can shoot and bend through a distance of 3 rooms: "           << endl << endl
         << "                               If your arrow should find the Wumpus, she will be slain!"                                  << endl
         << "                       ...However, if you should run out of arrows you are dead meat for sure."                           << endl << endl
         << "                             Tread lightly; be wary of pits, cave-bats, and the Wumpus herself."                          << endl
         << "  --------------------          Remember where you've been, plan carefully, and good luck      ------------------------"  << endl << endl;

   // cout << "where = " << dung.roomVector[playerChar.where].connections[0] << endl
    //     << "[0] = "<< dung.roomVector[0].connections[0] << endl;
    while(!gameOver) {
        if(playerChar.arrows == 0){
            goto LOST;
        }
        if(dung.roomVector[playerChar.where].hasSomething > 0){
            if(dung.roomVector[playerChar.where].hasPit){
                if(roomWithPit()){
                    gameOver = true;
                    goto LOST;
                }
            } //function declared in this header, NOT CHARACTER.h/cpp

            if(playerChar.where == wump.whereHaz){
                gameOver = true;
                cout << endl << "You enter the room and find yourself face to face with the Wumpus "
                     << endl << "You involuntarily mutter \"Oh.\" before being devoured" << endl << endl;
                goto LOST;
            }
            if(dung.roomVector[playerChar.where].hasBat){
                caveBats.action();
            }

        }

        checkNear();

        noTurn:

        cout << endl << endl << "---Room " << playerChar.where + 1 << " --- Floor " << dung.roomVector[playerChar.where].coords[2]  <<"-"
             << endl <<"Arrows: " << playerChar.arrows << endl << endl;
        /*
        if(command() == 2){
            goto noTurn;
        }
         */
        switch(command()){
            case 2:
                goto noTurn;
            case 3:
                gameOver = false;
                return;
        }



    }
    LOST:
    cout << "YOU LOSE!" << endl;
    return;
}

//TRI-MAP---------------------------------------------------------------------------------------------------------------


void playGameT(){
    bool gameOver = false;

    tri.buildMap();
    //tri.printMap();
    //tri.printInfo();

    //flavor
    cout << "  --------------------------------------------------WELCOME TO WUMPUS--------------------------------------------------"  << endl
         << "         You have hunted the Wumpus tirelessly and now find yourself in her home; a dark and cavernous labyrinth. "       << endl
         << "       You are certain the Wumpus lurks around here somewhere. She is a deadly foe and will eat you if she sees you."     << endl
         << "               Luckily, you are equipped with 5 Arrows that can shoot and bend through a distance of 3 rooms: "           << endl << endl
         << "                               If your arrow should find the Wumpus, she will be slain!"                                  << endl
         << "                       ...However, if you should run out of arrows you are dead meat for sure."                           << endl << endl
         << "                             Tread lightly; be wary of pits, cave-bats, and the Wumpus herself."                          << endl
         << "  --------------------          Remember where you've been, plan carefully, and good luck      ------------------------"  << endl << endl;

    // cout << "where = " << dung.roomVector[playerChar.where].connections[0] << endl
    //     << "[0] = "<< dung.roomVector[0].connections[0] << endl;




    while(!gameOver) {

        if(playerChar.arrows == 0){
            goto LOST;
        }


        if(tri.triRoomVec[playerChar.where].hasSomething > 0){

            if(tri.triRoomVec[playerChar.where].hasPit){
                if(roomWithPit()){
                    gameOver = true;
                    goto LOST;
                }
            } //function declared in this header, NOT CHARACTER.h/cpp

            if(playerChar.where == wump.whereHaz){
                gameOver = true;
                cout << endl << "You enter the room and find yourself face to face with the Wumpus "
                     << endl << "You involuntarily mutter \"Oh.\" before being devoured" << endl << endl;
                goto LOST;
            }

            if(tri.triRoomVec[playerChar.where].hasBat){
                caveBats.tBatAction();
            }

        }


        tCheckNear();

        noTurn:

        cout << endl
             << "Room " << playerChar.where + 1 << " ----------------------" << endl
             << "From here there is a path to rooms " << tri.triRoomVec[playerChar.where].connections[0] + 1 << ", "
             << tri.triRoomVec[playerChar.where].connections[1] + 1 << ", and "
             << tri.triRoomVec[playerChar.where].connections[2] + 1 << endl << endl;

        switch(tCommand()){
            case 2:
                goto noTurn;
            case 3:
                gameOver = false;
                return;
        }



    }
    LOST:
    cout << "YOU LOSE!" << endl;
    return;
}


void playWumpus(){
    string whichMap;
    bool inGame = false;
    while(!inGame){
        while ( cout << "Cave Map (c) or Dungeon Map (d)?" << endl
                && !(cin >> whichMap))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Invalid input; please re-enter.\n";
        }
        if(whichMap.length() == 1) {
            if (whichMap == "c" || whichMap == "C") {
                inGame = true;
                playGameT();
            }

            else if (whichMap == "d" || whichMap == "D") {
                inGame = true;
                playGameD();
            }
        }
        else{
            cout << endl << endl
                 << "     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
                 << "                       Please enter a valid map type:                " << endl
                 << "                   type 'd' for Dungeon or type 'c' for cave         " << endl
                 << "     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< endl;
        }
    }
}

#endif