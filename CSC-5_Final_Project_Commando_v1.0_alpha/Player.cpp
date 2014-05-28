//Defines Player class members
//Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Player.h"
#include "TileObj.h"
#include "Weapon.h"
using namespace std;

//Function definitions

Player::Player(){       //default constructor for Player instance
    
}
Player::Player(string name, short x_coord, short y_coord){      //creates player object, located at (posx, posy))
    P_Name = name;
    c_ID = '@';
    posx = x_coord;
    posy = y_coord;
}
Player::~Player(){      //destructor for the player instance
    //cleanup code here
}
char Player::Occupy(short x_coord, short y_coord, bool &isSet){
    if(x_coord == posx && y_coord == posy){
        isSet = true;
    }
    else{
        isSet = false;
    }
    return c_ID;
}
