#include <iostream>
#include <fstream>
#include "pizza.h"
using namespace std;

int Pizza::count_line(string x)
{
    string line;
    int counter = 0;
    ifstream fin;
    fin.open(x.c_str());
    while (!fin.eof())
    {
        getline(fin, line);
        counter++;
    }
    fin.close();
    return counter - 1;
}
void Pizza::populate_pizza()
{
}

Pizza::Pizza()
{
    ingredients = NULL;
    int small_cost, medium_cost, large_cost, num_ingredients, num_pizzas = 0;
}

void Pizza::setnum_pizza(int x)
{
    this->num_pizzas = x;
}
void Pizza::set_name(string x)
{
    this->name = x;
}
string Pizza::get_name()
{
    return name;
}
void Pizza::set_num_ingredients(int num)
{
    this->num_ingredients = num;
}
int Pizza::get_num_ingredients()
{
    return this->num_ingredients;
}