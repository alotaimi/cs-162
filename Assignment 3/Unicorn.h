/******************************************************
** Program: Unicorn.h
** Author: Mishary alotaibi
** Date: 5/92020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef Unicorn_H
#define Unicorn_H
#include "Animal.h"
class Unicorn : public Animal
{
public:
    Unicorn();
    ~Unicorn();
    Unicorn &operator=(const Unicorn &x);
};
#endif