/* 
 * File:   TileObj.h
 * Author: tekktronic
 *
 * Created on May 24, 2014, 11:41 PM
 */

//Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef TILEOBJ_H
#define	TILEOBJ_H

class TileObj{
    private:
        char e_disp;        //stores the default empty tile display
        char c_disp, p_disp;  //stores the current tile  & previous tile display
        short posx, posy;  //set to store the coordinates which objects need to link to
        bool isSet;      //if true, display this tile, otherwise display empty tile
        TileObj *tile;  //pointer to tile instance
    protected:
        short s_Coord(short &); //set the coordinates of the instance
    public:
        TileObj();              //default constructor for the tile instance
        TileObj(short, short);  //creates a tile object at coordinates specified
        ~TileObj();             //destructor for tile instance
        void DispTile();        //displays the tile
        bool SetDisp(short, short);         //sets the tile display character
        short x_Coord();        //returns the coordinate to compare against;
        short y_Coord();        //returns the coordinate to compare against;
};

#endif	/* TILEOBJ_H */