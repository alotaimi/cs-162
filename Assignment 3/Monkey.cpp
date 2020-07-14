/******************************************************
** Program: Monkey.cpp
** Author: Mishary Alotaibi
** Date: 05/09/2020
** Description:Everything related to the class
** Input:-
** Output:-
******************************************************/
#include "Monkey.h"
/*********************************************************************
** Function:Monkey
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Monkey::Monkey()
{
    age = 24;
    price = 15000;
    babies = 0;
    foodcost = 0;
    revenue = 1500;
    status = "adult";
    alive = true;
}
/*Monkey::Monkey(int agee, int pricee, int babiese, int foodcoste, int revenuee, string statuse)
{
    age = agee;
    price = pricee;
    babies = babiese;
    foodcost = foodcoste;
    revenue = revenuee;
    status = statuse;
}*/
Monkey::~Monkey() {}

/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
Monkey &Monkey::operator=(const Monkey &x)
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