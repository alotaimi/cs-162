#ifndef PIZZA_H
#define PIZZA_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

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
  int num_pizzas;

public:
  Pizza();
  void set_name(string name);
  string get_name();
  void createing();
  int count_line(string x);
  int counter(string x);
  void setnum_pizza(int x);
  void set_num_ingredients(int num);
  int get_num_ingredients();
  void set_from_file();
  void populate_pizza(ifstream &);
};

#endif