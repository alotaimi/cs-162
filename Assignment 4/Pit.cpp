/******************************************************
** Program: Pit.cpp
** Author: Mishary alotaibi
** Date: 5/25/2020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#include <iostream>
#include "Pit.h"
using namespace std;
/*********************************************************************
** Function:Pit
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Pit::Pit(){
    Who = "Pit";
    Message = "You feel a breeze.";
}
Pit::~Pit(){}
/*********************************************************************
** Function:action
** Description:actions for the event
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Pit::action(){
    cout << "Game Over"<<endl;
    cout << "You have fallen down and got killed"<<endl;
}
/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
Pit &Pit::operator=(const Pit &old_obj){
    this->Who = old_obj.Who;
    this->Message = old_obj.Message;
    return *this;
}