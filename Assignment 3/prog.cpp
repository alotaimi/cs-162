/******************************************************
** Program: prog.cpp
** Author: Mishary alotaibi
** Date: 5/9/2020
** Description: Zoo game 
** Input: NONE
** Output: NONE
******************************************************/
//it was over 15 lines because i had to do it in order to make it more readable for anyone who wants to use the program
#include <iostream>
#include <fstream>
#include "Zoo.h"
#include <cstring>
using namespace std;
void art();
int main()
{
    cout << "Welcome to Mishary's Zoo" << endl;
    Zoo zoo;
    int loop = 0;
    string x;
    while (loop == 0)
    {
        cout << "Do you want to continue? y/n"<<endl;
        cin>>x;
        if(x == "y"){
        if (zoo.getwallet() <= 0)
        {
            cout << "You Lost all your money" << endl;
            cout << "Thank you for Playing" << endl;
            loop++;
        }
        else
        {
            zoo.newround();
            zoo.setwallet();
            zoo.displayer();
            cout << "Bank account: " << zoo.getwallet() << endl;
            zoo.events();
            zoo.store();
            cout << "Bank account: " << zoo.getwallet() << endl;
            zoo.sell();
            zoo.totalcost();
            art();
            //cout << "Bank account: " << zoo.getwallet() << endl;
        }
        }
        else if(x == "n"){
            loop++;
        }
        else{
            cout << "wrong input"<<endl;
        }
    }
    cout << "Thank you for playing ^^"<<endl;
    return 0;
}
