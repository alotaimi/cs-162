/*#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "restaurant.h"

int Restaurant::count_line(string x)
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

Restaurant::Restaurant()
{
  employees = NULL;
  week = NULL;
  order = NULL;
  name = " ";
  phone = " ";
  address = " ";
}
Restaurant::~Restaurant()
{
  delete[] week;
  delete[] employees;
  delete[] order;
}
void Restaurant::createEmp()
{
  int num_employees = count_line("employee.txt");
  setnumEmp(num_employees);
  employees = new employee[this->num_Emp];
}
void Restaurant::createOrders()
{
  int num_orders = count_line("orders.txt");
  setnum_orders(num_orders);
  order = new orders[this->num_orders];
}
void Restaurant::setnum_orders(int x)
{
  this->num_orders = x;
}
void Restaurant::load_dataEmp()
{
  ifstream employee_file;
  employee_file.open("employee.txt");
  int num_employee = count_line("employee.txt");

  for (int i = 0; i < this->num_Emp; i++)
  {
    employee_file >> employees[i].id >> employees[i].password >> employees[i].first_name >> employees[i].last_name;
  }
  employee_file.close();
}
Restaurant::Restaurant(const Restaurant &old_obj)
{
  cout << "Copy Constructor" << endl;
  this->name = old_obj.name;
  this->phone = old_obj.phone;
  this->address = old_obj.address;
  this->num_hours = old_obj.num_hours;
  this->num_Emp = old_obj.num_Emp;
  this->num_orders = old_obj.num_orders;
  this->employees = new employee[this->num_Emp];
  for (int i = 0; i < this->num_Emp; i++)
  {
    this->employees[i] = old_obj.employees[i];
  }
  this->week = new hours[this->num_hours];
  for (int i = 0; i < this->num_hours; i++)
  {
    week[i] = old_obj.week[i];
  }
}
Restaurant &Restaurant::operator=(const Restaurant &old_obj)
{
  cout << "Operator" << endl;
  if (this != &old_obj)
  {
    this->name = old_obj.name;
    this->phone = old_obj.phone;
    this->address = old_obj.address;
    this->num_hours = old_obj.num_hours;
    this->num_Emp = old_obj.num_Emp;
    this->num_orders = old_obj.num_orders;
    if (this->employees != NULL)
    {
      delete[] this->employees;
      this->employees = new employee[this->num_Emp];
      for (int i = 0; i < this->num_Emp; i++)
      {
        this->employees[i] = old_obj.employees[i];
      }
    }
    if (this->week != NULL)
    {
      delete[] this->week;
      this->week = new hours[this->num_hours];
      for (int i = 0; i < this->num_hours; i++)
      {
        week[i] = old_obj.week[i];
      }
    }
  }
  return *this;
}
void Restaurant::add_to_menu()
{
  menu.additem();
}
void Restaurant::createHours()
{
  int num_hours = count_line("restaurant_info.txt");
  num_hours = num_hours - 3;
  sethours(num_hours);
  week = new hours[this->num_hours];
}
void Restaurant::load_dataOrders()
{
  ifstream order_file;
  order_file.open("orders.txt");
  string temp = "";
  string holder = "";
  int section = 0;
  for (int i = 0; i < num_orders; i++)
  {
    getline(order_file, temp);
    //cout << temp << endl;
    holder = "";
    section = 0;
    //cout << temp.length() << endl;
    for (int j = 0; j < temp.length() - 1; j++)
    {
      if (temp[j] != ' ')
      {
        holder += temp[j];
        if (j + 2 == temp.length())
        {
          order[i].order += temp[j];
        }
      }
      else
      {
        if (section == 0)
        {
          //cout << holder << endl;
          order[i].num_order = atoi(holder.c_str());
        }
        else if (section == 1)
        {
          //cout << holder << endl;
          order[i].name_order = holder;
        }
        else if (section == 2)
        {
          //cout << holder << endl;
          order[i].credit_num = holder;
        }
        else if (section == 3)
        {
          //cout << holder << endl;
          order[i].phone_num = holder;
        }
        else
        {
          order[i].order += holder + " ";
        }
        holder = "";
        section++;
      }
    }
    //cout << order[i].order << endl;
  }
  order_file.close();
}
void Restaurant::view_orders()
{
  for (int i = 0; i < num_orders; i++)
  {
    cout << order[i].num_order << " " << order[i].name_order << " " << order[i].credit_num << " " << order[i].phone_num << " " << order[i].order << endl;
  }
}
void Restaurant::load_dataHours()
{
  ifstream restaurant_file;
  restaurant_file.open("restaurant_info.txt");
  string line1, line2, line3, name, phone, address;
  getline(restaurant_file, name);
  getline(restaurant_file, phone);
  getline(restaurant_file, address);
  setaddress(address);
  setname(name);
  setphone(phone);
  for (int i = 0; i < this->num_hours; i++)
  {
    restaurant_file >> line1 >> line2 >> line3;
    week[i].day = line1;
    week[i].open_hour = line2;
    week[i].close_hour = line3;
  }
}
void Restaurant::create()
{
  createEmp();
  createHours();
  menu.createPizzas();
  createOrders();
}
void Restaurant::load_data()
{
  load_dataEmp();
  load_dataHours();
  menu.load_menu();
  load_dataOrders();
}
void Restaurant::view_hours()
{
  cout << "The Updated Hours:" << endl;
  for (int i = 0; i < this->num_hours; i++)
  {
    cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
  }
}
void Restaurant::add_hours()
{
  string day, open, close;
  cout << "Which day would you like to change?" << endl;
  cin >> day;
  cout << "When is the openning hour?" << endl;
  cin >> open;
  cout << "When is the closing hour?" << endl;
  cin >> close;
  hours *week_temp = new hours[this->num_hours + 1];
  for (int i = 0; i < this->num_hours; i++)
  {
    week_temp[i] = this->week[i];
  }
  week_temp[this->num_hours].day = day;
  week_temp[this->num_hours].open_hour = open;
  week_temp[this->num_hours].close_hour = close;
  if (this->week != NULL)
  {
    delete[] this->week;
  }
  this->week = week_temp;
  this->num_hours++;
}
void Restaurant::change_hours()
{
  string day, open, close;
  cout << "Which day would you like to change the hours?" << endl;
  cin >> day;
  for (int i = 0; i < this->num_hours; i++)
  {
    if (day == week[i].day)
    {
      cout << "When do you want the openning hours?" << endl;
      cin >> open;
      cout << "When do you want the closing hours?" << endl;
      cin >> close;
      week[i].open_hour = open;
      week[i].close_hour = close;
    }
  }
}
bool Restaurant::login(int id, string password)
{
  for (int i = 0; i < this->num_Emp; i++)
  {
    if (employees[i].id == id)
    {
      if (this->employees[i].password == password)
      {
        cout << "Welcome:" << employees[i].first_name << " " << employees[i].last_name << endl;
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }
}
void Restaurant::place_order()
{
  int choice;
  menu.view_menuorder();
  cout << "what would you like to choose? ";
  cin >> choice;
}
void Restaurant::setaddress(string x)
{
  this->address = x;
}
void Restaurant::setphone(string z)
{
  this->phone = z;
}
void Restaurant::setname(string z)
{
  this->name = z;
}
void Restaurant::view_address()
{
  cout << "Our address is: " << this->address << endl;
}
void Restaurant::view_phone()
{
  cout << "You can contact us by phone: " << this->phone << endl;
}
void Restaurant::view_name()
{
  cout << "The name of tthe restaurant is: " << this->name << endl;
}
void Restaurant::sethours(int x)
{
  this->num_hours = x;
}
void Restaurant::setnumEmp(int x)
{
  this->num_Emp = x;
}
void Restaurant::UpdatedHours()
{
  ofstream saveHours;
  saveHours.open("restaurant_info.txt");
  saveHours << this->name << endl;
  saveHours << this->phone << endl;
  saveHours << this->address << endl;
  for (int i = 0; i < this->num_hours; i++)
  {
    saveHours << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
  }
}
void Restaurant::UpdateOders()
{
  ofstream Orders;
  Orders.open("orders.txt");
  for (int i = 0; i < this->num_orders; i++)
  {
    Orders << order[i].num_order << " " << order[i].name_order << " " << order[i].credit_num << " " << order[i].phone_num << " " << order[i].order << endl;
  }
  Orders.close();
}
void Restaurant::remove_orders()
{
  int number;
  cout << "Which order would you like to remove?" << endl;
  cin >> number;
  int idx = -1;
  for (int i = 0; i < this->num_orders; i++)
  {
    if (this->order[i].num_order == number)
    {
      idx = i;
      break;
    }
  }
  if (idx == -1)
  {
    cout << "Oder was not found" << endl;
    return;
  }
  for (int i = idx; i < this->num_orders - 1; i++)
  {
    this->order[i].name_order = this->order[i + 1].name_order;
    this->order[i].credit_num = this->order[i + 1].credit_num;
    this->order[i].phone_num = this->order[i + 1].phone_num;
    this->order[i].order = this->order[i + 1].order;
  }
  this->num_orders--;
}
void Restaurant::view_menu()
{
  menu.view_menu();
}
void Restaurant::remove_from_menu()
{
  string x;
  cout << "Which Pizza would you like to remove? Please write the name of the pizza" << endl;
  cin >> x;
  menu.removeitem(x);
}
void Restaurant::view_menu_cost()
{
  menu.view_budgemenu();
}
void Restaurant::view_ing()
{
  menu.view_search();
}
void Restaurant::UpdatedMenu()
{
  menu.Updatedlist();
}*/
//**********************************************************************************************************Menu Class
/*Menu::Menu()
{
  setnum_pizzas(0);
  pizzas = NULL;
}
void Menu::view_menuorder()
{
  for (int i = 0; i < num_pizzas; i++)
  {
    if (i == 0)
    {
      cout << i + 1 << " Small " << pizzas[i].getname() << " $" << pizzas[i].getsetsmall_cost() << endl;
      cout << i + 2 << " Medium " << pizzas[i].getname() << " $" << pizzas[i].getsetmedium_cost() << endl;
      cout << i + 3 << " Large " << pizzas[i].getname() << " $" << pizzas[i].getlarge_cost() << endl;
    }
    else if (i == 1)
    {
      cout << i + 3 << " Small " << pizzas[i].getname() << " $" << pizzas[i].getsetsmall_cost() << endl;
      cout << i + 4 << " Medium " << pizzas[i].getname() << " $" << pizzas[i].getsetmedium_cost() << endl;
      cout << i + 5 << " Large " << pizzas[i].getname() << " $" << pizzas[i].getlarge_cost() << endl;
    }
    else if (i == 2)
    {
      cout << i + 5 << " Small " << pizzas[i].getname() << " $" << pizzas[i].getsetsmall_cost() << endl;
      cout << i + 6 << " Medium " << pizzas[i].getname() << " $" << pizzas[i].getsetmedium_cost() << endl;
      cout << i + 7 << " Large " << pizzas[i].getname() << " $" << pizzas[i].getlarge_cost() << endl;
    }
    else if (i == 3)
    {
      cout << i + 7 << " Small " << pizzas[i].getname() << " $" << pizzas[i].getsetsmall_cost() << endl;
      cout << i + 8 << " Medium " << pizzas[i].getname() << " $" << pizzas[i].getsetmedium_cost() << endl;
      cout << i + 9 << " Large " << pizzas[i].getname() << " $" << pizzas[i].getlarge_cost() << endl;
    }
    else if (i == 4)
    {
      cout << i + 9 << " Small " << pizzas[i].getname() << " $" << pizzas[i].getsetsmall_cost() << endl;
      cout << i + 10 << " Medium " << pizzas[i].getname() << " $" << pizzas[i].getsetmedium_cost() << endl;
      cout << i + 11 << " Large " << pizzas[i].getname() << " $" << pizzas[i].getlarge_cost() << endl;
    }
    else if (i == 5)
    {
      cout << i + 11 << " Small " << pizzas[i].getname() << " $" << pizzas[i].getsetsmall_cost() << endl;
      cout << i + 12 << " Medium " << pizzas[i].getname() << " $" << pizzas[i].getsetmedium_cost() << endl;
      cout << i + 13 << " Large " << pizzas[i].getname() << " $" << pizzas[i].getlarge_cost() << endl;
    }
  }
}
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
void Menu::setnum_pizzas(int x)
{
  this->num_pizzas = x;
}
void Menu::createPizzas()
{
  int x = count_line("menu.txt");
  setnum_pizzas(x);
  pizzas = new Pizza[this->num_pizzas];
}
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
}
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

void Menu::additem()
{
  string name, ingredients;
  int small_cost, medium_cost, large_cost, num_ingredients;
  cout << "What is the name of the item?" << endl;
  cin >> name;
  cout << "How much does it cost for small cost?" << endl;
  cin >> small_cost;
  cout << "How much does it cost for medium cost?" << endl;
  cin >> medium_cost;
  cout << "How much does it cost for large cost?" << endl;
  cin >> large_cost;
  cout << "How many ingredients?" << endl;
  cin >> num_ingredients;
  Pizza *pizzas_temp = new Pizza[this->num_pizzas + 1];
  cout << this->num_pizzas << endl;
  for (int i = 0; i < this->num_pizzas; i++)
  {
    /*pizzas_temp[i].setname(pizzas[i].getname());
    pizzas_temp[i].setsmall_cost(pizzas[i].getsetsmall_cost());
    pizzas_temp[i].setmedium_cost(pizzas[i].getsetmedium_cost());
    pizzas_temp[i].setlarge_cost(pizzas[i].getlarge_cost());
    pizzas_temp[i].setnum_ingredients(pizzas[i].getnum_ingredients());*/
