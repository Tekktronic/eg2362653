/* 
 * NAME: Ezra P. Guinmapang
 * DATE: October 14, 2013, 6:19 PM
 * PURPOSE: Solve Midterm Problem 3
 * Develop an application that will determine if a bank customer 
has exceeded his checking account. The following 
facts are available and input into the program:

a. Account number (Five digits only)
b. Balance at the beginning of the month 
c. Total of all checks written by this customer this month 
d. Total of all deposits credited to this customer's account this 
     month.
 * The program should input each of these facts as 
unsigned shorts, calculate the new balance, display the new balance and 
debit the account $17.50 if overdrawn. Also, if overdrawn, tell the 
customer an additional $17.50 fee has been assessed and what the 
balance would be with this fee included.
 */

//Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

//Global variables and constants: NONE

//Function Prototypes: NONE
int GetInput(){
    int RVal;
    char Digit;
    string Value;
    getline(cin, Value);
    do{
        peek
    }
    stringstream(Value) >> RVal;
    return RVal;
}

//Execution begins HERE
int main(int argc, char** argv) {
    int TEMP;
    char Repeat;
    const float OD_Fee = 17.50;
    unsigned short AcctN, Bal, T_Checks, T_Dep;
    cout << "Enter Account Number: ";
    TEMP = GetInput();
    cout << TEMP << endl;
    cout << "Enter the Account Balance: ";
    cin >> Bal;
    cout << "Enter the Total Amount of Deposits: ";
    cin >> T_Dep;
    Bal += (T_Dep - T_Checks);
    cout << "Enter the Total amount of checks written: ";
    cin >> T_Checks;
    
    if(Bal <= 0){
        cout << "This account is overdrawn. A $17.50 overdraft fee will be "
             << "debited to this account.\n";
        cout << "The Current Balance on this account is " << fixed << showpoint
             << setprecision(2) << Bal - OD_Fee << endl;
    }
    else cout << "The Current Balance on this account is " << fixed << showpoint
              << setprecision(2) << Bal << endl;    
    return 0;
}