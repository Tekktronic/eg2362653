/* 
 * File:   Player.h
 * Author: Ezra Guinmapang
 *
 * Created on April 28, 2014, 11:24 PM
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

#ifndef PLAYER_H
#define	PLAYER_H

class Player{
    private:
        bool isAlive;                   //Player's state
        string P_Name;                  //Player's name
        short posx, posy;               //stores the x- and the y-coordinates as integers
        char c_ID;                      //stores the unique character representing the player instance
    public:
        Player();               //default constructor for player instance
        Player(string, short, short);         //constructor for player instance
        ~Player();              //destructor for player instance
        char Occupy(short, short, bool &);        //returns the position of the Player to the map
        
};

#endif	/* PLAYER_H */

