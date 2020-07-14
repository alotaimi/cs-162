/******************************************************
** Program: pizza.h
** Author: Mishary alotaibi
** Date: 04/26/2020
** Description: Class pizza and defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <fstream>

using namespace std;

class Pizza
{
private:
  string name;
  int small_cost;
  int medium_cost;
  int large_cost;
  int num_ingredients;
  string *ingredients;

public:
  //need to include accessor functions and mutator functions for each private member
  void setname(string x);
  void setsmall_cost(int x);
  void setmedium_cost(int x);
  void setlarge_cost(int x);
  void setnum_ingredients(int x);
  void setingredients(string x, int i);
  string getname();
  int getsetsmall_cost();
  int getsetmedium_cost();
  int getlarge_cost();
  int getnum_ingredients();
  void createTemp();
  void deleteF();
  string getingredients(int x);
  string *getingredientsArray();
  void geting(int x);
  void load_ingredients(string x, int z);
  void createIng(int x);

  //need to include constructors, copy constructors, assignment operator overload,
  //and destructors where appropriate
  Pizza &operator=(const Pizza &old_obj);
  Pizza();
  ~Pizza();
};

#endif