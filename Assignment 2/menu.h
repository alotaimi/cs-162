/******************************************************
** Program: menu.h
** Author: Mishary alotaibi
** Date: 04/26/2020
** Description: Class menu and defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef MENU_H
#define MENU_H

#include <string>
#include <fstream>
#include "pizza.h"

using namespace std;

class Menu
{
private:
  int num_pizzas;
  Pizza *pizzas;

public:
  //need to include accessor functions and mutator functions for each private member
  void setnum_pizzas(int x);
  void createPizzas();
  //need to include constructors, copy constructors, assignment operator overload,
  Menu();
  ~Menu();
  void view_menu();
  void additem();
  void Updatedlist();
  void view_menuorder();
  void removeitem(string name);
  bool checker(string *x, int z);
  //and destructors where appropriate
  void load_menu();
  int count_line(string x);
  // Only one of the following two prototypes should be used:
  Menu search_pizza_by_cost(int upper_bound);
  void view_budgemenu();
  //Menu search_pizza_by_cost(int upper_bound, string size);
  void view_searchInc();
  Menu search_pizza_by_ingredients_to_include(string *ingredients, int num_ingredients);
  Menu search_pizza_by_ingredients_to_exclude(string *ingredients, int num_ingredients);
  void view_searchExc();
  void add_to_menu(Pizza pizza_to_add);
  void remove_from_menu(int index_of_pizza_on_menu);
  Menu &operator=(const Menu &old_obj);
};

#endif