/******************************************************
** Program: Room.cpp
** Author: Mishary alotaibi
** Date: 5/25/2020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#include <iostream>
#include "Room.h"
using namespace std;
/*********************************************************************
** Function:Room
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Room::Room(){
    has_event = false;
    event = NULL;
}
/*********************************************************************
** Function:Wumpus
** Description:Deconstructer
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Room::~Room(){
    event = NULL;
    delete event;
}
/*********************************************************************
** Function:setevent
** Description:set an event for the room
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Room::setevent(Event* x){
    if(event != NULL){
        event = NULL;
    }
    event = x;
    message = event->getMessage();
     Who = event->getWho();
     if(Who == "Player"){
     has_event = false;
     }
     else{
         has_event = true;
     }
}
/*********************************************************************
** Function:setters and getters
** Description:set and get
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Room::sethas(bool x){
    has_event = x;
}
Event* Room::getevent(){
    return event;
}
string Room::getWho(){
    return Who;
}
string Room::getmessage(){
    return message;
}
bool Room::gethas(){
    return has_event;
}
/*********************************************************************
** Function:action
** Description:actions for the event
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Room::action(){
    event->action();
}
/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
Room &Room::operator=(const Room &old_obj){
    this->event = old_obj.event;
    this->has_event = old_obj.has_event;
    return *this;
}
