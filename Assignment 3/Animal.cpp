/******************************************************
** Program: Animal.cpp
** Author: Mishary Alotaibi
** Date: 05/09/2020
** Description:Everything related to the class
** Input:-
** Output:-
******************************************************/
#include "Animal.h"
/*********************************************************************
** Function:Animal
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Animal::Animal()
{
    age = 0;
    price = 0;
    babies = 0;
    foodcost = 0;
    revenue = 0;
    status = "Animal";
}
/*********************************************************************
** Function:~Animal
** Description:desterctuor
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Animal::~Animal() {}

/*********************************************************************
** Function:Setters
** Description:sets all the variables
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Animal::setage(int x)
{
    age = x;
}
void Animal::setprice(int x)
{
    price = x;
}
void Animal::setbabies(int x)
{
    babies = x;
}
void Animal::setfoodcost(int x)
{
    foodcost = x;
}
void Animal::setrevenue(int x)
{
    revenue = x;
}
void Animal::setstatus(string x)
{
    status = x;
}
void Animal::setalive(bool x)
{
    alive = x;
}
void Animal::setfoodcostt(int x, int z){
        foodcost = x * z;
}
/*********************************************************************
** Function:getters
** Description:gets all the variables
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
int Animal::getage()
{
    return age;
}
int Animal::getprice()
{
    return price;
}
int Animal::getbabies()
{
    return babies;
}
int Animal::getfoodcost()
{
    return foodcost;
}
int Animal::getrevenue()
{
    return revenue;
}
string Animal::getstatus()
{
    return status;
}
bool Animal::getalive()
{
    return alive;
}
/*********************************************************************
** Function:AOO for class
** Description:copys everything
** Parameters: class
*********************************************************************/
Animal &Animal::operator=(const Animal &old_obj)
{
    this->age = old_obj.age;
    this->price = old_obj.price;
    this->babies = old_obj.babies;
    this->foodcost = old_obj.foodcost;
    this->revenue = old_obj.revenue;
    this->status = old_obj.status;
    return *this;
}