/* 
 * NAME: Ezra P. Guinmapang
 * DATE: October 15, 2013, 6:10 AM
 * PURPOSE: Create a program menu from which to choose the program to be run
 */

//Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Global variables and constants: NONE

//Function Prototypes:
int Prob1();
int Prob2();
int Prob3();
int Prob4();
int Prob5();
int Prob6();
float GetBase(char);
float GetRate(char);
float CalcCharge(char, int);
int main(int argc, char** argv) {
    
    //Declare variables
    char Again;
    bool EndIt = false;
    char m_Item;
    //Prompt and input menu item
        cout << "**************************************************\n";
        cout << "**        CSC-5: C++ MIDTERM EXAMINATION        **\n";
        cout << "**                 PROGRAM MENU                 **\n";
        cout << "**           NAME: EZRA P. GUINMAPANG           **\n";
        cout << "**                SECTION: 47981                **\n";
        cout << "**           PROFESSOR: DR. MARK LEHR           **\n";
        cout << "**************************************************\n";
        do{
            cout << "**************************************************\n";
            cout << "**          AVAILABLE PROGRAMS TO RUN:          **\n";
            cout << "**                                              **\n";
            cout << "**     1. Printing numbers: Columns = Width     **\n";
            cout << "**     2. Histograms                            **\n";
            cout << "**     3. Overdraft Calculator ***EMPTY!!***   **\n";
            cout << "**     4. Gross Pay Calculator                  **\n";
            cout << "**     5. ISP Monthly Charge Calculator         **\n";
            cout << "**     6. Funny Numbers   ***BROKEN!!***        **\n";
            cout << "**************************************************\n";
            cout << "\nWhich program would you like to run? ";
            cin >> m_Item;
            switch(m_Item){
                case '1': Prob1(); continue;
                case '2': Prob2(); continue;
                case '3': Prob3(); continue;
                case '4': Prob4(); continue;
                case '5': Prob5(); continue;
                case '6': Prob6(); continue;
                default: {
                    cout << "\nYou pressed " << m_Item << " to exit. Goodbye!!!\n";
                    EndIt = true;
                    break;
                }
            }
        }while(!EndIt);
    
    return 0;
}
//Function definitions
int Prob1(){
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
    }while(Repeat == 'Y' || Repeat == 'y');
    cout << "See you soon!!!\n";
    return 0;
}
int Prob2(){
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
        }while(N_Nums < 0 || N_Nums > 5);
        cout << "Again(Y/N)? ";
        cin >> Repeat;
    }while(Repeat == 'Y' || Repeat == 'y');
    cout << "See you again soon!\n";
    return 0;
}
int Prob3(){
    
}
int Prob4(){
    //Declare variables
    char Repeat;
    do{
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
        cout << "Again(Y/N)? ";
        cin >> Repeat;
    }while(Repeat == 'Y' || Repeat == 'y');
    cout << "See you soon!!!\n";
    return 0;
}
int Prob5(){
    
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
int Prob6(){
    //Declare variables
    char Repeat;
    do{
        int Ctr = 1;
        unsigned int Num = 1;
        int isPrime;
        int exp2 = 0, exp3 = 0, exp5 = 0;
        do{
            do{
                do{
                    Num = pow(2, exp2) * pow(3, exp3) * pow(5, exp5);
                    cout << Ctr << " = " << Num << endl;
                    Ctr++;
                    if(Ctr > 1501) break;
                    exp2++;
                }while(exp2 < 32);
                exp2 = 0;
                if(Ctr > 1501) break;
                exp3++;
            }while(exp3 < 32);
            exp3 = 0;
            if(Ctr > 1501) break;
            exp5++;
        }while(exp5 < 32);
    
    cout << endl << Num << endl;
    //Repeat
        cout << "Again(Y/N)? ";
        cin >> Repeat;
    }while (Repeat == 'Y' || Repeat == 'y');
    return 0;
}