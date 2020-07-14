/******************************************************
** Program: Wumpus.cpp
** Author: Mishary alotaibi
** Date: 5/25/2020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#include <iostream>
#include "Wumpus.h"
using namespace std;
/*********************************************************************
** Function:Wumpus
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Wumpus::Wumpus(){
    Who = "Wumpus";
    Message = "You smell a terrible stench.";
}
Wumpus::~Wumpus(){}
/*********************************************************************
** Function:action
** Description:actions for the event
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Wumpus::action(){
    cout << "Game Over"<<endl;
    cout << "You have been eaten by Wumpus"<<endl;
}
/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
Wumpus &Wumpus::operator=(const Wumpus &old_obj){
    this->Who = old_obj.Who;
    this->Message = old_obj.Message;
    return *this;
}