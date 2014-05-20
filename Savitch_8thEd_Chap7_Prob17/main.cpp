/* 
 * File:   main.cpp
 * Author: Ezra Guinmapang
 *
 * Created on May 19, 2014, 2:29 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

//Global variables and constants

//Function prototypes
void mainMenu();        //displays the main menu
bool getSched(ifstream &, char[][4], const int &, const int &); //get the currently loaded schedule
void printSched(char[][4], const int &, const int &, string &);   //print the currently loaded schedule
string loadSched(ifstream &, char[][4], const int &, const int &, const int &, char[], bool &); //open the appropriate schedule file
void editSched(ifstream &, char[][4], int &, int &, const int &, const int &, const int &, char[], bool &, bool &); //edit the appropriate schedule file
bool saveSched(ofstream &outfile, char sched[][4], const int &SLOT, const int &DAY, string &pName, bool &); //save the current schedule to file
char Command(ifstream &, ofstream &, char[][4], int &, int &, const int &, const int &, const int &, char[], string &, bool &, bool &); //run a command from the menu
//Execution begins HERE
int main(int argc, char** argv) {
    //declare variables
    const int SLOT = 4; //represents the time slot
    const int DAY = 4;  //represents the day of the week
    const int MAX_NAME = 20;    //maximum number of input characters
    char choice[MAX_NAME];      //holds the input characters
    string pName;       //holds the profile name
    char cmd;         //holds the command
    char sched[SLOT][DAY];      //holds the schedule array
    int t_slot = 0, c_day = 0;  //sets the counter variables to zero
    bool isSaved = false;       //set when a file is saved to disk
    bool isLoaded = false;      //set when a file is loaded
    //declare streams
    ifstream infile;    //input stream from file
    ofstream outfile;   //output stream to file
    mainMenu();
    do{
        cmd = Command(infile, outfile, sched, t_slot, c_day,
                SLOT, DAY, MAX_NAME, choice, pName, isSaved, isLoaded);
        if(toupper(cmd) == 'X' && !isSaved){
            cout << "File not saved. If you exit now, all changes will be lost.\n";
            cout << "Would you like to save the file(Y/N)? ";
            cin >> cmd;
            if(toupper(cmd) == 'Y') isSaved = saveSched(outfile, sched, SLOT, DAY, pName, isSaved);
            else cout << "Exit without saving(Y/N)? ";
            cin >> cmd;
            if(toupper(cmd) == 'Y') cmd = 'X';
        }
    }while(toupper(cmd) != 'X');    
    return 0;
}
bool saveSched(ofstream &outfile, char sched[][4], const int &SLOT, 
        const int &DAY, string &pName, bool &isSaved){
    char choice;
    bool isValid = false;
    if(pName == "Jeff"){
        outfile.open("sched_J_001.dat");
    }
    else if(pName == "Ann"){
        outfile.open("sched_E_001.dat");
    }
    cout << "WARNING! By choosing this option, your previous schedule profile will be overwritten.\n";
    while(!isValid){
        cout << "Save all changes(Y/N)? ";
        cin >> choice;
        switch(toupper(choice)){
            case 'Y':{
                for(int slotCT = 0; slotCT < SLOT; slotCT++){
                    for(int dayCT = 0; dayCT < DAY; dayCT++){
                        if(sched[slotCT][dayCT] != 'x') sched[slotCT][dayCT] = '.';
                        outfile << sched[slotCT][dayCT] << " ";
                    }
                    outfile << endl;
                }
                outfile.close();
                if(outfile.good()){
                    cout << "File saved.\n";
                    isValid = true;
                    return true;
                }
            }
            case 'N':{
                cout << "Exit without saving(Y/N)? ";
                cin >> choice;
                if(toupper(choice) == 'Y') return true;
                else if(toupper(choice) == 'N'){
                    cout << "Invalid input! Please try again.\n";
                    isValid = false;
                    break;
                }
            }
            default:{
                cout << "Invalid input! Please try again.\n";
            }
        }
    }
}
//fill the array with the schedule selected
bool getSched(ifstream &infile, char sched[][4], const int &SLOT, const int &DAY){
    for(int slotCT = 0; slotCT < SLOT && !infile.eof(); slotCT++){
        for(int dayCT = 0; dayCT < DAY && !infile.eof(); dayCT++){
            infile >> sched[slotCT][dayCT];
        }
    }
}
void printSched(char sched[][4], const int &SLOT, const int &DAY, string &pName){
    cout << "INSTRUCTOR NAME: " << pName << endl;
    cout << "         M T W Th\n";
    for(int slotCT = 0; slotCT < SLOT; slotCT++){
        switch(slotCT){
            case 0: cout << "1. 11-12 "; break;
            case 1: cout << "2. 12-1  "; break;
            case 2: cout << "3. 1-2   "; break;
            case 3: cout << "4. 2-3   "; break;
            default: cout << "ERR! "; //stub!
        }
        for(int dayCT = 0; dayCT < DAY; dayCT++){
            if(sched[slotCT][dayCT] == '.') sched[slotCT][dayCT] = ' ';
            cout << sched[slotCT][dayCT] << " ";
        }
        cout << endl;
    }
}
void mainMenu(){
    cout << "*** S C H E D U L E ***\n";
    cout << "*  Menu options:      *\n";
    cout << "*  A. Open a profile  *\n";
    cout << "*  V. View a profile  *\n";
    cout << "*  E. Edit a profile  *\n";
    cout << "*  S. Save profile    *\n";
    cout << "*  M. Display menu    *\n";
    cout << "***********************\n";
}
string loadSched(ifstream &infile, char sched[][4], const int &SLOT, 
        const int &DAY, const int &MAX_NAME, char choice[], bool &isLoaded){
    do{
        cout << "Enter the profile name to view: ";
        char fName[MAX_NAME];
        cin.get(choice, '\n');
        if(strncmp(choice, "Jeff", MAX_NAME) == 0){
            strncpy(fName, "sched_J_001.dat", MAX_NAME);
        }
        else if(strncmp(choice, "Ann", MAX_NAME) == 0){
            strncpy(fName, "sched_E_001.dat", MAX_NAME);
        }
        infile.open(fName);
        if(infile.good()){
            isLoaded = true;
        }
        else{
            isLoaded = false;
            infile.clear();
        }
    }while(!isLoaded);
    getSched(infile, sched, SLOT, DAY);
    infile.close();
    return choice;
}
void editSched(ifstream &infile, char sched[][4], int &t_slot, int &c_day, const int &SLOT, 
        const int &DAY, const int &MAX_NAME, char choice[], bool &isLoaded, bool &isSaved){
    bool isValid = false;
    while(!isLoaded){
        cout << "No profile is loaded for editing. Load profile(Y/N)? ";
        loadSched(infile, sched, SLOT, DAY, MAX_NAME, choice, isLoaded);
    }
    cout << "Enter your choice in <time_slot>:<day> format, where <time_slot> is\n";
    cout << "the number of the time slot desired, and <day> is the day desired,\n";
    cout << "separated by a colon ':'.\n";
    while(!isValid){
        cout << "Please choose a slot: ";
        cin >> choice;
        switch(choice[0]){
            case '1':{
                t_slot = 0;
                isValid = true;
                break;
            }
            case '2':{
                t_slot = 1;
                isValid = true;
                break;
            }
            case '3':{
                t_slot = 2;
                isValid = true;
                break;
            }
            case '4':{
                t_slot = 3;
                isValid = true;
                break;
            }
            default:{
                cout << "Invalid input. Please try again!\n";
                isValid = false;
                break;
            }
        }
        if(!isValid) continue;
        switch(toupper(choice[2])){
            case 'M':{
                c_day = 0; 
                isValid = true;
                break;
            }
            case 'T': {
                if(tolower(choice[3]) == 'h'){
                    c_day = 3;
                    isValid = true;
                    break;
                }
                else{
                    c_day = 1;
                    isValid = true;
                    break;
                }
            }
            case 'W':{
                c_day = 2; 
                isValid = true;
                break;
            }
            default:{
                cout << "Invalid input! Please try again.\n";
                isValid = false;
                break;
            }
        }
    }
    if(isspace(sched[t_slot][c_day])){
        cout << "That slot is available.\n";
        cout << "Would you like to add this time slot to the schedule(Y/N)? ";
        cin >> choice;
        if(toupper(choice[0]) == 'Y') sched[t_slot][c_day] = 'x';
    }
    else{
        cout << "That slot is occupied.\n";
        cout << "Would you like to remove this time slot from the schedule(Y/N)? ";
        cin >> choice;
        if(toupper(choice[0]) == 'Y') sched[t_slot][c_day] = ' ';
    }
}
char Command(ifstream &infile, ofstream &outfile, char sched[][4], int &t_slot, 
        int &c_day, const int &SLOT, const int &DAY, const int &MAX_NAME, 
        char choice[], string &pName, bool &isSaved, bool &isLoaded){
    cout << "Please enter your selection, or enter 'X' to quit: ";
    cin >> choice;
    cin.ignore();
    switch(toupper(choice[0])){
        case 'A':{
            pName = loadSched(infile, sched, SLOT, DAY, MAX_NAME, choice, isLoaded);
            printSched(sched, SLOT, DAY, pName);
            return 'A';
        }
        case 'V':{
            printSched(sched, SLOT, DAY, pName);
            return 'V';
        }
        case 'E':{
            editSched(infile, sched, t_slot, c_day, SLOT, DAY, MAX_NAME, choice, isLoaded, isSaved);
            return 'E';
        }
        case 'S':{
            isSaved = saveSched(outfile, sched, SLOT, DAY, pName, isSaved);
            return 'D';
        }
        case 'M':{
            mainMenu();
            return 'M';
        }
        case 'X': return 'X';
        default:{
            cout << "Invalid choice! Please try again.\n";
            return 1;
        }
    }
}