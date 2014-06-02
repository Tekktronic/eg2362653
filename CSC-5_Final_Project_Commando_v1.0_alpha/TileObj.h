/* 
 * FILE: TileObj.h
 * NAME: Ezra Guinmapang
 * DATE: May 24, 2014, 11:41 PM
 * PURPOSE: Defines the TileObj class
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
        int posx, posy;  //set to store the coordinates which objects need to link to
        bool isSet;      //if true, display this tile, otherwise display empty tile
    protected:

        int s_Coord(int&, int&); //set the coordinates of the instance
    public:
        TileObj();              //default constructor for the tile instance
        TileObj(int&, int&);  //creates a tile object at coordinates specified
        ~TileObj();             //destructor for tile instance
        char DispTile();        //display the tile
        int get_X();            //return posx
        int get_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
};

#endif	/* TILEOBJ_H */