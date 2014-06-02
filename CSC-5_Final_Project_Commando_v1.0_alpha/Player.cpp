/* 
 * FILE: Player.cpp
 * NAME: Ezra Guinmapang
 * DATE: May 24, 2014, 11:41 PM
 * PURPOSE: Player class source file
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Player.h"
#include "TileObj.h"
#include "Weapon.h"
using namespace std;
typedef TileObj *tile;
//Player class function definitions
Player::Player(){       //default constructor for Player instance
    
}
Player::Player(tile grid[][10], const int &ROW, const int &COL, string name, int x_coord, int y_coord):Actor(x_coord, y_coord){      //creates player object, located at (posx, posy))
    P_Name = name;
    c_ID = '@';
    Initialize(grid, ROW, COL);
}
Player::~Player(){      //destructor for the player instance
    //cleanup code here
}
bool Player::Initialize(tile grid[][10], const int &ROW, const int &COL){
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            Occupy(grid[idx][ctr]);
        }
    }
}
void Player::Occupy(tile c_tile){
    if(c_tile->Match(posx, posy)){
        c_tile->SetDisp(posx, posy, c_ID);
        t_obj = c_tile;
        cout << "Player tile: " << c_tile << endl;
    }
}
bool Player::Move(const int &ROW, const int &COL){
    t_obj->SetEmpty();
    bool isValid = false;
    char p_in;          //player's directional input
    while(!isValid){
        cout << "Move the player: ";
        cin.get(p_in);
        switch(p_in){
            case 'w':{
                if(posx > 0){
                    posx--;
                    isValid = true;
                }
                break;
            }
            case 'a':{
                if(posy > 0){
                    posy--;
                    isValid = true;
                }
                break;
            }
            case 's':{
                if(posx < ROW-1){
                    posx++;
                    isValid = true;
                }
                break;
            }
            case 'd':{
                if(posy < COL-1){
                    posy++;
                    isValid = true;
                }
                break;
            }
            case 'q':{
                if(posx > 0 && posy > 0){
                    posx--;
                    posy--;
                    isValid = true;
                }
                break;
            }
            case 'e':{
                if(posx > 0 && posy < COL-1){
                    posx--;
                    posy++;
                    isValid = true;
                }
                break;
            }
            case 'z':{
                if(posx < ROW-1 && posy > 0){
                    posx++;
                    posy--;
                    isValid = true;
                }
                break;
            }
            case 'c':{
                if(posx < ROW-1 && posy < COL-1){
                     posx++;
                     posy++;
                     isValid = true;
                }
                break;
            }
            default: cout << "Invalid input! Try again.\n";
        }
        cin.ignore();
    }
}
