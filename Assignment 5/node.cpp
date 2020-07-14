/******************************************************
** Program: Node.cpp
** Author: Mishary Alotaibi
** Date: 06/07/2020
** Description:Everything related to the class
** Input:-
** Output:-
******************************************************/
#include <iostream>
#include "node.h"
/*********************************************************************
** Function:Node
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Node::Node(int x){
    val = x;
    next = NULL;
}
/*********************************************************************
** Function:Next
** Description:that sets the next
** Parameters:1
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Node::Next(Node* x){
    this->next = x;
}