/******************************************************
** Program: Sloth.h
** Author: Mishary alotaibi
** Date: 5/92020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef SLOTH_H
#define SLOTH_H
#include "Animal.h"
class Sloth : public Animal
{
public:
    Sloth();
    Sloth(int age, int price, int babies, int foodcost, int revenue, string status);
    ~Sloth();
    Sloth &operator=(const Sloth &x);
};
#endif