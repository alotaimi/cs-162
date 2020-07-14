/******************************************************
** Program: Bats.cpp
** Author: Mishary alotaibi
** Date: 5/25/2020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#include <iostream>
#include "Bats.h"
using namespace std;
/*********************************************************************
** Function:Bats
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Bats::Bats(){
    Who = "Bats";
    Message = "You hear wings flapping.";
}
Bats::~Bats(){}
/*********************************************************************
** Function:action
** Description:actions for the event
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Bats::action(){
    cout << "Bats took you to another room"<<endl;
}
/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
Bats &Bats::operator=(const Bats &old_obj){
    this->Who = old_obj.Who;
    this->Message = old_obj.Message;
    return *this;
}