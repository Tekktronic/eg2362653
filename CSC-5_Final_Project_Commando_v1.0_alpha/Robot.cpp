/* 
 * FILE: Robot.cpp
 * NAME: Ezra Guinmapang
 * DATE: May 24, 2014, 11:41 PM
 * PURPOSE: Robot class source file
 */

//Libraries
//Defines Player class members
//Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Actor.h"
#include "TileObj.h"
#include "Robot.h"
using namespace std;
typedef TileObj *tile;
//Robot class function definitions
Robot::Robot(){       //default constructor for Robot instance
    
}
Robot::Robot(int x_coord, int y_coord){
    posx = x_coord;
    posy = y_coord;
}
Robot::Robot(tile grid[][10], const int &ROW, const int &COL, string name, int x_coord, int y_coord):Actor(x_coord, y_coord){      //creates player object, located at (posx, posy))
    P_Name = name;
    c_ID = '#';
    Initialize(grid, ROW, COL);
}
Robot::~Robot(){      //destructor for the player instance
    //cleanup code here
}
bool Robot::Initialize(tile grid[][10], const int &ROW, const int &COL){
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            Occupy(grid[idx][ctr]);
        }
    }
}
void Robot::Occupy(tile c_tile){
    if(c_tile->Match(posx, posy)){
        c_tile->SetDisp(posx, posy, c_ID);
        t_obj = c_tile;
        cout << "Robot tile: " << c_tile << endl;
    }
}
bool Robot::Move(const int &ROW, const int &COL){
    t_obj->SetEmpty();
    bool isValid = false;
    int move; 
    while(!isValid){
        move = (rand()%8) + 1;          //generate the random movement of the Robot
        switch(move){
            case 1:{
                if(posx > 0){
                    posx--;
                    isValid = true;
                }
                break;
            }
            case 2:{
                if(posy > 0){
                    posy--;
                    isValid = true;
                }
                break;
            }
            case 3:{
                if(posx < ROW-1){
                    posx++;
                    isValid = true;
                }
                break;
            }
            case 4:{
                if(posy < COL-1){
                    posy++;
                    isValid = true;
                }
                break;
            }
            case 5:{
                if(posx > 0 && posy > 0){
                    posx--;
                    posy--;
                    isValid = true;
                }
                break;
            }
            case 6:{
                if(posx > 0 && posy < COL-1){
                    posx--;
                    posy++;
                    isValid = true;
                }
                break;
            }
            case 7:{
                if(posx < ROW-1 && posy > 0){
                    posx++;
                    posy--;
                    isValid = true;
                }
                break;
            }
            case 8:{
                if(posx < ROW-1 && posy < COL-1){
                     posx++;
                     posy++;
                     isValid = true;
                }
                break;
            }
            default: continue;
        }
    }
}
