/******************************************************
** Program: Node.h
** Author: Mishary Alotaibi
** Date: 06/07/2020
** Description:Everything related to the class
** Input:-
** Output:-
******************************************************/
#ifndef NODE_H
#define NODE_H

class Node{
public:
	int val;
	Node *next;
    Node(int x);
    void Next(Node* x);
};

#endif