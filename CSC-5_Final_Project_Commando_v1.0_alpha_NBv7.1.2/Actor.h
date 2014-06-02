/* 
 * FILE: Actor.h
 * NAME: Ezra Guinmapang
 * DATE: May 24, 2014, 11:41 PM
 * PURPOSE: Defines the Actor class, base class for all non-stationary objects
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "TileObj.h"
using namespace std;
typedef TileObj* tile;
#ifndef ACTOR_H
#define	ACTOR_H

class Actor{
    protected:
        int posx, posy;         //stores the x- and the y-coordinates as integers
    public:
        Actor();                //default constructor for actor instance
        Actor(int, int);                //default constructor for actor instance
        ~Actor();               //destructor for actor instance
        virtual void Occupy(tile) = 0; //virtual function to override
        virtual bool Move();    //virtual function to override
};

#endif	/* ACTOR_H */

