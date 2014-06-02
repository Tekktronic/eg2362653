/* 
 * FILE: Robot.h
 * NAME: Ezra Guinmapang
 * DATE: June 2, 2014, 5:46 AM
 * PURPOSE: Defines the Robot class, derived from the Actor base class
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include "TileObj.h"
#include "Actor.h"
using namespace std;
typedef TileObj *tile;

#ifndef ROBOT_H
#define	ROBOT_H

class Robot: public Actor{
    private:
        bool isAlive;                   //Robot's state
        string P_Name;                  //Robot's name
        char c_ID;                      //stores the unique character representing the player instance
        tile t_obj;                     //pointer to a tile instance
    public:
        Robot();               //default constructor for player instance
        Robot(int, int);
        Robot(tile[][10], const int&, const int&, string, int, int);         //constructor for player instance
        ~Robot();              //destructor for player instance
        void Occupy(tile);           //occupy a tile
        bool Move(const int&, const int&);            //move the player instance to another tile
        bool Initialize(tile[][10], const int&, const int&); //sets the initial position of the player instance

};

#endif	/* ROBOT_H */