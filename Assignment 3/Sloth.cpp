/******************************************************
** Program: Sloth.cpp
** Author: Mishary Alotaibi
** Date: 05/09/2020
** Description:Everything related to the class
** Input:-
** Output:-
******************************************************/
#include "Sloth.h"
/*********************************************************************
** Function:Sloth
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Sloth::Sloth()
{
    age = 24;
    price = 2000;
    babies = 0;
    foodcost = 0;
    revenue = 100;
    status = "adult";
    alive = true;
}
/*Sloth::Sloth(int agee, int pricee, int babiese, int foodcoste, int revenuee, string statuse)
{
    age = agee;
    price = pricee;
    babies = babiese;
    foodcost = foodcoste;
    revenue = revenuee;
    status = statuse;
}*/
Sloth::~Sloth() {}
/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
Sloth &Sloth::operator=(const Sloth &x)
{
    this->age = x.age;
    this->price = x.price;
    this->babies = x.babies;
    this->foodcost = x.foodcost;
    this->revenue = x.revenue;
    this->status = x.status;
    this->alive = x.alive;
    return *this;
}