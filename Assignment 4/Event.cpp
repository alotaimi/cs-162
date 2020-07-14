/******************************************************
** Program: Event.cpp
** Author: Mishary alotaibi
** Date: 5/25/2020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#include <iostream>
#include "Event.h"
using namespace std;
/*********************************************************************
** Function:Event
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Event::Event(){
    Who = "Nothing";
    Message = "No Action";
}
Event::~Event(){
}
/*********************************************************************
** Function:setters
** Description:sets
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Event::setWho(string x){
    Who = x;
}
void Event::setMessage(string x){
    Message = x;
}
/*********************************************************************
** Function:getters
** Description:gets everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
string Event::getWho(){
    return Who;
}
string Event::getMessage(){
    return Message;
}
/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
void Event::action(){}
Event &Event::operator=(const Event &old_obj){
    this->Who = old_obj.Who;
    this->Message = old_obj.Message;
    return *this;
}