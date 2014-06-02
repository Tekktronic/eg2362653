/* 
 * FILE: Player.h
 * NAME: Ezra Guinmapang
 * DATE: June 2, 2014, 5:46 AM
 * PURPOSE: Defines the Player class, derived from the Actor base class
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include "TileObj.h"
#include "Actor.h"
using namespace std;
typedef TileObj *tile;

#ifndef PLAYER_H
#define	PLAYER_H

class Player: public Actor{
    private:
        bool isAlive;                   //Player's state
        string P_Name;                  //Player's name
        char c_ID;                      //stores the unique character representing the player instance
        tile t_obj;                     //pointer to a tile instance
    public:
        Player();               //default constructor for player instance
        Player(int, int);
        Player(tile[][10], const int&, const int&, string, int, int);         //constructor for player instance
        ~Player();              //destructor for player instance
        void Occupy(tile);           //occupy a tile
        bool Move(const int&, const int&);            //move the player instance to another tile
        bool Initialize(tile[][10], const int&, const int&); //sets the initial position of the player instance
};

#endif /* PLAYER_H */