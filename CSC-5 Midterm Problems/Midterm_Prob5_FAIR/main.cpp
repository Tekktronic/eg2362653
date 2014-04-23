/* 
 * NAME: Ezra P. Guinmapang
 * DATE: October 14, 2013, 6:19 PM
 * PURPOSE: Solve Midterm Problem 5 - ISP Monthly Charge Calculator
 */

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global variables and constants: NONE

//Function Prototypes
float GetBase(char);
float GetRate(char);
float CalcCharge(char, int);
//Execution begins HERE
int main(int argc, char** argv) {
    
    //Declare variables
    char Repeat, Choice;
    do{
        //Declare inside the loop to reset value upon repeat
        int Hrs;
        float Charges;
        //Input values
        do{
            cout << "AVAILABLE INTERNET SERVICE PACKAGES:\n";
            cout << "A: $29.95 per month with 11 hours free access.\n";
            cout << "   Additional hours are $2.50 per hour up to 22 hours.\n";
            cout << "   Additional hours in excess of 22 hours are $5.00 per hour.\n";
            cout << "B: $34.95 per month with 22 hours free access.\n";
            cout << "   Additional hours are $1.25 per hour up to 33 hours.\n";
            cout << "   Additional hours in excess of 33 hours are $2.50 per hour.\n";
            cout << "C: $39.95 per month with unlimited access.\n";
            cout << "Please choose which subscription package you would like: ";
            cin >> Choice;
            if(Choice == 'A' || Choice == 'a') Choice = 'a';
            else if(Choice == 'B' || Choice == 'b') Choice = 'b';
            else if(Choice == 'C' || Choice == 'c') Choice = 'c';
            else cout << "Invalid choice! Please enter a valid package choice:\n";
        }
        while(Choice != 'A' && Choice != 'a' && Choice != 'B' && Choice != 'b' &&
              Choice != 'C' && Choice != 'c'); //Input validation
        cout << "Enter the number of hours: ";
        cin >> Hrs;
        Charges = CalcCharge(Choice, Hrs); //Calculate the monthly charges
        //Output values
        cout << "Your monthly usage in hours is: " << Hrs << endl;
        cout << "Your monthly charge = $" << fixed << showpoint << setprecision(2)
             << Charges << endl;
        //Repeat
        cout << "Again(Y/N)? ";
        cin >> Repeat;
    }while (Repeat == 'Y' || Repeat == 'y');
    //Execution ends HERE
    return 0;
}
//Function definitions
float GetBase(char Ch){
    switch(Ch){
        case 'a': return 29.95;
        case 'b': return 34.95;
        case 'c': return 39.95;
    }
}
float GetRate(char Ch){
    switch(Ch){
        case 'a': return 2.50;
        case 'b': return 1.25;
        case 'c': return 0;
    }
}
float CalcCharge(char Ch, int Hr){
    float Base, Rate;
    Base = GetBase(Ch);
    Rate = GetRate(Ch);
    switch(Ch){
        case 'a': {
            cout << "You have chosen Package A!\n";
            if(Hr < 22){
                if(Hr <= 11) return Base;
                else if(Hr%11 != 0) return Base + ((Hr%11) * Rate);
            }
            else if(Hr == 22) return Base + (11 * Rate);
            else if(Hr > 22) return Base + (11 * Rate) + ((Hr%22) * (Rate * 2));
        }
        case 'b': {
            cout << "You have chosen Package B!\n";
            if(Hr < 33){
                if(Hr <= 22) return Base;
                else if(Hr%22 != 0) return Base + ((Hr%22) * Rate );
            }
            else if(Hr == 33) return Base + (11 * Rate);
            else if(Hr > 33) return Base + (11 * Rate) + ((Hr%33) * (Rate * 2));
        }
        case 'c': {
            cout << "You have chosen Package C!\n";
            return Base;
        }
    }
}