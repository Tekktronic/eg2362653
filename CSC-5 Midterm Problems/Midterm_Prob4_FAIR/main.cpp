/* 
 * NAME: Ezra P. Guinmapang
 * DATE: October 14, 2013, 6:19 PM
 * PURPOSE: Solve Midterm Problem 4 - Gross Pay Calculator
 */

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global variables and constants: NONE

//Function Prototypes: NONE

//Execution begins HERE
int main(int argc, char** argv) {
    int Hrs = 0;
    float Rate = 0, Gross = 0;
    cout << "Enter the hours: ";
    cin >> Hrs;
    cout << "Enter the Rate of pay: $";
    cin >> Rate;
    if(Hrs < 40){
        if(Hrs <= 20){
            Gross = Hrs * Rate;
            cout << "Pay = $" << fixed << showpoint << setprecision(2)
                 << Hrs * Rate << endl;
        }
        else{
            Gross = (20 * Rate) + ((Hrs%20) * (Rate * 1.5));
            cout << "Pay = $" << fixed << showpoint << setprecision(2)
                 << 20 * Rate << endl;
            cout << "Time-&-a-Half Pay = $" << fixed << showpoint
                 << setprecision(2) << Hrs%20 * (Rate * 1.5) << endl;
        }
    }
    else if(Hrs == 40){
        Gross = (20 * Rate) + (20 * (Rate * 1.5));
        cout << "Pay = $" << fixed << showpoint << setprecision(2)
             <<  20 * Rate << endl;
        cout << "Time-&-a-Half Pay = $" << fixed << showpoint << setprecision(2)
             << 20 * (Rate * 1.5) << endl;
    }
    else if(Hrs > 40){
        Gross = (20 * Rate) + (20 * (Rate * 1.5)) + ((Hrs-40) * (Rate * 2));
        cout << "Pay = $" << fixed << showpoint << setprecision(2)
             << 20 * Rate << endl;
        cout << "Time-&-a-Half Pay = $" << fixed << showpoint 
             << setprecision(2) << 20 * (Rate * 1.5) << endl;
        cout << "Double-Time Pay = $" << fixed << showpoint << setprecision(2)
             << (Hrs-40) * (Rate * 2) << endl;
    }
    cout << "Gross Pay = $" << fixed << showpoint << setprecision(2)
         << Gross << endl;
    return 0;
}