/* 
 * File:   main.cpp
 * Author: Ezra Guinmapang
 *
 * Created on May 12, 2014, 9:52 PM
 */

//Libraries
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
//Global variables and constants

//Function prototypes
bool GetDigits(int[], const int &);     //takes the initial PIN# input from the user.
bool pinIt(int[], int[], const int &);  //takes the random# key input from user and validates the user's PIN#
void gen_Rkey(int[], int);      //generates a different random# key and displays it.
//Exection begins HERE
int main(int argc, char** argv) {
    const int DIGITS = 5;       //number of digits in the PIN#
    const int SIZE = 10;        //size of array holding the identifier array
    bool match = false;         //boolean representing a matched pair of PIN# and random# key
    int PIN[DIGITS];            //holds the digits(char) of the PIN#
    int idx[SIZE];              //holds the random# key used to identify the PIN#
    srand(static_cast<int>(time(0)));   //seed the random number generator
    GetDigits(PIN, DIGITS);     //Takes the PIN# input and stores it in the array
    cout << "Generating your random number key. Each PIN# digit is associated with a random number.\n";
    cout << "Use these random numbers to enter your PIN# instead of entering it directly.\n";
    cout << "WARNING! Match each digit accordingly, or you will get an invalid PIN# error!\n";
    cout << "After 3 consecutive invalid PIN# errors, YOU WILL BE LOCKED OUT!\n";
    cout << endl;
    gen_Rkey(idx, SIZE);        //generates the random# key
    do{
        match = pinIt(idx, PIN, DIGITS);    //get input from user. User inputs random numbers from 1 to 3, for each PIN# digit
    }while(!match);
    return 0;
}
//Function definitions
bool GetDigits(int array[], const int &DIGITS){
    string pin_In;      //string for the PIN# input
    bool nan;           //boolean to flag a non-digit PIN entry
    do{
        nan = false;    //initialize boolean to false
        cout << "Enter a 5-digit PIN number: ";
        cin >> pin_In;
        for(int ctr = 0; ctr < DIGITS; ctr++){
            if(isdigit(pin_In[ctr])){
                array[ctr] = static_cast<int>(pin_In[ctr]) - 48;
            }
            else{
                nan = true;     //set boolean to true if input is invalid
                break;
            }
        }
        if(pin_In.size() != DIGITS || (nan) ) cout << "Invalid input! Please try again.\n";
    }while(pin_In.size() != DIGITS || (nan));
}
void gen_Rkey(int num[], int n){
    for(int i = 0; i < n; i++){
        num[i] = (rand() % 3) + 1;
        cout << "PIN# Digit: " << i << ", key: " << num[i] << endl;
    }
    cout << endl;
}
bool pinIt(int index[], int PIN[], const int &DIGITS){
    static short Locked = 3;    //holds the number of tries the user has left; if this reaches ZERO, user's PIN# is locked
    bool isValid = false;       //boolean to flag a non-digit PIN entry//
    int input[DIGITS];          //holds the random numbers input from user, to match against the identifier array
    if(Locked == 0){
        cout << "You have entered an invalid PIN# 3 times. You are now locked out.\n";
        cout << "Please contact customer support to unlock or change your PIN#.\n";
        return true;
    }
    do{
        while(!isValid){
            isValid = GetDigits(input, DIGITS);   //get input from user
        }
        for(int ctr = 0; ctr < DIGITS; ctr++){
            if(index[PIN[ctr]] != input[ctr]){
                cout << "You entered an invalid PIN number! You have 2 more tries,\n";
                cout << "after which you will be locked out and will have to reset ";
                cout << "your PIN number.\n";
                isValid = false;
                Locked--;
                return isValid;
            }
            else{
                isValid = true;
            }
        }
        if(isValid) cout << "You have entered the correct PIN!!!\n";
    }while(!isValid);
    return isValid;
}