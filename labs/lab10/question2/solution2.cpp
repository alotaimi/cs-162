#include <iostream>
using namespace std;
#include "list.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* current = head;
    int a = 0;
    int b = 0;
    while(current != NULL){
        a++;
        current = current->next;
    }
    if(n != 1){
        a = a - n;
    }
    if(a == 0){
            head->val = head->next->val;
            current = head->next;
            head->next = head->next->next;
    }
    else{
    current = head;
    while(current != NULL){
        current = current->next;
        if(b == a){
            current->next = current->next->next;
        }
        b++;
    }
    }
    current = head;
    while(current != NULL){
        cout << current->val<<" ";
        current = current->next;
    }
    current = head;
    return current;
}