/*  pizzas_temp[i] = pizzas[i];
    /*pizzas_temp[i].createIng(pizzas_temp[i].getnum_ingredients());
    for (int j = 0; j < pizzas_temp[i].getnum_ingredients(); j++)
    {
      pizzas_temp[i].load_ingredients(pizzas[i].getingredients(j), j);
    }*/
//}
/*pizzas_temp[this->num_pizzas].setname(name);
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
  /*for (int i = 0; i < this->num_pizzas; i++)
  {
    for (int j = 0; j < pizzas[i].getnum_ingredients(); j++)
    {
      pizzas[i].load_ingredients(pizzas_temp[i].getingredients(j), j);
    }
  }*/
/*  this->num_pizzas++;
}
void Menu::view_budgemenu()
{
  int budget;
  cout << "What's your Budget?" << endl;
  cin >> budget;
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
}

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
        //cout << "   " << j << endl;
        if (pizzas[i].getingredients(z) == ingredients[j])
        {
          //temp.pizzas[correctpizza] = pizzas[i];
          correctpizza++;
          //cout << correctpizza << endl;
        }
      }
    }
  }
  //cout << correctpizza << endl;
  temp.num_pizzas = correctpizza;
  temp.pizzas = new Pizza[temp.num_pizzas];
  //correctpizza = 0;
  for (int z = 0; z < temp.num_pizzas; z++)
  {
    for (int i = 0; i < num_pizzas; i++)
    {
      //for (int z = 0; z < temp.num_pizzas; z++)
      //{
      for (int j = 0; j < num_ingredients; j++)
      {
        if (pizzas[i].getingredients(j) == ingredients[j])
        {
          temp.pizzas[z] = pizzas[i];
        }
      }
    }
  }
  return temp;
}
bool Menu::checker(string *x, int z)
{
  for (int i = 0; i < num_pizzas; i++)
  {
    for (int j = 0; j < pizzas[i].getnum_ingredients(); j++)
    {
      if (pizzas[i].getingredients(j) == x[z])
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }
}
void Menu::view_search()
{
  int number;
  cout << "How many ingredients would you like to include?" << endl;
  cin >> number;
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
Menu::~Menu()
{
  delete[] pizzas;
}*/
//**********************************************************************************************************Pizza Class

/*void Pizza::setname(string x)
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
Pizza::Pizza()
{
  setname(" ");
  setsmall_cost(0);
  setmedium_cost(0);
  setlarge_cost(0);
  setnum_ingredients(0);
  ingredients = NULL;
}
void Pizza::createIng(int x)
{
  ingredients = new string[x];
}
void Pizza::load_ingredients(string x, int z)
{
  ingredients[z] = x;
}
void Pizza::createTemp()
{
  string *ingredients_temp = new string[this->num_ingredients];
}
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
Pizza::~Pizza()
{
  delete[] ingredients;
}*/