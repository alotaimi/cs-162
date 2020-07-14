/******************************************************
** Program: linked_list.h
** Author: Mishary Alotaibi
** Date: 06/07/2020
** Description:Everything related to the class
** Input:-
** Output:-
******************************************************/
#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"

class Linked_List {
private:
	unsigned int length; 
	Node* head;
    Node* current;
public:
    Linked_List();
	int get_length();
   
	void print(); 
	void clear();
   
	void push_front(int); 
	void push_back(int); 
	void insert(int val, unsigned int index);

	void sort_ascending();
	void sort_descending();
    Node* sortingA(Node* arr1, Node* arr2);
    void SplitListA(Node* x, Node** front, Node** back);
    void MergeSortA(Node** current);
	Node* sortingD(Node* arr1, Node* arr2);
    void SplitListD(Node* x, Node** front, Node** back);
    void MergeSortD(Node** current);
	int primenum(int x);
	unsigned int count_prime();

};
#endif