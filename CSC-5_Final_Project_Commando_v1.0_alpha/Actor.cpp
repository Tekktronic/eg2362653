/* 
 * FILE: Actor.cpp
 * NAME: Ezra Guinmapang
 * DATE: May 24, 2014, 11:41 PM
 * PURPOSE: Actor class source file
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "TileObj.h"
#include "Actor.h"
Actor::Actor(){
    
}
Actor::Actor(int x_coord, int y_coord){
    posx = x_coord;
    posy = y_coord;
}
Actor::~Actor(){
    //clean-up code here
}
void Actor::Occupy(tile c_tile){
    
}
bool Actor::Move(){
    
}
