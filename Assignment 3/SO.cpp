/******************************************************
** Program: SO.cpp
** Author: Mishary Alotaibi
** Date: 05/09/2020
** Description:Everything related to the class
** Input:-
** Output:-
******************************************************/
#include "SO.h"
/*********************************************************************
** Function:SO
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
SO::SO()
{
    age = 24;
    price = 5000;
    babies = 0;
    foodcost = 0;
    revenue = 250;
    status = "adult";
    alive = true;
}
/*SO::SO(int agee, int pricee, int babiese, int foodcoste, int revenuee, string statuse)
{
    age = agee;
    price = pricee;
    babies = babiese;
    foodcost = foodcoste;
    revenue = revenuee;
    status = statuse;
}*/
SO::~SO() {}
/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
SO &SO::operator=(const SO &x)
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