#ifndef CPPPROJECT_SHAPES_H
#define CPPPROJECT_SHAPES_H

//Code comes from exercise 5.23 that was made earlier in the course
#include <iostream>
using namespace std;

//Non-recursive, uses nested funcitons
//Diamond printing program
static void diamondshape() {
    //Variables
    int amount = 9;
    int originalamount = amount;
    int stars = 1;
    int space = 3;

    //While loop for first half of stars
    while(amount > 0) {

        //Space Before
        for (int i{0}; i < amount / 2; i++) {
            cout << " ";
        }

        //Stars
        for (int i{0}; i < stars; i++) {
            cout << "*";
        }

        //Space After
        for (int i{0}; i < amount / 2; i++) {
            cout << " ";
        }
        cout <<"\n";
        amount -= 2;
        stars += 2;
    }

    //Restarts the loop with negative amount instead
    amount = originalamount * -1;
    stars -= 2;
    //Second half of the stars
    while(amount < 0){

        //Space Before
        for(int i{0}; i < space/2; i++){
            cout << " ";
        }

        //Stars
        for(int i{0};i > amount+2 ;i--) {
            cout << "*";
        }

        //Space After
        for(int i{0}; i < space/2; i++){
            cout << " ";
        }
        amount += 2;
        space += 2;
        cout << "\n";
    }
}

//Recursive, uses nested functions
//Draws a Triangle (Right angle)
int number = 10;
static void triangleshape(){
    if(number > 0){
        //Recursive call
        for(int i{0}; i < number; i++){
            cout << "*";
        }
        cout << "\n";
        number--;
        number--;
        triangleshape();
    } else {
        //Base case
        number = 10;
        return;
    }
}
#endif //CPPPROJECT_SHAPES_H
