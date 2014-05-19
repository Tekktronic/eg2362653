/* 
 * File:   main.cpp
 * Author: Ezra Guinmapang
 *
 * Created on May 19, 2014, 2:29 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//Global variables and constants

//Function prototypes

//Execution begins HERE
int main(int argc, char** argv) {
    //declare variables
    const int SLOT = 0;
    const int DAY = 0;
    char choice[20];
    char f_sched;
    char sched[SLOT][DAY];
    cin.get(choice, '\n');
    //declare streams
    cout << "** INSERT MENU HERE***\n";
    if(choice[0] == '1'){
        ifstream infile;
        ofstream outfile;
        infile.open("sched.dat");
        cout << "Enter the profile name to load: ";
        infile >> choice;
        cin.ignore();
        cout << choice << endl;
    }
    cin.get(choice, '/n');
    cout << choice << endl;
    
    return 0;
}

