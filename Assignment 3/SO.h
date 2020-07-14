/******************************************************
** Program: SO.h
** Author: Mishary alotaibi
** Date: 5/92020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef SO_H
#define SO_H
#include "Animal.h"
class SO : public Animal
{
public:
    SO();
    SO(int age, int price, int babies, int foodcost, int revenue, string status);
    ~SO();
    SO &operator=(const SO &x);
};
#endif