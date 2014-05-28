//Define TileObj class members
//Libraries
#include <iostream>
#include <cstdlib>
#include "TileObj.h"
#include "Player.h"
//Function definitions
TileObj::TileObj(){     //default constructor for tile instance
    
}
TileObj::TileObj(short t_posx, short t_posy){   //creates a tile instance
    e_disp = '.';
    isSet = SetDisp(t_posx, t_posy);
}
TileObj::~TileObj(){            //destructor for tile instance
    //cleanup code here
}
void TileObj::DispTile(){        //displays the tile
    if(!isSet){
        cout << e_disp << " ";
    }
    else{
        if(isSet){
            cout << c_disp << " ";
        }
    }
}
bool TileObj::SetDisp(short t_posx, short t_posy){         //sets the tile display character
    posx = t_posx;
    posy = t_posy;
    return false;
}
short TileObj::x_Coord(){        //returns the coordinate to compare against;
    return posx;
}
short TileObj::y_Coord(){        //returns the coordinate to compare against;
    return posy;
}