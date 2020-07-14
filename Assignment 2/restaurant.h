/******************************************************
** Program: restaurant.h
** Author: Mishary alotaibi
** Date: 04/26/2020
** Description: Class restaurant and defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "emp_hours.h"

using namespace std;

class Restaurant
{
private:
  Menu menu;
  employee *employees;
  hours *week;
  orders *order;
  string name;
  string phone;
  string address;
  int num_hours;
  int num_Emp;
  int num_menu;
  int num_orders;

public:
  //need to include accessor functions and mutator functions for each private member
  Restaurant();
  ~Restaurant();
  Restaurant(const Restaurant &);
  Restaurant &operator=(const Restaurant &);
  void createEmp();
  void createHours();
  void create();
  void createOrders();
  int count_line(string x);
  void UpdatedHours();
  void UpdatedMenu();
  void UpdateOders();
  //need to include constructors, copy constructors, assignment operator overload,
  //and destructors where appropriate
  void load_data();
  void load_dataEmp(); //reads from files to correctly populate menu, employees, hours, etc.
  void load_dataHours();
  void load_dataMenu();
  void load_dataOrders();
  void sethours(int x);
  bool login(int id, string password);
  void view_menu();
  void view_hours();
  void view_address();
  void setaddress(string x);
  void view_phone();
  void view_name();
  void setnum_orders(int x);
  void setphone(const string z);
  void setname(string x);
  void setnumEmp(int x);
  void setaddressphone(int x);
  void search_menu_by_price();
  void search_by_ingredients();
  void add_hours();
  void view_menu_cost();
  void view_ingInc();
  void view_ingExc();
  // Only one of the following two prototypes should be used:
  // selection is a dynamically allocated array of Pizza objects that are being ordered
  // selection_size indicates the number of Pizza objects in the array
  // num_ordered is a dynamically allocated array that indicates how many pizzas of each type were ordered
  //void place_order(Pizza *selection, int selection_size, int *num_ordered);
  // you may also choose to use this prototype:
  //void place_order(Pizza* selection);
  void place_order();

  void change_hours();
  void add_to_menu();
  void remove_from_menu();
  void view_orders();
  void remove_orders();
};

#endif