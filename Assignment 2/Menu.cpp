/******************************************************
** Program: Menu.cpp
** Author: Mishary Alotaibi
** Date: 04/26/2020
** Description:Everything related to the menu
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
** Function:Menu
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Menu::Menu()
{
    setnum_pizzas(0);
    pizzas = NULL;
}
/*********************************************************************
** Function:view_menuorder
** Description:view the orders
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:Displayer
*********************************************************************/
void Menu::view_menuorder()
{

    for (int i = 0; i < num_pizzas; i++)
    {
        cout << " Small " << pizzas[i].getname() << " $" << pizzas[i].getsetsmall_cost() << endl;
        cout << " Medium " << pizzas[i].getname() << " $" << pizzas[i].getsetmedium_cost() << endl;
        cout << " Large " << pizzas[i].getname() << " $" << pizzas[i].getlarge_cost() << endl;
    }
}
/*********************************************************************
** Function:count_line
** Description:counts all the lines in the files
** Parameters:string x
** Pre-Conditions:string
** Post-Conditions:lines counter
*********************************************************************/
int Menu::count_line(string x)
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
/*********************************************************************
** Function:setnum_pizzas
** Description:sets number of pizzas
** Parameters:int x
** Pre-Conditions:int 
** Post-Conditions:sets num_pizzas
*********************************************************************/
void Menu::setnum_pizzas(int x)
{
    this->num_pizzas = x;
}
/*********************************************************************
** Function:createPizzas
** Description:creates a dynamic array
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:Array
*********************************************************************/
void Menu::createPizzas()
{
    int x = count_line("menu.txt");
    setnum_pizzas(x);
    pizzas = new Pizza[this->num_pizzas];
}
/*********************************************************************
** Function:search_pizza_by_cost
** Description:search pizza by cost
** Parameters:int x
** Pre-Conditions:int x 
** Post-Conditions:displays menu
*********************************************************************/
Menu Menu::search_pizza_by_cost(int upper_bound)
{
    Menu Pricemenu;
    int correctpizzas, correctpizzasV2;
    correctpizzas = 0;
    correctpizzasV2 = 0;
    string temp;
    for (int i = 0; i < this->num_pizzas; i++)
    {
        if (pizzas[i].getsetsmall_cost() <= upper_bound)
        {
            correctpizzas++;
        }
        else if (pizzas[i].getsetmedium_cost() <= upper_bound)
        {
            correctpizzas++;
        }
        else if (pizzas[i].getlarge_cost() <= upper_bound)
        {
            correctpizzas++;
        }
    }
    Pricemenu.num_pizzas = correctpizzas;
    Pricemenu.pizzas = new Pizza[correctpizzas];
    cout << correctpizzas << endl;
    //cout << this->num_pizzas << endl;
    for (int i = 0; i < this->num_pizzas; i++)
    {
        if (pizzas[i].getsetsmall_cost() <= upper_bound)
        {
            Pricemenu.pizzas[correctpizzasV2] = pizzas[i];
            correctpizzasV2++;
        }
        else if (pizzas[i].getsetmedium_cost() <= upper_bound)
        {
            Pricemenu.pizzas[correctpizzasV2] = pizzas[i];
            correctpizzasV2++;
        }
        else if (pizzas[i].getlarge_cost() <= upper_bound)
        {
            Pricemenu.pizzas[correctpizzasV2] = pizzas[i];
            correctpizzasV2++;
        }
    }
    return Pricemenu;
} //it was over 15 because i had to check how many pizzas fits the describtion and then show it
/*********************************************************************
** Function:load_menu
** Description:Read the file 
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:loaded arrays
*********************************************************************/
void Menu::load_menu()
{
    string name, ing;
    int small_cost, medium_cost, large_cost, num_ingredients;
    ifstream fin;
    fin.open("menu.txt");
    for (int i = 0; i < this->num_pizzas; i++)
    {
        fin >> name >> small_cost >> medium_cost >> large_cost >> num_ingredients;
        pizzas[i].setname(name);
        pizzas[i].setsmall_cost(small_cost);
        pizzas[i].setmedium_cost(medium_cost);
        pizzas[i].setlarge_cost(large_cost);
        pizzas[i].setnum_ingredients(num_ingredients);
        pizzas[i].getnum_ingredients();
        pizzas[i].createIng(pizzas[i].getnum_ingredients());
        for (int j = 0; j < pizzas[i].getnum_ingredients(); j++)
        {
            fin >> ing;
            pizzas[i].load_ingredients(ing, j);
        }
    }
}
/*********************************************************************
** Function:view_menu
** Description:displayer
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:display of the menu
*********************************************************************/
void Menu::view_menu()
{
    cout << "Updatedlist" << endl;
    for (int i = 0; i < this->num_pizzas; i++)
    {
        cout << pizzas[i].getname() << " " << pizzas[i].getsetsmall_cost() << " " << pizzas[i].getsetmedium_cost() << " " << pizzas[i].getlarge_cost() << " " << pizzas[i].getnum_ingredients() << " ";
        for (int j = 0; j < pizzas[i].getnum_ingredients(); j++)
        {
            cout << pizzas[i].getingredients(j) << " ";
        }
        cout << endl;
    }
}
/*********************************************************************
** Function:additem
** Description:adds an item to menu
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:added item
*********************************************************************/
void Menu::additem()
{
    string name, ingredients;
    int small_cost, medium_cost, large_cost, num_ingredients;
    cout << "What is the name of the item?" << endl;
    cin >> name;
    cout << "How much does it cost for small cost?" << endl;
    while (!(cin >> small_cost))
    {
        cout << "Write numbers" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << "How much does it cost for medium cost?" << endl;
    while (!(cin >> medium_cost))
    {
        cout << "Write numbers" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << "How much does it cost for large cost?" << endl;
    while (!(cin >> large_cost))
    {
        cout << "Write numbers" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << "How many ingredients?" << endl;
    while (!(cin >> num_ingredients))
    {
        cout << "Write numbers" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    Pizza *pizzas_temp = new Pizza[this->num_pizzas + 1];
    cout << this->num_pizzas << endl;
    for (int i = 0; i < this->num_pizzas; i++)
    {
        pizzas_temp[i] = pizzas[i];
    }
    pizzas_temp[this->num_pizzas].setname(name);
    pizzas_temp[this->num_pizzas].setsmall_cost(small_cost);
    pizzas_temp[this->num_pizzas].setmedium_cost(medium_cost);
    pizzas_temp[this->num_pizzas].setlarge_cost(large_cost);
    pizzas_temp[this->num_pizzas].setnum_ingredients(num_ingredients);
    pizzas_temp[this->num_pizzas].createIng(pizzas_temp[this->num_pizzas].getnum_ingredients());
    for (int i = 0; i < pizzas_temp[this->num_pizzas].getnum_ingredients(); i++)
    {
        cout << "For ingredients " << i + 1 << endl;
        cin >> ingredients;
        pizzas_temp[this->num_pizzas].load_ingredients(ingredients, i);
    }
    delete[] pizzas;
    this->pizzas = pizzas_temp;
    this->num_pizzas++;
} //i had to make it more because first i had to check the inputs and then add the extra item
/*********************************************************************
** Function:view_budgemenu
** Description:views the menu by the budget
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:display the menu
*********************************************************************/
void Menu::view_budgemenu()
{
    int budget;
    cout << "What's your Budget?" << endl;
    while (!(cin >> budget))
    {
        cout << "Write numbers" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    Menu temp;
    temp = search_pizza_by_cost(budget);
    for (int i = 0; i < temp.num_pizzas; i++)
    {
        cout << temp.pizzas[i].getname() << " ";
        if (temp.pizzas[i].getlarge_cost() <= budget)
        {
            cout << " S "
                 << "$" << temp.pizzas[i].getsetsmall_cost()
                 << " M " << temp.pizzas[i].getsetmedium_cost()
                 << " L "
                 << "$" << temp.pizzas[i].getlarge_cost() << endl;
        }
        else if (temp.pizzas[i].getsetmedium_cost() <= budget)
        {
            cout << " S "
                 << "$" << temp.pizzas[i].getsetsmall_cost()
                 << " M "
                 << "$" << temp.pizzas[i].getsetmedium_cost() << endl;
        }
        else if (temp.pizzas[i].getsetsmall_cost() <= budget)
        {
            cout << "S "
                 << "$" << temp.pizzas[i].getsetsmall_cost() << endl;
        }
    }
} //it was over because i wanted to make it visually better than just make it regular
/*********************************************************************
** Function:search_pizza_by_ingredients_to_include
** Description:searchs pizza
** Parameters:array of strings , int numbers
** Pre-Conditions:array of strings , int numbers
** Post-Conditions:menu temp
*********************************************************************/
Menu Menu::search_pizza_by_ingredients_to_include(string *ingredients, int num_ingredients)
{
    Menu temp;
    int correctpizza = 0;
    for (int i = 0; i < num_pizzas; i++)
    {
        for (int z = 0; z < pizzas[i].getnum_ingredients(); z++)
        {
            for (int j = 0; j < num_ingredients; j++)
            {
                if (pizzas[i].getingredients(z) == ingredients[j])
                {
                    correctpizza++;
                }
            }
        }
    }
    temp.num_pizzas = correctpizza;
    temp.pizzas = new Pizza[temp.num_pizzas];
    int array = 0;
    for (int i = 0; i < num_pizzas; i++)
    {
        for (int j = 0; j < pizzas[i].getnum_ingredients(); j++)
        {
            for (int z = 0; z < num_ingredients; z++)
            {
                if (pizzas[i].getingredients(j) == ingredients[z])
                {
                    temp.pizzas[array] = pizzas[i];
                    array++;
                }
            }
        }
    }
    return temp;
} //i had to check first how many pizza fits and then copy it to the new array
/*********************************************************************
** Function:search_pizza_by_ingredients_to_exclude
** Description:search pizza
** Parameters:array of strings , int numbers
** Pre-Conditions:array of strings , int numbers
** Post-Conditions:display exclude
*********************************************************************/
Menu Menu::search_pizza_by_ingredients_to_exclude(string *ingredients, int num_ingredients)
{
    Menu temp;
    int correctpizza = 0;
    for (int i = 0; i < num_pizzas; i++)
    {
        for (int z = 0; z < pizzas[i].getnum_ingredients(); z++)
        {
            for (int j = 0; j < num_ingredients; j++)
            {
                if (pizzas[i].getingredients(z) == ingredients[j])
                {
                    correctpizza++;
                }
            }
        }
    }
    correctpizza = this->num_pizzas - correctpizza;
    temp.num_pizzas = correctpizza;
    temp.pizzas = new Pizza[temp.num_pizzas];
    int array = 0;
    bool exit = false;
    for (int i = 0; i < num_pizzas; i++)
    {
        exit = false;
        for (int j = 0; j < pizzas[i].getnum_ingredients(); j++)
        {
            for (int z = 0; z < num_ingredients; z++)
            {
                if (pizzas[i].getingredients(j) == ingredients[z])
                {
                    exit = true;
                    break;
                }
            }
            if (exit)
            {
                break;
            }
            else if (j + 1 == pizzas[i].getnum_ingredients())
            {
                temp.pizzas[array] = pizzas[i];
                //cout << pizzas[i].getname();
                array++;
            }
        }
    }
    return temp;
} //i had to check first how many pizza fits and then copy it to the new array
/*********************************************************************
** Function:view_searchInc
** Description:views the menu
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:view the menu
*********************************************************************/
void Menu::view_searchInc()
{
    int number;
    cout << "How many ingredients would you like to include?" << endl;
    while (!(cin >> number))
    {
        cout << "Write numbers" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    string *ing = new string[number];
    for (int i = 0; i < number; i++)
    {
        cout << i + 1 << " "
             << " Item?" << endl;
        cin >> ing[i];
    }
    Menu temp;
    temp = search_pizza_by_ingredients_to_include(ing, number);
    for (int i = 0; i < temp.num_pizzas; i++)
    {
        cout << temp.pizzas[i].getname() << " " << temp.pizzas[i].getsetsmall_cost() << " " << temp.pizzas[i].getsetmedium_cost() << " " << temp.pizzas[i].getlarge_cost() << " ";
        for (int j = 0; j < temp.pizzas[i].getnum_ingredients(); j++)
        {
            cout << temp.pizzas[i].getingredients(j) << " ";
        }
        cout << endl;
    }
}
/*********************************************************************
** Function:view_searchExc
** Description:views the menu excluded
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:vews the menu
*********************************************************************/
void Menu::view_searchExc()
{
    int number;
    cout << "How many ingredients would you like to include?" << endl;
    while (!(cin >> number))
    {
        cout << "Write numbers" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    string *ing = new string[number];
    for (int i = 0; i < number; i++)
    {
        cout << i + 1 << " "
             << " Item?" << endl;
        cin >> ing[i];
    }
    Menu temp;
    temp = search_pizza_by_ingredients_to_exclude(ing, number);
    for (int i = 0; i < temp.num_pizzas; i++)
    {
        cout << temp.pizzas[i].getname() << " " << temp.pizzas[i].getsetsmall_cost() << " " << temp.pizzas[i].getsetmedium_cost() << " " << temp.pizzas[i].getlarge_cost() << " ";
        for (int j = 0; j < temp.pizzas[i].getnum_ingredients(); j++)
        {
            cout << temp.pizzas[i].getingredients(j) << " ";
        }
        cout << endl;
    }
}
/*********************************************************************
** Function:removeitem
** Description:removes an item from the menu
** Parameters:string 
** Pre-Conditions:string 
** Post-Conditions:removed item
*********************************************************************/
void Menu::removeitem(string name)
{
    int idx = -1;
    for (int i = 0; i < this->num_pizzas; i++)
    {
        if (this->pizzas[i].getname() == name)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "Pizza was not found" << endl;
        return;
    }
    for (int i = idx; i < this->num_pizzas - 1; i++)
    {
        this->pizzas[i] = this->pizzas[i + 1];
    }
    this->num_pizzas--;
}
/*********************************************************************
** Function:AOO for menu
** Description:copys everything
** Parameters:menu class
** Pre-Conditions:menu class
** Post-Conditions:returns the copied object
*********************************************************************/
Menu &Menu::operator=(const Menu &old_obj)
{
    //cout << "Operator" << endl;
    if (this != &old_obj)
    {
        this->num_pizzas = old_obj.num_pizzas;
        if (this->pizzas != NULL)
        {
            delete[] this->pizzas;
        }
        this->pizzas = new Pizza[this->num_pizzas];
        for (int i = 0; i < this->num_pizzas; i++)
        {
            this->pizzas[i] = old_obj.pizzas[i];
        }
    }
    return *this;
}
/*********************************************************************
** Function:Updatedlist
** Description:updates the files
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:updated files
*********************************************************************/
void Menu::Updatedlist()
{
    ofstream file;
    file.open("menu.txt");
    for (int i = 0; i < this->num_pizzas; i++)
    {
        file << pizzas[i].getname() << " " << pizzas[i].getsetsmall_cost() << " " << pizzas[i].getsetmedium_cost() << " " << pizzas[i].getlarge_cost() << " " << pizzas[i].getnum_ingredients() << " ";
        for (int j = 0; j < pizzas[i].getnum_ingredients(); j++)
        {
            file << pizzas[i].getingredients(j) << " ";
        }
        file << endl;
    }
}
/*********************************************************************
** Function:~Menu
** Description:delete the array
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:deletes the array
*********************************************************************/
Menu::~Menu()
{
    delete[] pizzas;
}