/******************************************************
** Program: Gold.cpp
** Author: Mishary alotaibi
** Date: 5/25/2020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#include <iostream>
#include "Gold.h"
using namespace std;
/*********************************************************************
** Function:Gold
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Gold::Gold(){
    Who = "Gold";
    Message = "You see a glimmer nearby.";
}
Gold::~Gold(){}
/*********************************************************************
** Function:action
** Description:actions for the event
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Gold::action(){
    cout << "You have obtained The treasure"<<endl;
}
/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
Gold &Gold::operator=(const Gold &old_obj){
    this->Who = old_obj.Who;
    this->Message = old_obj.Message;
    return *this;
}