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
#include <fstream>
using namespace std;
class T_Type;
class TileObj;
typedef TileObj *tile;
//Class definitions
//TileObj class: this is the mediator class. This class should act as the interface
//for all the different classes. This adds a layer of interconnectivity between objects
//without interdependence.
class TileObj{
    protected:
        T_Type *c_tile;         //current terrain tile
        T_Type *c_item;         //curent item tile
        T_Type *c_obst;         //current obstacle tile
        char e_disp;        //stores the default empty tile display
        char c_disp, p_disp;  //stores the current tile  & previous tile display
        int posx, posy;  //set to store the coordinates which objects need to link to
        bool isSet;      //if true, display this tile, otherwise display empty tile
        bool isPass;     //if true, the tile may be occupied by an Actor
        bool isBreak;    //if true, the tile is breakable by an Actor
        bool isItem;     //if true, the tile may be picked up by an Actor
        bool isLock;     //if true, the tile may be opened by an Actor, using an Item
        int s_Coord(int&, int&); //set the coordinates of the instance
    public:
        TileObj();              //default constructor for the tile instance
        TileObj(int&, int&, int, int);  //creates a tile object at coordinates specified
        ~TileObj();             //destructor for tile instance
        virtual char DispTile();        //display the tile
        virtual int ret_X();            //return posx
        virtual int ret_Y();            //return posy
        virtual bool Match(int, int);   //match coordinates of tile to appropriate object
        virtual void SetDisp(int, int, char);     //sets the display character for the current tile instance
        virtual void SetEmpty();        //sets the tile instance display to an empty tile
        virtual bool ret_Set();          //return isSet
        virtual bool ret_Itm();         //return isItem
        virtual bool ret_Lck();         //return isLock
        virtual bool ret_Brk();         //return isBreak
        virtual bool ret_Pass();        //return isPass
        T_Type *takeItm();//return item address?
};
class T_Type{
    protected:
        tile c_tile;            //pointer to a TileObj instance
        char e_disp;        //stores the default empty tile display
        char c_disp, p_disp;  //stores the current tile  & previous tile display
        int posx, posy;  //set to store the coordinates which objects need to link to
        bool isSet;      //if true, display this tile, otherwise display empty tile
        bool isPass;     //if true, the tile may be occupied by an Actor
        bool isBreak;    //if true, the tile is breakable by an Actor
        bool isItem;     //if true, the tile may be picked up by an Actor
        bool isLock;     //if true, the tile may be opened by an Actor, using an Item
        int s_Coord(int&, int&); //set the coordinates of the instance
    public:
        T_Type();              //default constructor for the tile instance
        T_Type(int&, int&, tile);  //creates a tile object at coordinates specified
        ~T_Type();             //destructor for tile instance
        virtual char DispTile();        //display the tile
        virtual int ret_X();            //return posx
        virtual int ret_Y();            //return posy
        virtual bool Match(int, int);   //match coordinates of tile to appropriate object
        virtual void SetDisp(int, int, char);     //sets the display character for the current tile instance
        virtual void SetEmpty();        //sets the tile instance display to an empty tile
        virtual char ret_ID();          //return c_ID
        virtual bool ret_Set();          //return isSet
        virtual bool ret_Itm();         //return isItem
        virtual bool ret_Lck();         //return isLock
        virtual bool ret_Brk();         //return isBreak
        virtual bool ret_Pass();        //return isPass
};
class E_Tile: public T_Type{   //derived class from base class T_Type
    private:
        
