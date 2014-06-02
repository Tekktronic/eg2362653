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
#include "TileObj.h"
#include "Actor.h"
#include "Player.h"
#include "Robot.h"
using namespace std;

//Global variables and constants

//Function prototypes
void DispMap(tile[][10], const int&, const int&);    //display the map
void Populate(tile[][10], const int&, const int&);   //populate the map
void FindTile(tile[][10], const int&, const int&, Actor*);        //find a match in the tile object array
//Exection begins HERE
int main(int argc, char** argv) {
    //declare variables
    srand(static_cast<unsigned int>(time(0)));  //seed the random number generator
    const int ROW = 5;         //row size
    const int COL = 10;         //column size
    tile grid[ROW][COL];  //array of tileobj pointers
    Populate(grid, ROW, COL);       //populates the array with tileobj instances
    Player *Player1 = new Player(grid, ROW, COL, "EzTmp", 0, 0);        //create the player instance
    Robot *Robot1 = new Robot(grid, ROW, COL, "R1", ROW-1, COL-1);      //create the robot instance
    DispMap(grid, ROW, COL);       //Display the initial grid
    
    Player1->Move(ROW, COL);        //tells the player instance to change its position
    Robot1->Move(ROW, COL);        //tells the player instance to change its position
    
    FindTile(grid, ROW, COL, Player1); //goes through the array and finds the right tile to occupy
    FindTile(grid, ROW, COL, Robot1); //goes through the array and finds the right tile to occupy
    DispMap(grid, ROW, COL);
    
    Player1->Move(ROW, COL);        //tells the player instance to change its position
    Robot1->Move(ROW, COL);        //tells the player instance to change its position
    
    FindTile(grid, ROW, COL, Player1); //goes through the array and finds the right tile to occupy
    FindTile(grid, ROW, COL, Robot1); //goes through the array and finds the right tile to occupy
    DispMap(grid, ROW, COL);
    
    Player1->Move(ROW, COL);        //tells the player instance to change its position
    Robot1->Move(ROW, COL);        //tells the player instance to change its position
    
    FindTile(grid, ROW, COL, Player1); //goes through the array and finds the right tile to occupy
    FindTile(grid, ROW, COL, Robot1); //goes through the array and finds the right tile to occupy
    DispMap(grid, ROW, COL);
    
    
    return 0;
}
//Populate the array with tileobj instances
void Populate(tile grid[][10], const int &ROW, const int &COL){
    int tmp1, tmp2;
    tmp1 = rand() % ROW;
    tmp2 = rand() % COL;
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            grid[idx][ctr] = new TileObj(idx, ctr);
        }
    }
}
//Display the array of tileobj instances
void DispMap(tile grid[][10], const int &ROW, const int &COL){
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            grid[idx][ctr]->DispTile();
        }
        cout << endl;
    }
}
void FindTile(tile grid[][10], const int &ROW, const int &COL, Actor *c_Actor){
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            c_Actor->Occupy(grid[idx][ctr]);
        }
    }
}