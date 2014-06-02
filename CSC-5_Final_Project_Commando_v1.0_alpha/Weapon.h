/* 
 * File:   Ship.h
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

#ifndef WEAPON_H
#define	WEAPON_H

class Weapon{
    private:
        bool isEmpty;            //stores the status of the weapon
        bool isEq;              //stores whether the weapon is equipped or not
        short wepCT;             //quantity left of the weapon
        string w_Type;          //stores the type of weapon
        
    public:
        Weapon();                         //default constructor for the ship object
        Weapon(string);                   //constructor for the ship object
        ~Weapon();                        //destructor for the ship object
        bool Empty();                    //returns the status of a ship
        bool Equip();                 //returns the size of the vector holding the ship's placement coordinates
        short q_Left();                 //returns how much of the weapon is left to use
};

#endif	/* WEAPON_H */

