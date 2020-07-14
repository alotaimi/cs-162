/******************************************************
** Program: linked_list.cpp
** Author: Mishary Alotaibi
** Date: 06/07/2020
** Description:Everything related to the class
** Input:-
** Output:-
******************************************************/
#include <iostream>
#include "linked_list.h"
#include <string>
#include <stdlib.h>
using namespace std;
/*********************************************************************
** Function:linked list
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Linked_List::Linked_List(){
    length = 0;
    head = NULL;
    current = NULL;
}
/*********************************************************************
** Function:get_length
** Description:gets your length
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
int Linked_List::get_length(){
    return length;
}
/*********************************************************************
** Function:print
** Description:prints all the values inside of linked list
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Linked_List::print(){
    current = head;
    int x = 0;
    while(x < length) {
        cout << current->val;
        cout << " ";
        current = current->next;
        x++;
    }
    cout << "\n";
}
/*********************************************************************
** Function:clear
** Description:deletes all nodes and sets legnth 0
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Linked_List::clear(){
    current = head;
	Node* temp = NULL;
	while(current != NULL){
		temp = current->next;
		delete current;
		current = temp;
	}
	delete temp;
    length = 0;
}
/*********************************************************************
** Function:push_front
** Description:creates a node inside of linked list
** Parameters:1
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Linked_List::push_front(int x){
    Node *z = new Node(x);
    z->Next(head);
    head = z;
    current = head;
    length++;
}
/*********************************************************************
** Function:push_back
** Description:creates a node inside of linked list
** Parameters:1
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Linked_List::push_back(int x){
    Node *z = new Node(x);
    int a = 0;
    if(head == NULL) {
        head = z;
        return;
    }

    current = head;
    while(current && current->next) {
        current = current->next;
    }
    current->Next(z);
    length++;
}
/*********************************************************************
** Function:insert
** Description:inserts a node inside of linked list
** Parameters:2
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
// it was over 15 becuase i had to check if it was at the first of linked list or last because it will make things easier :D
void Linked_List::insert(int val, unsigned int index){
    Node* temp = new Node(val);
    int a = 0;
    if(index > length){
        cout <<"wrong index"<<endl;
        delete temp;
    }
    if(index == 0){
     push_front(val);
     delete temp;
    }
   else if(index == length){
     push_back(val);
     delete temp;
    }
    else{
     current = head;
    while(current && current->next) {
        if(a == index-1){
            temp->next = current->next;
            current->next = temp;
            current = current->next;
            length++;
        }
        current = current->next;
        a++;
    }
    }
}
/*********************************************************************
** Function:sort_ascending
** Description:sorts everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Linked_List::sort_ascending(){
MergeSortA(&head);
}
/*********************************************************************
** Function:sort_descending
** Description:sorts everything but in descending
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Linked_List::sort_descending(){
    MergeSortD(&head);
}
/*********************************************************************
** Function:sortingA
** Description:sorts the two linked lists 
** Parameters:2
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was inspired by a website called "educative"
//https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
Node* Linked_List::sortingA(Node* arr1, Node* arr2){
	Node* temp = NULL; 

	if (arr1 == NULL) {
		return (arr2); 
    }
	else if (arr2 == NULL){ 
		return (arr1); 
    }
	if (arr1->val <= arr2->val) { 
		temp = arr1; 
		temp->next = sortingA(arr1->next, arr2); 
	} 
	else { 
		temp = arr2; 
		temp->next = sortingA(arr1, arr2->next); 
	} 
	return temp; 
}
/*********************************************************************
** Function:SplitListA
** Description:splits the linked list into two linked lists 
** Parameters:3
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was inspired by a website called "educative"
//https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
void Linked_List::SplitListA(Node* x, Node** front, Node** back){
    Node* a; 
	Node* b; 
	b = x; 
	a = x->next; 

	while (a != NULL) { 
		a = a->next; 
		if (a != NULL) { 
			b = b->next; 
			a = a->next; 
		} 
	} 

	*front = x; 
	*back = b->next; 
	b->next = NULL; 
}
/*********************************************************************
** Function:MergeSortA
** Description:merge and sorts the two linked list into one
** Parameters:1
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was inspired by a website called "educative"
//https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
void Linked_List::MergeSortA(Node** current){
    Node* temp = *current; 
	Node* a; 
	Node* b; 

	if ((temp == NULL) || (temp->next == NULL)) { 
		return; 
	}

	SplitListA(temp, &a, &b); 

	MergeSortA(&a); 
	MergeSortA(&b); 

	*current = sortingA(a, b); 
}
/*********************************************************************
** Function:sortingD
** Description:sorts the two linked lists 
** Parameters:2
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was inspired by a website called "educative"
//https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
Node* Linked_List::sortingD(Node* arr1, Node* arr2){
	Node* temp = NULL; 

	if (arr1 == NULL){
		return (arr2);
    } 
	else if (arr2 == NULL){ 
		return (arr1); 
    }
	if (arr1->val >= arr2->val) { 
		temp = arr1; 
		temp->next = sortingD(arr1->next, arr2); 
	} 
	else { 
		temp = arr2; 
		temp->next = sortingD(arr1, arr2->next); 
	} 
	return temp; 
}
/*********************************************************************
** Function:SplitListD
** Description:splits the linked list into two linked lists 
** Parameters:3
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was inspired by a website called "educative"
//https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
void Linked_List::SplitListD(Node* x, Node** front, Node** behind){
    Node* a; 
	Node* b; 
	b = x; 
	a = x->next; 

	while (a != NULL) { 
		a = a->next; 
		if (a != NULL) { 
			b = b->next; 
			a = a->next; 
		} 
	} 

	*front = x; 
	*behind = b->next; 
	b->next = NULL; 
}
/*********************************************************************
** Function:MergeSortD
** Description:merge and sorts the two linked list into one
** Parameters:1
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was inspired by a website called "educative"
//https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
void Linked_List::MergeSortD(Node** x){
    Node* temp = *x; 
	Node* a; 
	Node* b; 

	if ((temp == NULL) || (temp->next == NULL)) { 
		return; 
	} 

	SplitListD(temp, &a, &b); 

	MergeSortD(&a); 
	MergeSortD(&b); 

	*x = sortingD(a, b); 
}
/*********************************************************************
** Function:primenum
** Description:it checks the number if it is a prime number or no
** Parameters:1
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
int Linked_List::primenum(int x){
        bool prime = true;
        if(x < 0){
        x = x*(-1);
    for(int i = 2; i <= x/2; i++){
        if(x%i == 0){
            prime = false;
            break;
        }
    }
        }
        else{
    for(int i = 2; i <= x/2; i++){
        if(x%i == 0){
            prime = false;
            break;
        }
    }
        }
    return prime;
}
/*********************************************************************
** Function:count_prime
** Description:calculates the number prime numbers inside of linked list 
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
unsigned int Linked_List::count_prime(){
    current = head;
    int a = 0;
    unsigned int counter = 0;
    bool prime;
    while(current != NULL){
        prime = primenum(current->val);
        if(current->val == 0 || current->val == 2){
            prime = false;
        }
        if(prime == true){
            counter++;
        }   
        current = current->next;
        a++;
    }
    return counter;
}