    public:
        E_Tile();              //default constructor for the empty tile instance
        E_Tile(int&, int&, tile);  //creates an empty tile object at coordinates specified
        ~E_Tile();             //destructor for empty tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class T_Tile: public T_Type{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        T_Tile();               //default constructor for boost tile instance
        T_Tile(int&, int&, tile);              //creates a boost tile instance at the coordinates specified
        ~T_Tile();              //destructor for boost tile instance
        virtual char DispTile();        //display the tile
        virtual int ret_X();            //return posx
        virtual int ret_Y();            //return posy
        virtual bool Match(int, int);   //match coordinates of tile to appropriate object
        virtual void SetDisp(int, int, char);     //sets the display character for the current tile instance
        virtual void SetEmpty();        //sets the tile instance display to an empty tile
        virtual char ret_ID();          //return c_ID
        virtual bool ret_Set();          //return isSet
        virtual bool ret_Itm();         //return isItem
        virtual bool ret_Lck();         //return isLock
        virtual bool ret_Brk();         //return isBreak
        virtual bool ret_Pass();        //return isPass
};
class T_Mtn: public T_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        T_Mtn();               //default constructor for empty tile
        T_Mtn(int&, int&, tile);      //creates an terrain tile object at coordinates specified
        ~T_Mtn();              //destructor for terrain tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class T_Wet: public T_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        T_Wet();               //default constructor for empty tile
        T_Wet(int&, int&, tile);      //creates an terrain tile object at coordinates specified
        ~T_Wet();              //destructor for terrain tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class T_Grnd: public T_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        T_Grnd();               //default constructor for empty tile
        T_Grnd(int&, int&, tile);      //creates an terrain tile object at coordinates specified
        ~T_Grnd();              //destructor for terrain tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class B_Tile: public T_Type{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        B_Tile();               //default constructor for boost tile instance
        B_Tile(int&, int&, tile);              //creates a boost tile instance at the coordinates specified
        ~B_Tile();              //destructor for boost tile instance
        virtual char DispTile();        //display the tile
        virtual int ret_X();            //return posx
        virtual int ret_Y();            //return posy
        virtual bool Match(int, int);   //match coordinates of tile to appropriate object
        virtual void SetDisp(int, int, char);     //sets the display character for the current tile instance
        virtual void SetEmpty();        //sets the tile instance display to an empty tile
        virtual char ret_ID();          //return c_ID
        virtual bool ret_Set();          //return isSet
        virtual bool ret_Itm();         //return isItem
        virtual bool ret_Lck();         //return isLock
        virtual bool ret_Brk();         //return isBreak
        virtual bool ret_Pass();        //return isPass
};
class B_Bomb: public B_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        B_Bomb();               //default constructor for boost tile instance
        B_Bomb(int&, int&, tile);              //creates a boost tile instance at the coordinates specified
        ~B_Bomb();              //destructor for boost tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class B_Tport: public B_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        B_Tport();               //default constructor for boost tile instance
        B_Tport(int&, int&, tile);              //creates a boost tile instance at the coordinates specified
        ~B_Tport();              //destructor for boost tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class B_Wep: public B_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        B_Wep();               //default constructor for boost tile instance
        B_Wep(int&, int&, tile);              //creates a boost tile instance at the coordinates specified
        ~B_Wep();              //destructor for boost tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class O_Tile: public T_Type{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        O_Tile();               //default constructor for obstacle tile instance
        O_Tile(int&, int&, tile);     //creates an obstacle tile instance at the coordinates specified
        ~O_Tile();              //destructor for the obstacle tile instance
        virtual char DispTile();        //display the tile
        virtual int ret_X();            //return posx
        virtual int ret_Y();            //return posy
        virtual bool Match(int, int);   //match coordinates of tile to appropriate object
        virtual void SetDisp(int, int, char);     //sets the display character for the current tile instance
        virtual void SetEmpty();        //sets the tile instance display to an empty tile
        virtual char ret_ID();          //return c_ID
        virtual bool ret_Set();          //return isSet
        virtual bool ret_Itm();         //return isItem
        virtual bool ret_Lck();         //return isLock
        virtual bool ret_Brk();         //return isBreak
        virtual bool ret_Pass();        //return isPass
};
class O_Door: public O_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        O_Door();               //default constructor for obstacle tile instance
        O_Door(int&, int&, tile);     //creates an obstacle tile instance at the coordinates specified
        ~O_Door();              //destructor for the obstacle tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class O_Rock: public O_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        O_Rock();               //default constructor for obstacle tile instance
        O_Rock(int&, int&, tile);     //creates an obstacle tile instance at the coordinates specified
        ~O_Rock();              //destructor for the obstacle tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class O_Fnce: public O_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        O_Fnce();               //default constructor for obstacle tile instance
        O_Fnce(int&, int&, tile);     //creates an obstacle tile instance at the coordinates specified
        ~O_Fnce();              //destructor for the obstacle tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
class O_Wall: public O_Tile{
    private:
        int delay;      //if the tile is passable, delay the Actor for this many turns
    protected:
        
    public:
        O_Wall();               //default constructor for obstacle tile instance
        O_Wall(int&, int&, tile);     //creates an obstacle tile instance at the coordinates specified
        ~O_Wall();              //destructor for the obstacle tile instance
        char DispTile();        //display the tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool Match(int, int);   //match coordinates of tile to appropriate object
        void SetDisp(int, int, char);     //sets the display character for the current tile instance
        void SetEmpty();        //sets the tile instance display to an empty tile
        char ret_ID();          //return c_ID
        bool ret_Set();          //return isSet
        bool ret_Itm();         //return isItem
        bool ret_Lck();         //return isLock
        bool ret_Brk();         //return isBreak
        bool ret_Pass();        //return isPass
};
//typedef TileObj *tile;
class Actor{
    protected:
        int posx, posy;         //stores the x- and the y-coordinates as integers
    public:
        Actor();                //default constructor for actor instance
        Actor(int, int);                //default constructor for actor instance
        ~Actor();               //destructor for actor instance
        virtual tile FindTile(tile**, int&, int&, Actor*) = 0;        //find a match in the tile object array
        virtual void Occupy(tile**, int&, int&); //virtual function to override
        virtual bool Move(tile**, int&, int&);    //virtual function to override
        virtual int ret_X();            //virtual function to override
        virtual int ret_Y();            //virtual function to override
};
class Player: public Actor{
    private:
        bool isAlive;                   //Player's state
        string p_Name;                  //Player's name
        char c_ID;                      //stores the unique character representing the player instance
        tile t_obj;                     //pointer to a tile instance
        vector<T_Type*> i_list;         //vector of pointers to items
    public:
        Player();               //default constructor for player instance
        Player(tile**, int&, int&, string, int, int);         //constructor for player instance
        ~Player();              //destructor for player instance
        tile FindTile(tile**, int&, int&, Actor*);        //find a match in the tile object array
        void Occupy(tile**, int&, int&);           //occupy a tile
        bool Move(tile**, int&, int&);            //move the player instance to another tile
        bool GetItem();
        bool UseItem();
        bool Shoot();
        int ret_X();            //return posx
        int ret_Y();            //return posy
        bool ret_St();
};
class Robot: public Actor{
    private:
        bool isAlive;                   //Robot's state
        string p_Name;                  //Robot's name
        char c_ID;                      //stores the unique character representing the player instance
        tile t_obj;                     //pointer to a tile instance
    public:
        Robot();               //default constructor for player instance
        Robot(int, int);
        Robot(tile**, int&, int&, string, int, int);         //constructor for player instance
        ~Robot();              //destructor for player instance
        tile FindTile(tile**, int&, int&, Actor*);        //find a match in the tile object array
        void Occupy(tile**, int&, int&);           //occupy a tile
        bool Move(tile**,int&, int&);            //move the player instance to another tile
        int ret_X();            //return posx
        int ret_Y();            //return posy
};
//Global variables and constants

