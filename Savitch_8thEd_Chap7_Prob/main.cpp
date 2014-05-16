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
#include <cmath>
using namespace std;
//Global variables and constants

//Function prototypes
void GetDigits(char[], const int &, int &);
//Exection begins HERE
int main(int argc, char** argv) {
    const int SIZE = 20;
    int s_Num1 = 0, s_Num2 = 0, limit = 0;         //stores the partially-filled array's size
    int Sum[SIZE];                      //array of 20 integers max
    string n_In;                        //string for input
    int idx;                            //index for the addition
    char BigNum[SIZE];                  //stores the digits of the sum
    char Num1[SIZE];                    //stores first number's digits as characters
    char Num2[SIZE];                    //stores second number's digits as characters
    cout << "Enter a number up to 20 digits long: ";
    GetDigits(Num1, SIZE, s_Num1);
    for(int ctr = 0; ctr < s_Num1; ctr++){
        cout << Num1[ctr];
    }
    cout << endl;
    cout << "Enter another number up to 20 digits long: ";
    GetDigits(Num2, SIZE, s_Num2);
    for(int ctr = 0; ctr < s_Num1; ctr++){
        cout << Num2[ctr];
    }
    cout << endl;
    s_Num1 >= s_Num2 ? limit = s_Num1 : limit = s_Num2;
    idx = abs(s_Num1 - s_Num2);
    for(int ctr = limit-idx; ctr < limit && s_Num1 != s_Num2; ctr++){
        if(s_Num1 > s_Num2) Num1[ctr] = 0;
        else if(s_Num1 < s_Num2) Num2[ctr] = 0;
    }
    cout << Num2[3] << endl;
    for(int ctr = 0; ctr < limit; ctr++ ){
        //declare a boolean variable for the offset or "carry" used in addition
        bool offset = false;
        Sum[ctr] = (static_cast<int>(Num1[ctr]) - 48) + (static_cast<int>(Num2[ctr]) - 48);
        cout << "Digit #" << ctr << " = " << Sum[ctr] << endl; //stub! Print the Sums array before the modulus
        if(Sum[ctr] > 10){
            offset = true;
        }
    }
    return 0;
}
//Function definitions
void GetDigits(char BigNum[], const int &SIZE, int &s_Num){
    string n_In;
    cin >> n_In;
    for(int ctr = 0, ctr2 = n_In.size()-1; ctr < n_In.size() && ctr2 >= 0; ctr++){
        BigNum[ctr2] = n_In[ctr];
        ctr2--;
        s_Num++;
    }
}