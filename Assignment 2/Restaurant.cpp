/******************************************************
** Program: Restaurant.cpp
** Author: Mishary Alotaibi
** Date: 04/26/2020
** Description:Everything related to Restaurant
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
** Function:count_line
** Description:counts all the lines in the files
** Parameters:string x
** Pre-Conditions:string
** Post-Conditions:lines counter
*********************************************************************/
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
/*********************************************************************
** Function:Restaurant
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Restaurant::Restaurant()
{
    employees = NULL;
    week = NULL;
    order = NULL;
    name = " ";
    phone = " ";
    address = " ";
}
/*********************************************************************
** Function:~Restaurant
** Description:deletes everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:deleted arrays
*********************************************************************/
Restaurant::~Restaurant()
{
    delete[] week;
    delete[] employees;
    delete[] order;
}
/*********************************************************************
** Function:createEmp
** Description:creates an array 
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:creates an array
*********************************************************************/
void Restaurant::createEmp()
{
    int num_employees = count_line("employee.txt");
    setnumEmp(num_employees);
    employees = new employee[this->num_Emp];
}
/*********************************************************************
** Function:createOrders
** Description:creates an array 
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:creates an array 
*********************************************************************/
void Restaurant::createOrders()
{
    int num_orders = count_line("orders.txt");
    setnum_orders(num_orders);
    order = new orders[this->num_orders];
}
/*********************************************************************
** Function:setnum_orders
** Description:sets number of orders
** Parameters:int x
** Pre-Conditions:int x
** Post-Conditions:sets number of orders
*********************************************************************/
void Restaurant::setnum_orders(int x)
{
    this->num_orders = x;
}
/*********************************************************************
** Function:load_dataEmp
** Description:loads employee file
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:loads employee file
*********************************************************************/
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
/*********************************************************************
** Function:Restaurant
** Description:copy constructer
** Parameters:Restaurant &old_obj
** Pre-Conditions:Restaurant &old_obj
** Post-Conditions:copys
*********************************************************************/
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
/*********************************************************************
** Function:AOO for Restaurant
** Description:copys everything 
** Parameters:Restaurant &old_obj
** Pre-Conditions:Restaurant &old_obj
** Post-Conditions:copied new object
*********************************************************************/
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
} //To copy everytthing inside of the old object
/*********************************************************************
** Function:add_to_menu
** Description:adds an item
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:adds an item
*********************************************************************/
void Restaurant::add_to_menu()
{
    menu.additem();
}
/*********************************************************************
** Function:createHours
** Description:creates an array
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:creates an array
*********************************************************************/
void Restaurant::createHours()
{
    int num_hours = count_line("restaurant_info.txt");
    num_hours = num_hours - 3;
    sethours(num_hours);
    week = new hours[this->num_hours];
}
/*********************************************************************
** Function:load_dataOrders
** Description:fill all the orders 
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:fill all the orders 
*********************************************************************/
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
        holder = "";
        section = 0;
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
                    order[i].num_order = atoi(holder.c_str());
                }
                else if (section == 1)
                {
                    order[i].name_order = holder;
                }
                else if (section == 2)
                {
                    order[i].credit_num = holder;
                }
                else if (section == 3)
                {
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
    }
    order_file.close();
} //It was over 15 because i had to add each string to one big string to make for orders
/*********************************************************************
** Function:view_orders
** Description:views all orders
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:views all orders
*********************************************************************/
void Restaurant::view_orders()
{
    for (int i = 0; i < num_orders; i++)
    {
        cout << order[i].num_order << " " << order[i].name_order << " " << order[i].credit_num << " " << order[i].phone_num << " " << order[i].order << endl;
    }
}
/*********************************************************************
** Function:load_dataHours
** Description:fill all the hours
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:fill all the hours
*********************************************************************/
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
/*********************************************************************
** Function:create
** Description:creates all the files
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:creates all the files
*********************************************************************/
void Restaurant::create()
{
    createEmp();
    createHours();
    menu.createPizzas();
    createOrders();
}
/*********************************************************************
** Function:load_data
** Description:fills all the files
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:fills all the files
*********************************************************************/
void Restaurant::load_data()
{
    load_dataEmp();
    load_dataHours();
    menu.load_menu();
    load_dataOrders();
}
/*********************************************************************
** Function:view_hours
** Description:view all days
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:view all days
*********************************************************************/
void Restaurant::view_hours()
{
    cout << "The Updated Hours:" << endl;
    for (int i = 0; i < this->num_hours; i++)
    {
        cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
    }
}
/*********************************************************************
** Function:add_hours
** Description:adds an hour
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:adds an hour
*********************************************************************/
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
/*********************************************************************
** Function:change_hours
** Description:changes the hours
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:changes the hours
*********************************************************************/
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
/*********************************************************************
** Function:login
** Description:checks the user input
** Parameters:string x, int id
** Pre-Conditions:string x, int id
** Post-Conditions:checks the user input
*********************************************************************/
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
/*********************************************************************
** Function:place_order
** Description:place an order
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:place an order
*********************************************************************/
void Restaurant::place_order()
{
    int choice;
    menu.view_menuorder();
    cout << "what would you like to choose? ";
    cin >> choice;
    if (choice <= 3)
    {
    }
}
/*********************************************************************
** Function:Sets everything in member
** Description:Sets everything in member
** Parameters:strings
** Pre-Conditions:strings
** Post-Conditions:sets everything
*********************************************************************/
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
/*********************************************************************
** Function:view_address
** Description:views the address
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:views the address
*********************************************************************/
void Restaurant::view_address()
{
    cout << "Our address is: " << this->address << endl;
}
/*********************************************************************
** Function:view_phone
** Description:views the phone
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:views the phone
*********************************************************************/
void Restaurant::view_phone()
{
    cout << "You can contact us by phone: " << this->phone << endl;
}
/*********************************************************************
** Function:view_name
** Description:views the name
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:views the name
*********************************************************************/
void Restaurant::view_name()
{
    cout << "The name of tthe restaurant is: " << this->name << endl;
}
/*********************************************************************
** Function:Sets everything in member
** Description:Sets everything in member
** Parameters:strings
** Pre-Conditions:strings
** Post-Conditions:sets everything
*********************************************************************/
void Restaurant::sethours(int x)
{
    this->num_hours = x;
}
void Restaurant::setnumEmp(int x)
{
    this->num_Emp = x;
}
/*********************************************************************
** Function:UpdatedHours
** Description:Updated hours
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:Updated hours
*********************************************************************/
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
/*********************************************************************
** Function:UpdateOders
** Description:Update Oders
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:Update Oders
*********************************************************************/
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
/*********************************************************************
** Function:remove_orders
** Description:removes an order
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:removes an order
*********************************************************************/
void Restaurant::remove_orders()
{
    int number;
    cout << "Which order would you like to remove?" << endl;
    while (!(cin >> number))
    {
        cout << "Write numbers" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
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
} //To check every possible input
/*********************************************************************
** Function:view_menu
** Description:views the menu
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:views the menu
*********************************************************************/
void Restaurant::view_menu()
{
    menu.view_menu();
}
/*********************************************************************
** Function:remove_from_menu
** Description:removes and item
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:removes and item
*********************************************************************/
void Restaurant::remove_from_menu()
{
    string x;
    cout << "Which Pizza would you like to remove? Please write the name of the pizza" << endl;
    cin >> x;
    menu.removeitem(x);
}
/*********************************************************************
** Function:view_menu_cost
** Description:view_menu_cost
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:view_menu_cost
*********************************************************************/
void Restaurant::view_menu_cost()
{
    menu.view_budgemenu();
}
/*********************************************************************
** Function:view_ingInc
** Description:displays the included ingredients
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:displays the included ingredients
*********************************************************************/
void Restaurant::view_ingInc()
{
    menu.view_searchInc();
}
/*********************************************************************
** Function:view_ingExc
** Description:displays the excluded ingredients
** Parameters:string x
** Pre-Conditions:string
** Post-Conditions:displays the excluded ingredients
*********************************************************************/
void Restaurant::view_ingExc()
{
    menu.view_searchExc();
}
/*********************************************************************
** Function:UpdatedMenu
** Description:shows the updated list
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:shows the updated list
*********************************************************************/
void Restaurant::UpdatedMenu()
{
    menu.Updatedlist();
}