//Function prototypes
void DispMap(tile**, int&, int&);    //display the map
tile **Populate(int&, int&);   //populate the map
void Destroy(tile**, int&, int&);   //delete the dynamic array
//Exection begins HERE
int main(int argc, char** argv) {
    //declare variables
    srand(static_cast<unsigned int>(time(0)));  //seed the random number generator
    int ROW = 20;         //row size
    int COL = 80;         //column size
    tile **grid;            //2D array of tileobj pointers
    grid = Populate(ROW, COL);       //populates the array with tileobj instances
    Player *Player1 = new Player(grid, ROW, COL, "EzTmp", 1, 1);        //create the player instance
    Player1->Occupy(grid, ROW, COL);
    Robot *Robot1 = new Robot(grid, ROW, COL, "R1", ROW-1, COL-1);      //create the robot instance
    Robot1->Occupy(grid, ROW, COL);
    DispMap(grid, ROW, COL);       //Display the initial grid
    for(int test = 0; test < 15; test++){
        Player1->Move(grid, ROW, COL);        //tells the player instance to change its position
        Robot1->Move(grid, ROW, COL);        //tells the player instance to change its position
        
        //FindTile(grid, ROW, COL, Player1); //goes through the array and finds the right tile to occupy
        Player1->Occupy(grid, ROW, COL);
        //FindTile(grid, ROW, COL, Robot1); //goes through the array and finds the right tile to occupy
        Robot1->Occupy(grid, ROW, COL);
        DispMap(grid, ROW, COL);
    }
    //while(Player1->ret_St()) - put this back!!
    Destroy(grid, ROW, COL);
    delete Player1;
    delete Robot1;
    return 0;
}
//Populate the array with tileobj instances
tile **Populate(int &ROW, int &COL){
    fstream file1, file2;
    file1.open("mapgen.dat");
    file2.open("obstacles.dat");
    int tmp1, tmp2;
    float s_Rate = rand()%36/100.0f;     //stores the percentage of the map that is set as special tiles
    tmp2 = rand() % COL;
    tile **grid;
    grid = new tile*[ROW];
    for(int idx = 0; idx < ROW; idx++){
        grid[idx] = new tile[COL];
    }
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            file1 >> tmp1;
            file2 >> tmp2;
            grid[idx][ctr] = new TileObj(idx, ctr, tmp1, tmp2);
        }
    }
    file1.close();
    file2.close();
    return grid;
}
//Display the array of tileobj instances
void DispMap(tile **grid, int &ROW, int &COL){
    cout << "#########################################";
    cout << "#########################################" << endl;
    for(int idx = 0; idx < ROW; idx++){
        cout << "#";
        for(int ctr = 0; ctr < COL; ctr++){
            grid[idx][ctr]->DispTile();
        }
        cout << "#" << endl;
    }
    cout << "#########################################";
    cout << "#########################################" << endl;
}
//delete the dynamic array
void Destroy(tile **grid, int &ROW, int &COL){
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            delete grid[idx][ctr];
        }
        delete[] grid[COL];
    }
    delete[] grid[ROW];
}
Actor::Actor(){
    
}
Actor::Actor(int x_coord, int y_coord){
    posx = x_coord;
    posy = y_coord;
}
Actor::~Actor(){
    //clean-up code here
}
int Actor::ret_X(){
    return posx;
}
int Actor::ret_Y(){
    return posy;
}
tile Actor::FindTile(tile **grid, int &ROW, int &COL, Actor *c_Actor){      //find a match in the tile object array
    
}      //find a match in the tile object array
void Actor::Occupy(tile **grid, int &ROW, int &COL){
    
}
bool Actor::Move(tile**grid, int &ROW, int &COL){
    
}
Player::Player(){       //default constructor for Player instance
    
}
Player::Player(tile **grid, int &ROW, int &COL, string name, int x_coord, int y_coord):Actor(x_coord, y_coord){      //creates player object, located at (posx, posy))
    p_Name = name;
    isAlive = true;
    c_ID = '@';
    t_obj = FindTile(grid, ROW, COL, this);
}
Player::~Player(){      //destructor for the player instance

}
int Player::ret_X(){
    return posx;
}
int Player::ret_Y(){
    return posy;
}
tile Player::FindTile(tile **grid, int &ROW, int &COL, Actor *c_Actor){
    int x_coord = c_Actor->ret_X();
    int y_coord = c_Actor->ret_Y();
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            if(grid[idx][ctr]->Match(x_coord, y_coord)){
                return grid[idx][ctr];
            }
        }
    }
}
void Player::Occupy(tile **grid, int &ROW, int &COL){
        t_obj = FindTile(grid, ROW, COL, this);
        t_obj->SetDisp(posx, posy, c_ID);
}
bool Player::Move(tile **grid, int &ROW, int &COL){
    bool isValid = false;
    int ch_x;
    int ch_y;
    char p_in;          //player's directional input
    while(!isValid){
        ch_x = 0;
        ch_y = 0;
        cout << "Move the player: ";
        cin.get(p_in);
        switch(p_in){
            case 'w':{
                if(posx > 0){
                    ch_x = -1;
                    isValid = true;
                }
                break;
            }
            case 'a':{
                if(posy > 0){
                    ch_y = -1;
                    isValid = true;
                }
                break;
            }
            case 's':{
                if(posx < ROW-1){
                    ch_x = 1;
                    isValid = true;
                }
                break;
            }
            case 'd':{
                if(posy < COL-1){
                    ch_y = 1;
                    isValid = true;
                }
                break;
            }
            case 'q':{
                if(posx > 0 && posy > 0){
                    ch_x = -1;
                    ch_y = -1;
                    isValid = true;
                }
                break;
            }
            case 'e':{
                if(posx > 0 && posy < COL-1){
                    ch_x = -1;
                    ch_y = 1;
                    isValid = true;
                }
                break;
            }
            case 'z':{
                if(posx < ROW-1 && posy > 0){
                    ch_x = 1;
                    ch_y = -1;
                    isValid = true;
                }
                break;
            }
            case 'c':{
                if(posx < ROW-1 && posy < COL-1){
                    ch_x = 1;
                    ch_y = 1;
                    isValid = true;
                }
                break;
            }
            default: cout << "Invalid input! Try again.\n";
        }
        cin.ignore();
        tile nxt_obj;
        nxt_obj = *(*(grid+(posx+ch_x))+(posy+ch_y));    //peeks at the next tile to see if it is passable
        if(nxt_obj->ret_Pass()){
            t_obj->SetEmpty();
            posx += ch_x;
            posy += ch_y;
            if(nxt_obj->ret_Itm()){
                i_list.push_back(nxt_obj->takeItm());        //places the item pointer in the inventory
            }
            Occupy(grid, ROW, COL);
        }
        else isValid = false;
    }
}
bool Player::ret_St(){
    return isAlive;
}
Robot::Robot(){       //default constructor for Robot instance
    
}
Robot::Robot(int x_coord, int y_coord){
    posx = x_coord;
    posy = y_coord;
}
Robot::Robot(tile **grid, int &ROW, int &COL, string name, int x_coord, int y_coord):Actor(x_coord, y_coord){      //creates player object, located at (posx, posy))
    p_Name = name;
    c_ID = '?';
    t_obj = FindTile(grid, ROW, COL, this);
}
Robot::~Robot(){      //destructor for the player instance
    //cleanup code here
}
int Robot::ret_X(){
    return posx;
}
int Robot::ret_Y(){
    return posy;
}
tile Robot::FindTile(tile **grid, int &ROW, int &COL, Actor *c_Actor){
    int x_coord = c_Actor->ret_X();
    int y_coord = c_Actor->ret_Y();
    for(int idx = 0; idx < ROW; idx++){
        for(int ctr = 0; ctr < COL; ctr++){
            if(grid[idx][ctr]->Match(x_coord, y_coord)){
                return *(*(grid+idx)+ctr);
            }
        }
    }
}
void Robot::Occupy(tile **grid, int &ROW, int &COL){
        t_obj = FindTile(grid, ROW, COL, this);
        t_obj->SetDisp(posx, posy, c_ID);
}
bool Robot::Move(tile **grid, int &ROW, int &COL){
    t_obj->SetEmpty();
    bool isValid = false;
    int move; 
    while(!isValid){
        int ch_x = 0, ch_y = 0;
        move = (rand()%8) + 1;          //generate the random movement of the Robot
        switch(move){
            case 1:{
                if(posx > 0){
                    ch_x = -1;
                    isValid = true;
                }
                break;
            }
            case 2:{
                if(posy > 0){
                    ch_y = -1;
                    isValid = true;
                }
                break;
            }
            case 3:{
                if(posx < ROW-1){
                    ch_x = 1;
                    isValid = true;
                }
                break;
            }
            case 4:{
                if(posy < COL-1){
                    ch_y = 1;
                    isValid = true;
                }
                break;
            }
            case 5:{
                if(posx > 0 && posy > 0){
                    ch_x = -1;
                    ch_y= -1;
                    isValid = true;
                }
                break;
            }
            case 6:{
                if(posx > 0 && posy < COL-1){
                    ch_x = -1;
                    ch_y = 1;
                    isValid = true;
                }
                break;
            }
            case 7:{
                if(posx < ROW-1 && posy > 0){
                    ch_x = 1;
                    ch_y = -1;
                    isValid = true;
                }
                break;
            }
            case 8:{
                if(posx < ROW-1 && posy < COL-1){
                     ch_x = 1;
                     ch_y = 1;
                     isValid = true;
                }
                break;
            }
            default: continue;
        }
        tile nxt_obj;
        nxt_obj = *(*(grid+(posx+ch_x))+(posy+ch_y));    //peeks at the next tile to see if it is not set
        if(nxt_obj->ret_Pass()){
            t_obj->SetEmpty();
            posx += ch_x;
            posy += ch_y;
            Occupy(grid, ROW, COL);
        }
        else isValid = false;
    }
}
//TileObj functions
TileObj::TileObj(){     //default constructor for tile instance
    
}
TileObj::TileObj(int &t_posx, int &t_posy, int id, int id2){   //creates a tile instance
    posx = t_posx;
    posy = t_posy;
    int tmp;
    //creates the appropriate tile type according to the map
    switch(id){
        case 0:{
            c_tile = new T_Grnd(posx, posy, this);
            break;
        }
        case 1:{
            c_tile = new T_Mtn(posx, posy, this);
            break;
        }
        case 2:{
            c_tile = new T_Wet(posx, posy, this);
            break;
        }
        default: break; //shouldn''t reach this!
    }
    switch(id2){
        case 0:{
            c_obst = 0;
            break;
        }
        case 1:{
            c_obst = new O_Wall(posx, posy, this);
            
            break;
        }
        case 2:{
            c_obst = new O_Door(posx, posy, this);
            break;
        }
        case 3:{
            c_obst = new O_Fnce(posx, posy, this); break;
        }
        case 4:{
            c_obst = new O_Rock(posx, posy, this); break;
        }
        default: break; //shouldn't reach this!
    }
    //generate the obstacle at this tile
    //set the TileObj attributes to the appropriate values for the current tile type
    c_disp = c_tile->ret_ID();
    p_disp = c_disp;
    isSet = c_tile->ret_Set();
    if(c_obst != 0){
        c_disp = c_obst->ret_ID();
        isPass = c_obst->ret_Pass();
        switch(c_disp){
            case '/': isLock = c_obst->ret_Lck(); break;
            case '&': isBreak = c_obst->ret_Brk(); break;
        }
    }
    else{
        isLock = c_tile->ret_Lck();
        isPass = c_tile->ret_Pass();
        isBreak = c_tile->ret_Brk();
    }
    //generate the item at this tile
    tmp = rand() % 100;
    if(isPass){
        if(tmp == 0) c_item = new B_Bomb(posx, posy, this);
        else if(tmp == 1) c_item = new B_Tport(posx, posy, this);
        else if(tmp  == 2) c_item = new B_Wep(posx, posy, this);
    }
    else c_item = 0;
    if(c_item != 0){
        c_disp = c_item->ret_ID();
        isItem = c_item->ret_Itm();
    }
}
TileObj::~TileObj(){            //destructor for tile instance
    delete c_tile;
    delete c_item;
    delete c_obst;
}
char TileObj::DispTile(){       //returns the character to display
    cout << c_disp;
}
int TileObj::ret_X(){
    return posx;
}
int TileObj::ret_Y(){
    return posy;
}
bool TileObj::ret_Brk(){
    return isBreak;
}
bool TileObj::ret_Itm(){
    return isItem;
}
bool TileObj::ret_Lck(){
    return isLock;
}
bool TileObj::ret_Pass(){
    return isPass;
}
T_Type* TileObj::takeItm(){
    return c_item;
}
bool TileObj::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void TileObj::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void TileObj::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
bool TileObj::ret_Set(){
    return isSet;
}
//T_Type functions
T_Type::T_Type(){     //default constructor for tile instance
    
}
T_Type::T_Type(int &t_posx, int &t_posy, tile c_tile){   //creates a tile instance
    posx = t_posx;
    posy = t_posy;
}
T_Type::~T_Type(){            //destructor for tile instance
    //cleanup code here
}
char T_Type::DispTile(){       //returns the character to display
    cout << c_disp;
}
int T_Type::ret_X(){
    return posx;
}
int T_Type::ret_Y(){
    return posy;
}
bool T_Type::ret_Brk(){
    return isBreak;
}
bool T_Type::ret_Itm(){
    return isItem;
}
bool T_Type::ret_Lck(){
    return isLock;
}
bool T_Type::ret_Pass(){
    return isPass;
}
bool T_Type::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void T_Type::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void T_Type::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char T_Type::ret_ID(){
    return c_disp;
}
bool T_Type::ret_Set(){
    return isSet;
}
//E_Tile functions
E_Tile::E_Tile(){
    
}
E_Tile::E_Tile(int &t_posx, int &t_posy, tile c_tile):T_Type(t_posx, t_posy, c_tile){   //creates a tile instance
    e_disp = '.';
    c_disp = e_disp;
    isSet = false;
    isPass = false;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
E_Tile::~E_Tile(){            //destructor for tile instance
    //cleanup code here
}
char E_Tile::DispTile(){       //returns the character to display
    cout << c_disp;
}
int E_Tile::ret_X(){
    return posx;
}
int E_Tile::ret_Y(){
    return posy;
}
bool E_Tile::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void E_Tile::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void E_Tile::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char E_Tile::ret_ID(){
    return c_disp;
}
bool E_Tile::ret_Set(){
    return isSet;
}
bool E_Tile::ret_Brk(){
    return isBreak;
}
bool E_Tile::ret_Itm(){
    return isItem;
}
bool E_Tile::ret_Lck(){
    return isLock;
}
bool E_Tile::ret_Pass(){
    return isPass;
}
//T_Tile functions
T_Tile::T_Tile(){     //default constructor for tile instance
    
}
T_Tile::T_Tile(int &t_posx, int &t_posy, tile c_tile):T_Type(t_posx, t_posy, c_tile){   //creates a tile instance
    e_disp = ',';
    c_disp = e_disp;
    isSet = false;
}
T_Tile::~T_Tile(){            //destructor for tile instance
    //cleanup code here
}
char T_Tile::DispTile(){       //returns the character to display
    cout << c_disp;
}
int T_Tile::ret_X(){
    return posx;
}
int T_Tile::ret_Y(){
    return posy;
}
bool T_Tile::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void T_Tile::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void T_Tile::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char T_Tile::ret_ID(){
    return c_disp;
}
bool T_Tile::ret_Set(){
    return isSet;
}
bool T_Tile::ret_Brk(){
    return isBreak;
}
bool T_Tile::ret_Itm(){
    return isItem;
}
bool T_Tile::ret_Lck(){
    return isLock;
}
bool T_Tile::ret_Pass(){
    return isPass;
}
//T_Mtn functions
T_Mtn::T_Mtn(){     //default constructor for tile instance
    
}
T_Mtn::T_Mtn(int &t_posx, int &t_posy, tile c_tile): T_Tile(t_posx, t_posy, c_tile){   //creates a tile instance
    delay = 3;
    c_disp = 'M';
    p_disp = c_disp;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
T_Mtn::~T_Mtn(){            //destructor for tile instance
    //cleanup code here
}
char T_Mtn::DispTile(){       //returns the character to display
    cout << c_disp;
}
int T_Mtn::ret_X(){
    return posx;
}
int T_Mtn::ret_Y(){
    return posy;
}
bool T_Mtn::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void T_Mtn::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void T_Mtn::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char T_Mtn::ret_ID(){
    return c_disp;
}
bool T_Mtn::ret_Set(){
    return isSet;
}
bool T_Mtn::ret_Brk(){
    return isBreak;
}
bool T_Mtn::ret_Itm(){
    return isItem;
}
bool T_Mtn::ret_Lck(){
    return isLock;
}
bool T_Mtn::ret_Pass(){
    return isPass;
}
//T_Wet functions
T_Wet::T_Wet(){     //default constructor for tile instance
    
}
T_Wet::T_Wet(int &t_posx, int &t_posy, tile c_tile):T_Tile(t_posx, t_posy, c_tile){   //creates a tile instance
    delay = 2;
    c_disp = '~';
    p_disp = c_disp;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
T_Wet::~T_Wet(){            //destructor for tile instance
    //cleanup code here
}
char T_Wet::DispTile(){       //returns the character to display
    cout << c_disp;
}
int T_Wet::ret_X(){
    return posx;
}
int T_Wet::ret_Y(){
    return posy;
}
bool T_Wet::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void T_Wet::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void T_Wet::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char T_Wet::ret_ID(){
    return c_disp;
}
bool T_Wet::ret_Set(){
    return isSet;
}
bool T_Wet::ret_Brk(){
    return isBreak;
}
bool T_Wet::ret_Itm(){
    return isItem;
}
bool T_Wet::ret_Lck(){
    return isLock;
}
bool T_Wet::ret_Pass(){
    return isPass;
}
//T_Grnd functions
T_Grnd::T_Grnd(){     //default constructor for tile instance
    
}
T_Grnd::T_Grnd(int &t_posx, int &t_posy, tile c_tile):T_Tile(t_posx, t_posy, c_tile){   //creates a tile instance
    c_disp = ',';
    p_disp = c_disp;
    isSet = true;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
T_Grnd::~T_Grnd(){            //destructor for tile instance
    //cleanup code here
}
char T_Grnd::DispTile(){       //returns the character to display
    cout << c_disp;
}
int T_Grnd::ret_X(){
    return posx;
}
int T_Grnd::ret_Y(){
    return posy;
}
bool T_Grnd::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void T_Grnd::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void T_Grnd::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char T_Grnd::ret_ID(){
    return c_disp;
}
bool T_Grnd::ret_Set(){
    return isSet;
}
bool T_Grnd::ret_Brk(){
    return isBreak;
}
bool T_Grnd::ret_Itm(){
    return isItem;
}
bool T_Grnd::ret_Lck(){
    return isLock;
}
bool T_Grnd::ret_Pass(){
    return isPass;
}
//B_Tile functions
B_Tile::B_Tile(){     //default constructor for tile instance
    
}
B_Tile::B_Tile(int &t_posx, int &t_posy, tile c_tile):T_Type(t_posx, t_posy, c_tile){   //creates a tile instance
    e_disp = '^';
    c_disp = e_disp;
    isSet = true;
}
B_Tile::~B_Tile(){            //destructor for tile instance
    //cleanup code here
}
char B_Tile::DispTile(){       //returns the character to display
    cout << c_disp;
}
int B_Tile::ret_X(){
    return posx;
}
int B_Tile::ret_Y(){
    return posy;
}
bool B_Tile::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void B_Tile::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void B_Tile::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char B_Tile::ret_ID(){
    return c_disp;
}
bool B_Tile::ret_Set(){
    return isSet;
}
bool B_Tile::ret_Brk(){
    return isBreak;
}
bool B_Tile::ret_Itm(){
    return isItem;
}
bool B_Tile::ret_Lck(){
    return isLock;
}
bool B_Tile::ret_Pass(){
    return isPass;
}
//B_Bomb functions
B_Bomb::B_Bomb(){     //default constructor for tile instance
    
}
B_Bomb::B_Bomb(int &t_posx, int &t_posy, tile c_tile):B_Tile(t_posx, t_posy, c_tile){   //creates a tile instance
    delay = 5;
    c_disp = 'B';
    p_disp = c_disp;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = true;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
B_Bomb::~B_Bomb(){            //destructor for tile instance
    //cleanup code here
}
char B_Bomb::DispTile(){       //returns the character to display
    cout << c_disp;
}
int B_Bomb::ret_X(){
    return posx;
}
int B_Bomb::ret_Y(){
    return posy;
}
bool B_Bomb::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void B_Bomb::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void B_Bomb::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char B_Bomb::ret_ID(){
    return c_disp;
}
bool B_Bomb::ret_Set(){
    return isSet;
}
bool B_Bomb::ret_Brk(){
    return isBreak;
}
bool B_Bomb::ret_Itm(){
    return isItem;
}
bool B_Bomb::ret_Lck(){
    return isLock;
}
bool B_Bomb::ret_Pass(){
    return isPass;
}
//B_Tport functions
B_Tport::B_Tport(){     //default constructor for tile instance
    
}
B_Tport::B_Tport(int &t_posx, int &t_posy, tile c_tile):B_Tile(t_posx, t_posy, c_tile){   //creates a tile instance
    delay = 0;
    c_disp = '%';
    p_disp = c_disp;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = true;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
B_Tport::~B_Tport(){            //destructor for tile instance
    //cleanup code here
}
char B_Tport::DispTile(){       //returns the character to display
    cout << c_disp;
}
int B_Tport::ret_X(){
    return posx;
}
int B_Tport::ret_Y(){
    return posy;
}
bool B_Tport::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void B_Tport::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void B_Tport::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char B_Tport::ret_ID(){
    return c_disp;
}
bool B_Tport::ret_Set(){
    return isSet;
}
bool B_Tport::ret_Brk(){
    return isBreak;
}
bool B_Tport::ret_Itm(){
    return isItem;
}
bool B_Tport::ret_Lck(){
    return isLock;
}
bool B_Tport::ret_Pass(){
    return isPass;
}
//B_Wep functions
B_Wep::B_Wep(){     //default constructor for tile instance
    
}
B_Wep::B_Wep(int &t_posx, int &t_posy, tile c_tile):B_Tile(t_posx, t_posy, c_tile){   //creates a tile instance
    delay = 0;
    c_disp = ']';
    p_disp = c_disp;
    isPass = true;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = true;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
B_Wep::~B_Wep(){            //destructor for tile instance
    //cleanup code here
}
char B_Wep::DispTile(){       //returns the character to display
    cout << c_disp;
}
int B_Wep::ret_X(){
    return posx;
}
int B_Wep::ret_Y(){
    return posy;
}
bool B_Wep::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void B_Wep::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void B_Wep::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char B_Wep::ret_ID(){
    return c_disp;
}
bool B_Wep::ret_Set(){
    return isSet;
}
bool B_Wep::ret_Brk(){
    return isBreak;
}
bool B_Wep::ret_Itm(){
    return isItem;
}
bool B_Wep::ret_Lck(){
    return isLock;
}
bool B_Wep::ret_Pass(){
    return isPass;
}
//O_Tile functions
O_Tile::O_Tile(){     //default constructor for tile instance
    
}
O_Tile::O_Tile(int &t_posx, int &t_posy, tile c_tile): T_Type(t_posx, t_posy, c_tile){   //creates a tile instance
    e_disp = '.';
    c_disp = e_disp;
    isSet = true;
}
O_Tile::~O_Tile(){            //destructor for tile instance
    //cleanup code here
}
char O_Tile::DispTile(){       //returns the character to display
    cout << c_disp;
}
int O_Tile::ret_X(){
    return posx;
}
int O_Tile::ret_Y(){
    return posy;
}
bool O_Tile::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void O_Tile::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void O_Tile::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char O_Tile::ret_ID(){
    return c_disp;
}
bool O_Tile::ret_Set(){
    return isSet;
}
bool O_Tile::ret_Brk(){
    return isBreak;
}
bool O_Tile::ret_Itm(){
    return isItem;
}
bool O_Tile::ret_Lck(){
    return isLock;
}
bool O_Tile::ret_Pass(){
    return isPass;
}
//O_Door functions
O_Door::O_Door(){     //default constructor for tile instance
    
}
O_Door::O_Door(int &t_posx, int &t_posy, tile c_tile): O_Tile(t_posx, t_posy, c_tile){   //creates a tile instance
    delay = 0;
    c_disp = '/';
    p_disp = c_disp;
    isPass = false;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = true;     //if true, the tile may be opened by an Actor, using an Item
}
O_Door::~O_Door(){            //destructor for tile instance
    //cleanup code here
}
char O_Door::DispTile(){       //returns the character to display
    cout << c_disp;
}
int O_Door::ret_X(){
    return posx;
}
int O_Door::ret_Y(){
    return posy;
}
bool O_Door::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void O_Door::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void O_Door::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char O_Door::ret_ID(){
    return c_disp;
}
bool O_Door::ret_Set(){
    return isSet;
}
bool O_Door::ret_Brk(){
    return isBreak;
}
bool O_Door::ret_Itm(){
    return isItem;
}
bool O_Door::ret_Lck(){
    return isLock;
}
bool O_Door::ret_Pass(){
    return isPass;
}
//O_Rock functions
O_Rock::O_Rock(){     //default constructor for tile instance
    
}
O_Rock::O_Rock(int &t_posx, int &t_posy, tile c_tile): O_Tile(t_posx, t_posy, c_tile){   //creates a tile instance
    c_disp = '&';
    p_disp = c_disp;
    isPass = false;     //if true, the tile may be occupied by an Actor
    isBreak = true;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
O_Rock::~O_Rock(){            //destructor for tile instance
    //cleanup code here
}
char O_Rock::DispTile(){       //returns the character to display
    cout << c_disp;
}
int O_Rock::ret_X(){
    return posx;
}
int O_Rock::ret_Y(){
    return posy;
}
bool O_Rock::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void O_Rock::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void O_Rock::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char O_Rock::ret_ID(){
    return c_disp;
}
bool O_Rock::ret_Set(){
    return isSet;
}
bool O_Rock::ret_Brk(){
    return isBreak;
}
bool O_Rock::ret_Itm(){
    return isItem;
}
bool O_Rock::ret_Lck(){
    return isLock;
}
bool O_Rock::ret_Pass(){
    return isPass;
}
//O_Fnce functions
O_Fnce::O_Fnce(){     //default constructor for tile instance
    
}
O_Fnce::O_Fnce(int &t_posx, int &t_posy, tile c_tile): O_Tile(t_posx, t_posy, c_tile){   //creates a tile instance
    c_disp = '$';
    p_disp = c_disp;
    isPass = false;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
O_Fnce::~O_Fnce(){            //destructor for tile instance
    //cleanup code here
}
char O_Fnce::DispTile(){       //returns the character to display
    cout << c_disp;
}
int O_Fnce::ret_X(){
    return posx;
}
int O_Fnce::ret_Y(){
    return posy;
}
bool O_Fnce::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void O_Fnce::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void O_Fnce::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char O_Fnce::ret_ID(){
    return c_disp;
}
bool O_Fnce::ret_Set(){
    return isSet;
}
bool O_Fnce::ret_Brk(){
    return isBreak;
}
bool O_Fnce::ret_Itm(){
    return isItem;
}
bool O_Fnce::ret_Lck(){
    return isLock;
}
bool O_Fnce::ret_Pass(){
    return isPass;
}
//O_Wall functions
O_Wall::O_Wall(){     //default constructor for tile instance
    
}
O_Wall::O_Wall(int &t_posx, int &t_posy, tile c_tile): O_Tile(t_posx, t_posy, c_tile){   //creates a tile instance
    c_disp = '#';
    p_disp = c_disp;
    isSet = false;
    isPass = false;     //if true, the tile may be occupied by an Actor
    isBreak = false;    //if true, the tile is breakable by an Actor
    isItem = false;     //if true, the tile may be picked up by an Actor
    isLock = false;     //if true, the tile may be opened by an Actor, using an Item
}
O_Wall::~O_Wall(){            //destructor for tile instance
    //cleanup code here
}
char O_Wall::DispTile(){       //returns the character to display
    cout << c_disp;
}
int O_Wall::ret_X(){
    return posx;
}
int O_Wall::ret_Y(){
    return posy;
}
bool O_Wall::Match(int x_coord, int y_coord){
    bool isMatch = false;
    if(posx == x_coord && posy == y_coord) isMatch = true;
    return isMatch;
}
void O_Wall::SetDisp(int x_coord, int y_coord, char objID){
    if(x_coord == posx && y_coord == posy){
        c_disp = objID;
    }
}
void O_Wall::SetEmpty(){
    isSet = false;
    c_disp = p_disp;
}
char O_Wall::ret_ID(){
    return c_disp;
}
bool O_Wall::ret_Set(){
    return isSet;
}
bool O_Wall::ret_Brk(){
    return isBreak;
}
bool O_Wall::ret_Itm(){
    return isItem;
}
bool O_Wall::ret_Lck(){
    return isLock;
}
bool O_Wall::ret_Pass(){
    return isPass;
}