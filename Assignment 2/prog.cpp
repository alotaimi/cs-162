/******************************************************
** Program: prog.cpp
** Author: Mishary Alotaibi
** Date: 04/26/2020
** Description:Everything related to the actual program
** Input:-
** Output:-
******************************************************/
#include <iostream>
#include <iostream>
#include <fstream>
#include "restaurant.h"
#include "menu.h"
#include "emp_hours.h"

using namespace std;

int main(int argc, char *argv[])
{
	Restaurant restaurant;
	restaurant.create();
	restaurant.load_data();
	//program starts here
	cout << "Welcome to Bytes Pizza!" << endl;
	char user;
	int id, choice, choicesHours, choicev2;
	string password;
	int loop = 0;
	int loop2 = 0;
	int loop3 = 0;
	cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)?" << endl;
	while (loop == 0)
	{
		cin >> user;
		if (user == 'E' || user == 'e')
		{
			cout << "Please provide an id" << endl;
			while (!(cin >> id))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
			cout << "Please provide a Password" << endl;
			cin >> password;
			if (restaurant.login(id, password))
			{
				while (loop == 0)
				{
					cout << "What would you like to do?"
						 << "\t"
						 << " 1. Change hours"
						 << "\t"
						 << " 2. View orders"
						 << "\t"
						 << " 3. Remove order"
						 << "\t "
						 << " 4. Add Item to Menu"
						 << "\t "
						 << " 5. Remove Item from Menu "
						 << "\t "
						 << " 6. View Menu "
						 << "\t "
						 << " 7. View Hours "
						 << "\t "
						 << " 8. View Address "
						 << "\t "
						 << " 9. View Phone "
						 << "\t "
						 << " 10. View Name "
						 << "\t"
						 << "11. log out" << endl;
					while (!(cin >> choice))
					{
						cout << "Write numbers" << endl;
						cin.clear();
						cin.ignore(123, '\n');
					}
					if (choice == 1)
					{
						cout << "What option would you like to do?"
							 << "\t"
							 << "1. add hours"
							 << "\t"
							 << "2. Change hours" << endl;
						while (!(cin >> choicesHours))
						{
							cout << "Write numbers" << endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						if (choicesHours == 1)
						{
							restaurant.add_hours();
							restaurant.view_hours();
							restaurant.UpdatedHours();
						}
						else if (choicesHours == 2)
						{
							restaurant.change_hours();
							restaurant.view_hours();
							restaurant.UpdatedHours();
						}
					}
					else if (choice == 2)
					{
						restaurant.view_orders();
					}
					else if (choice == 3)
					{
						restaurant.remove_orders();
						restaurant.view_orders();
						restaurant.UpdateOders();
					}
					else if (choice == 4)
					{
						restaurant.add_to_menu();
						restaurant.view_menu();
						restaurant.UpdatedMenu();
					}
					else if (choice == 5)
					{
						restaurant.remove_from_menu();
						restaurant.view_menu();
						restaurant.UpdatedMenu();
					}
					else if (choice == 6)
					{
						restaurant.view_menu();
					}
					else if (choice == 7)
					{
						restaurant.view_hours();
					}
					else if (choice == 8)
					{
						restaurant.view_address();
					}
					else if (choice == 9)
					{
						restaurant.view_phone();
					}
					else if (choice == 10)
					{
						restaurant.view_name();
					}
					else if (choice == 11)
					{
						cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)?" << endl;
						break;
					}
					else
					{
						cout << "Wrong choice" << endl;
					}
				}
			}
			else
			{
				cout << "Wrong Info" << endl;
				cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)?" << endl;
			}
		}
		else if (user == 'C' || user == 'c')
		{
			while (loop == 0)
			{
				cout << "1. View Menu"
					 << "\t"
					 << "2. Search by Cost"
					 << "\t"
					 << "3. Search by Ingredients"
					 << "\t"
					 << "4. Place Order"
					 << "\t"
					 << "5. View Hours"
					 << "\t"
					 << "6. View Address"
					 << "\t"
					 << "7. View Phone"
					 << "\t"
					 << "8. Log out" << endl;
				while (!(cin >> choice))
				{
					cout << "Write numbers" << endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
				if (choice == 1)
				{
					restaurant.view_menu();
				}
				else if (choice == 2)
				{
					restaurant.view_menu_cost();
				}
				else if (choice == 3)
				{
					cout << "What would you like to do in your search?"
						 << "\t"
						 << "1. Search by include"
						 << "\t"
						 << "2. Search by exclude" << endl;
					while (!(cin >> choicev2))
					{
						cout << "Write numbers" << endl;
						cin.clear();
						cin.ignore(123, '\n');
					}
					if (choicev2 == 1)
					{
						restaurant.view_ingInc();
					}
					else if (choicev2 == 2)
					{
						restaurant.view_ingExc();
					}
				}
				else if (choice == 4)
				{
					restaurant.place_order();
				}
				else if (choice == 5)
				{
					restaurant.view_hours();
				}
				else if (choice == 6)
				{
					restaurant.view_address();
				}
				else if (choice == 7)
				{
					restaurant.view_phone();
				}
				else if (choice == 8)
				{
					cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)?" << endl;
					break;
				}
				else
				{
					cout << "Wrong choice" << endl;
				}
			}
		}
		else if (user == 'Q' || user == 'q')
		{
			return 0;
		}
		else
		{
			cout << "Wrong input" << endl;
		}
	}
	return 0;
} //it was over because i had to show the menu and make it easier for the user to know the options