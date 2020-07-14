/******************************************************
** Program: Escape.cpp
** Author: Mishary alotaibi
** Date: 5/25/2020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#include <iostream>
#include "Escape.h"
using namespace std;
/*********************************************************************
** Function:Escape
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Escape::Escape(){
    Who = "Escape";
    Message = "";
}
Escape::~Escape(){}
/*********************************************************************
** Function:action
** Description:actions for the event
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Escape::action(){
    cout << "you have won"<<endl;
    cout << "You have escaped the cave"<<endl;
}
/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
Escape &Escape::operator=(const Escape &old_obj){
    this->Who = old_obj.Who;
    this->Message = old_obj.Message;
    return *this;
}