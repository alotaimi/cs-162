/******************************************************
** Program: Pizza.cpp
** Author: Mishary Alotaibi
** Date: 04/26/2020
** Description:Everything related to Pizzas
** Input:-
** Output:-
******************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "restaurant.h"
/*********************************************************************
** Function:Setters
** Description:Sets everything inside of the class
** Parameters:
** Pre-Conditions: 
** Post-Conditions:Sets everything inside of the class
*********************************************************************/
void Pizza::setname(string x)
{
    this->name = x;
}
void Pizza::setsmall_cost(int x)
{
    this->small_cost = x;
}

void Pizza::setmedium_cost(int x)
{
    this->medium_cost = x;
}
void Pizza::setlarge_cost(int x)
{
    this->large_cost = x;
}
void Pizza::setnum_ingredients(int x)
{
    this->num_ingredients = x;
}
/*********************************************************************
** Function:Getters
** Description:getter everything inside of the class
** Parameters:
** Pre-Conditions: 
** Post-Conditions:getter everything inside of the class
*********************************************************************/
string Pizza::getname()
{
    return this->name;
}
int Pizza::getsetsmall_cost()
{
    return this->small_cost;
}
string *Pizza::getingredientsArray()
{
    return ingredients;
}
int Pizza::getsetmedium_cost()
{
    return this->medium_cost;
}
int Pizza::getlarge_cost()
{
    return this->large_cost;
}
int Pizza::getnum_ingredients()
{
    return this->num_ingredients;
}
void Pizza::setingredients(string x, int i)
{
    ingredients[i] = x;
}
string Pizza::getingredients(int x)
{
    return ingredients[x];
}
void Pizza::geting(int x)
{
    for (int i = 0; i < x; i++)
    {
        cout << ingredients[i] << endl;
    }
}
/*********************************************************************
** Function:Constructer
** Description:Constructer that initialize everything
** Parameters:
** Pre-Conditions: 
** Post-Conditions:Constructer that initialize everything
*********************************************************************/
Pizza::Pizza()
{
    setname(" ");
    setsmall_cost(0);
    setmedium_cost(0);
    setlarge_cost(0);
    setnum_ingredients(0);
    ingredients = NULL;
}
/*********************************************************************
** Function:createIng
** Description:creates an array
** Parameters:int x
** Pre-Conditions: int x
** Post-Conditions:creates an array
*********************************************************************/
void Pizza::createIng(int x)
{
    ingredients = new string[x];
}
/*********************************************************************
** Function:load_ingredients
** Description:loads everything for ingredients
** Parameters:string x , int x
** Pre-Conditions: string x , int x
** Post-Conditions:loads everything for ingredients
*********************************************************************/
void Pizza::load_ingredients(string x, int z)
{
    ingredients[z] = x;
}
/*********************************************************************
** Function:createTemp
** Description:creates an array
** Parameters:-
** Pre-Conditions: -
** Post-Conditions:creates an array
*********************************************************************/
void Pizza::createTemp()
{
    string *ingredients_temp = new string[this->num_ingredients];
}
/*********************************************************************
** Function:AOO for Pizza
** Description:copys everything
** Parameters:old object
** Pre-Conditions: 
** Post-Conditions:copys everything
*********************************************************************/
Pizza &Pizza::operator=(const Pizza &old_obj)
{
    this->name = old_obj.name;
    this->small_cost = old_obj.small_cost;
    this->medium_cost = old_obj.medium_cost;
    this->large_cost = old_obj.large_cost;
    this->num_ingredients = old_obj.num_ingredients;
    if (this->ingredients != NULL)
    {
        delete[] this->ingredients;
    }
    this->ingredients = new string[this->num_ingredients];
    for (int i = 0; i < this->num_ingredients; i++)
    {
        this->ingredients[i] = old_obj.ingredients[i];
    }
    return *this;
}
/*********************************************************************
** Function:~Pizza
** Description:Destructer thats delete everytthing
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:Destructer thats delete everytthing
*********************************************************************/
Pizza::~Pizza()
{
    delete[] ingredients;
}