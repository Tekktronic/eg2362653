/* 
 * FILE: TileObj.cpp
 * NAME: Ezra Guinmapang
 * DATE: May 24, 2014, 11:41 PM
 * PURPOSE: TileObj class source file
 */
 
//Libraries
#include <iostream>
#include <cstdlib>
#include "TileObj.h"
#include "Player.h"
//TileObj class function definitions
TileObj::TileObj(){     //default constructor for tile instance
    
}
TileObj::TileObj(int &t_posx, int &t_posy){   //creates a tile instance
    posx = t_posx;
    posy = t_posy;
    e_disp = '.';
    c_disp = e_disp;
    isSet = false;
}
TileObj::~TileObj(){            //destructor for tile instance
    //cleanup code here
}
char TileObj::DispTile(){       //returns the character to display
    cout << c_disp;
}
int TileObj::get_X(){
    return posx;
}
int TileObj::get_Y(){
    return posy;
}
bool TileObj::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void TileObj::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void TileObj::SetEmpty(){
    c_disp = '.';
}
