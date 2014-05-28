/* 
 * NAME: Ezra Guinmapang
 * DATE: May 23, 2014, 5:57 PM
 * PURPOSE: CSC-5 Final Project: Create a program that plays a game called "COMMANDO"
 *          This game is my adaptation of the Unix-BSD game "Robots" This adaptation
 *          will include a "shoot" action that allows a player to kill enemy robots.
 *          This adaptation will also eliminate the "collision" of robots and instead
 *          have robots build obstacles that the player must avoid. All other victory
 *          conditions are the same as the original "Robots" game. This description
 *          may change as subsequent versions are written, coded, and tested, and the
 *          final version may deviate from this original description entirely. This
 *          section will be updated with any changes made to either the gameplay or
 *          the implementation thereof.
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include "Player.h"
#include "TileObj.h"
#include "Weapon.h"
using namespace std;
//Global variables and constants

//Function prototypes
void DispMap(TileObj *[][3], const int &);
void Populate(TileObj *[][3], const int &);
//Exection begins HERE
int main(int argc, char** argv) {
    //declare variables
    const int SIZE = 3;         //size of array
    TileObj *tile[SIZE][SIZE];  //array of tileobj instances
    Populate(tile, SIZE);       //populates the array with tileobj instances
    Player Player1("Ez", 3, 3); //creates the player instance
    DispMap(tile, SIZE);        //displays the array of tileobj instances
    return 0;
}
//Populate the array with tileobj instances
void Populate(TileObj *map[][3], const int&SIZE){
    for(int idx = 0; idx < SIZE; idx++){
        for(int ctr = 0; ctr < SIZE; ctr++){
            map[idx][ctr] = new TileObj(idx, ctr);
        }
    }
}
//Display the array of tileobj instances
void DispMap(TileObj *map[][3], const int&SIZE){
    for(int idx = 0; idx < SIZE; idx++){
        for(int ctr = 0; ctr < SIZE; ctr++){
            map[idx][ctr]->DispTile();
        }
        cout << endl;
    }
}
