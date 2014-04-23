/* 
 * NAME: Ezra P. Guinmapang
 * DATE: October 14, 2013, 6:19 PM
 * PURPOSE: Solve Midterm Problem 1 - Print numbers where Columns = Rows
 */

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global variables and constants: NONE

//Function Prototypes: NONE

//Execution begins HERE
int main(int argc, char** argv) {
    
    //Delcare variables
    char Repeat;
    do{
        //Declare N_Lines inside loop to clear its value upon repeat
        int N_Lines = 0;
        //Input values
        cout << "Please enter the number of lines you want to output: ";
        cin >> N_Lines;
        for(int Col = 1; Col <= N_Lines; Col++){
            cout << setw(Col) << Col << endl;
        }
        cout << "Again(Y/N)? ";
        cin >> Repeat;
    }
    while(Repeat == 'Y' || Repeat == 'y');
    cout << "See you soon!!!\n";
    return 0;
}

