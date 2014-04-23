/* 
 * NAME: Ezra P. Guinmapang
 * DATE: October 14, 2013, 6:19 PM
 * PURPOSE: Solve Midterm Problem 2 - Histograms
 */

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global variables and constants: NONE

//Function Prototypes: NONE

//Execution begins HERE
int main(int argc, char** argv) {
    
    //Declare variables
    char Repeat;
    do{
        //Declare these variables inside the loop to clear variables on repeat
        int Ctr = 0, N_Nums = 0, Num = 0;
        //Prompt and input values
        cout << "We are going to draw simple histograms.\n";
        cout << "You may enter up to 5 numbers. Each number ";
        cout << "should be a number between 5 and 25.\n";
        do{
            cout << "How many numbers are you entering? ";
            cin >> N_Nums;
            if(N_Nums > 0 && N_Nums <= 5){
                do{
                    cout << "Enter the number: ";
                    cin >> Num;
                        if(Num >= 5 && Num <= 25){
                            cout << "Here is your histogram:\n";
                            cout << Num << ":\t";
                            for(int Ctr2 = 0; Ctr2 < Num; Ctr2++){
                                cout << "*";
                            }
                            cout << endl;
                            Ctr++;
                        }
                        else cout << "Invalid input! Try again!\n";
                    }
                    while(Ctr < N_Nums);
                }
            else cout << "Invalid number of inputs! Try again!\n";
        }
        while(N_Nums < 0 || N_Nums > 5);
        cout << "Again(Y/N)? ";
        cin >> Repeat;
    }
    while(Repeat == 'Y' || Repeat == 'y');
    cout << "See you again soon!\n";
    return 0;
}

