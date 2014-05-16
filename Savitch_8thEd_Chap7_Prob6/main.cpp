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
void fillAR(int[], int);
void printAR(int[], int, int);
void sort_In(int[], int);
//Exection begins HERE
int main(int argc, char** argv) {
    const int SIZE = 30;                //size of array holding the integers to be sorted
    int a_Num[SIZE];                    //the array of integers to be sorted
    srand(static_cast<int>(time(0)));   //seed the random number generator
    fillAR(a_Num, SIZE);                //fills the array with random 2-digit integers
    cout << "Before the sort:\n";
    printAR(a_Num, SIZE, 10);           //prints out the unsorted array
    sort_In(a_Num, SIZE);               //perform the insertion sort
    cout << "After the sort:\n";
    printAR(a_Num, SIZE, 10);           //prints out the sorted array
    return 0;
}
//Function definitions
void fillAR(int num[], int n){
    for(int i = 0; i < n; i++){
        num[i] = (rand() % 90) + 10;
    }
}
void printAR(int num[], int n, int perline){
    for(int i = 0; i < n; i++){
        cout << num[i] << " ";
        if(i % perline == (perline - 1)) cout << endl;
    }
    cout << endl;
}
void sort_In(int num[], int SIZE){
    int idx;                            //loop iterator for the entire array
    int pos;                            //index of the element compared against
    int e_Sort;                         //index of the element being sorted
    for(idx = 0; idx < SIZE - 1; idx++){
        pos = idx;                      //set position to element to be compared against
        e_Sort = idx + 1;               //set position to element being sorted
        while(num[e_Sort] < num[pos] && pos >= 0){    //as long as the element being sorted
            int tmp = num[e_Sort];                    //is less than the element being compared to,
            num[e_Sort] = num[pos];                   //swap the two elements, effectively "inserting"
            num[pos] = tmp;                           //the element into place in the sorted sub-array
            pos--;              //set the position of the next element in the sorted sub-array to be compared against
            e_Sort--;           //decrement this to keep track of the element being sorted 
        }
    }
    cout << endl;
}