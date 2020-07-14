/******************************************************
** Program: Monkey.h
** Author: Mishary alotaibi
** Date: 5/92020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef MONKEY_H
#define MONKEY_H
#include "Animal.h"
class Monkey : public Animal
{
public:
    Monkey();
    Monkey(int age, int price, int babies, int foodcost, int revenue, string status);
    ~Monkey();
    Monkey &operator=(const Monkey &x);
};
#endif