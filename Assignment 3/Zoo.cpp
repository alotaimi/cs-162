/******************************************************
** Program: Zoo.cpp
** Author: Mishary Alotaibi
** Date: 05/09/2020
** Description:Everything related to the class
** Input:-
** Output:-
******************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include "Zoo.h"
using namespace std;
/*********************************************************************
** Function:Zoo
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to initialize all the memebers
Zoo::Zoo()
{
    revenue = 0;
    num_monkey = 0;
    num_babyM = 0;
    num_sea_otter = 0;
    num_babySO = 0;
    num_sloth = 0;
    num_unicorn = 0;
    num_babyU = 0;
    num_babyS = 0;
    num_animals = 0;
    wallet = 50000;
    bonus = 0;
    fcost = 100;

    for (int i = 0; i < 4; i++)
    {
        animal[i] = NULL;
    }
}
/*********************************************************************
** Function:~ZOO
** Description:desterctuor
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
Zoo::~Zoo()
{
    if (num_monkey > 0)
    {
        delete[] animal[0];
    }
    if (num_sea_otter > 0)
    {
        delete[] animal[1];
    }
    if (num_sloth > 0)
    {
        delete[] animal[2];
    }
    if (num_unicorn > 0)
    {
        delete[] animal[3];
    }
}
/*********************************************************************
** Function:Setters
** Description:sets all the variables
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::setnumM(int x)
{
    this->num_monkey = x;
}
void Zoo::setnumSO(int x)
{
    this->num_sea_otter = x;
}
void Zoo::setnumSloth(int x)
{
    this->num_sloth = x;
}
void Zoo::setnum_unicorn(int x){
    this->num_unicorn = x;
}
void Zoo::setnumA()
{
    this->num_animals = num_monkey + num_sea_otter + num_sloth + num_unicorn;
}
/*********************************************************************
** Function:setrevenue
** Description:sets calculates all the revenue and profits
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//It was over 15 lines because i had to check if it was a baby or not and then caluclate the other animals
void Zoo::setrevenue()
{
    int total = 0;
    for (int i = 0; i < num_monkey; i++)
    {
        if (animal[0][i].getstatus() == "baby")
        {
            total = total + (animal[0][i].getrevenue() * 2) + bonus;
        }
        else
        {
            total = total + animal[0][i].getrevenue() + bonus;
        }
    }
    for (int i = 0; i < num_sea_otter; i++)
    {
         if (animal[1][i].getstatus() == "baby")
        {
            total = total + (animal[1][i].getrevenue() * 2) + bonus;
        }
        else
        {
            total = total + animal[1][i].getrevenue() + bonus;
        }
    }
    for (int i = 0; i < num_sloth; i++)
    {
        if (animal[2][i].getstatus() == "baby")
        {
            total = total + (animal[2][i].getrevenue() * 2) + bonus;
        }
        else
        {
            total = total + animal[2][i].getrevenue() + bonus;
        }
    }
        for (int i = 0; i < num_unicorn; i++)
    {
        if (animal[3][i].getstatus() == "baby")
        {
            total = total + (animal[3][i].getrevenue() * 2) + bonus;
        }
        else
        {
            total = total + animal[3][i].getrevenue() + bonus;
        }
    }
    this->revenue = this->revenue + total;
}
/*********************************************************************
** Function:totalcost
** Description:calculates all the food cost
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 because i had to first generate a number and then calcualte the food cost
void Zoo::totalcost(){
    float x;
    x = rand()% 76 + 50;
    while(x < 75){
        x++;
    }
    x /= 100;
    int total = 0;
    fcost = fcost * x;
    for(int i =0; i < num_monkey; i++){
        animal[0][i].setfoodcostt(fcost,4);
        total += animal[0][i].getfoodcost();
    }
     for(int i =0; i < num_sea_otter; i++){
        animal[1][i].setfoodcostt(fcost,2);
        total += animal[1][i].getfoodcost();
    }
     for(int i =0; i < num_sloth; i++){
        animal[2][i].setfoodcostt(fcost,1);
        total += animal[2][i].getfoodcost();
    }
    for(int i =0; i < num_unicorn; i++){
        animal[3][i].setfoodcostt(fcost,1);
        total += animal[3][i].getfoodcost();
    }
    fcost = total;
    cout << "Total Food Cost is "<< fcost <<endl;
    wallet = wallet - total;
}
/*********************************************************************
** Function:setwallet
** Description:calculate everything to set the wallet
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::setwallet()
{
    setrevenue();
    cout << "Total revenue is " << revenue<<endl;
    wallet = wallet + revenue;
    bonus = 0;
    fcost = 100;
}
/*********************************************************************
** Function:deduction
** Description:deduct from the wallet
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::deduction(int x)
{
    wallet = wallet - x;
}
/*********************************************************************
** Function:getters
** Description:gets all the variables
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
int Zoo::getwallet()
{
    return wallet;
}
int Zoo::getnum_animals()
{
    return num_animals;
}
int Zoo::getnum_monkey()
{
    return num_monkey;
}
int Zoo::getnum_sea_otter()
{
    return num_sea_otter;
}
int Zoo::getnum_sloth()
{
    return num_sloth;
}
int Zoo::getnum_unicorn(){
    return num_unicorn;
}
/*********************************************************************
** Function:displayer
** Description:sets all the variables
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::displayer()
{
    int M,SO,S;
    M = num_monkey;
    SO = num_sea_otter;
    S = num_sloth;
    setnumA();
    cout << "You have: " << num_monkey << " monkies \t"
         << "You have: " << num_sea_otter << " Sea Otter \t"
         << "You have: " << num_sloth << " Sloths \t" << "You have: " << num_unicorn<<" Unicorns"<<"\t" 
         << "You have a total of " << num_animals << " Animals \t" << endl;
    cout << "You have: "<< num_monkey - num_babyM << " Adult Monkies"<<endl;
    cout << "You have: "<< num_sea_otter - num_babySO << " Adult Sea Otter"<<endl;
    cout << "You have: "<< num_sloth - num_babyS << " Adult Sloth"<<endl;
    cout << "You have: "<< num_unicorn - num_babyU << " Adult Unicorn"<<endl;
     cout << "You have: "<< num_babyM << " baby Monkies"<<endl;
    cout << "You have: "<< num_babySO << " baby Sea Otter"<<endl;
    cout << "You have: "<< num_babyS << " baby Sloth"<<endl;
    cout << "You have: "<< num_babyU << " baby Unicorn"<<endl;
}
/*********************************************************************
** Function:newround
** Description:adds a new month for each animal
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 because i had to check first if it was a baby or not and then add age for it
void Zoo::newround()
{
    for (int i = 0; i < num_monkey; i++)
    {
        Monkey m;
        animal[0][i].setage(animal[0][i].getage() + 1);
        if (animal[0][i].getage() == 6 && animal[0][i].getage() < 24)
        {
            cout << "Monkey: " << i + 1 << "Became adolescence" << endl;
            animal[0][i].setstatus("adolescence");
        }
        else if (animal[0][i].getage() == 24)
        {
            cout << "Monkey: " << i + 1 << "Became adult" << endl;
            animal[0][i] = m;
        }
    }
    for (int i = 0; i < num_sea_otter; i++)
    {
        SO so;
        animal[1][i].setage(animal[1][i].getage() + 1);
        if (animal[1][i].getage() == 6 && animal[1][i].getage() < 24)
        {
            cout << "Sea otter: " << i + 1 << "Became adolescence" << endl;
            animal[1][i].setstatus("adolescence");
        }
        else if (animal[1][i].getage() == 24)
        {
            cout << "Sea otter: " << i + 1 << "Became adult" << endl;
            animal[1][i] = so;
        }
    }
    for (int i = 0; i < num_sloth; i++)
    {
        Sloth sloth;
        animal[2][i].setage(animal[2][i].getage() + 1);
        if (animal[2][i].getage() == 6 && animal[2][i].getage() < 24)
        {
            cout << "sloth: " << i + 1 << " Became adolescence" << endl;
            animal[2][i].setstatus("adolescence");
        }
        else if (animal[2][i].getage() == 24)
        {
            cout << "sloth: " << i + 1 << "Became adult" << endl;
            animal[2][i] = sloth;
        }
    }
        for (int i = 0; i < num_unicorn; i++)
    {
        Sloth sloth;
        animal[3][i].setage(animal[3][i].getage() + 1);
        if (animal[3][i].getage() == 6 && animal[3][i].getage() < 24)
        {
            cout << "Unicorn: " << i + 1 << " Became adolescence" << endl;
            animal[3][i].setstatus("adolescence");
        }
        else if (animal[3][i].getage() == 24)
        {
            cout << "sloth: " << i + 1 << "Became adult" << endl;
            animal[3][i] = sloth;
        }
    }
}
/*********************************************************************
** Function:addmonkey
** Description:adds a monkey
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::addMonkey()
{
    num_monkey++;
    if (num_monkey == 1)
        animal[0] = new Monkey[num_monkey];
    else
    {
        Animal *temp = new Monkey[num_monkey - 1];
        for (int i = 0; i < num_monkey - 1; i++)
        {
            temp[i] = animal[0][i];
        }
        delete[] animal[0];
        animal[0] = new Monkey[num_monkey];
        for (int i = 0; i < num_monkey - 1; i++)
        {
            animal[0][i] = temp[i];
        }
        delete[] temp;
    }
}
/*********************************************************************
** Function:addSO
** Description:adds a sea otter
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::addSO()
{
    num_sea_otter++;
    if (num_sea_otter == 1)
        animal[1] = new SO[num_sea_otter];
    else
    {
        Animal *temp = new SO[num_sea_otter - 1];
        for (int i = 0; i < num_sea_otter - 1; i++)
        {
            temp[i] = animal[1][i];
        }
        delete[] animal[1];
        animal[1] = new SO[num_sea_otter];
        for (int i = 0; i < num_sea_otter - 1; i++)
        {
            animal[1][i] = temp[i];
        }
        delete[] temp;
    }
}
/*********************************************************************
** Function:addsloth
** Description:adds a sloth
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::addSloth()
{
    num_sloth++;
    if (num_sloth == 1)
        animal[2] = new Sloth[num_sloth];
    else
    {
        Animal *temp = new Sloth[num_sloth - 1];
        for (int i = 0; i < num_sloth - 1; i++)
        {
            temp[i] = animal[2][i];
        }
        delete[] animal[2];
        animal[2] = new Sloth[num_sloth];
        for (int i = 0; i < num_sloth - 1; i++)
        {
            animal[2][i] = temp[i];
        }
        delete[] temp;
    }
}
/*********************************************************************
** Function:addu
** Description:adds a unicorn
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::addU()
{
    num_unicorn++;
    if (num_unicorn == 1){
        animal[3] = new Unicorn[num_unicorn];
    }
    else
    {
        Animal *temp = new Unicorn[num_unicorn - 1];
        for (int i = 0; i < num_unicorn - 1; i++)
        {
            temp[i] = animal[3][i];
        }
        delete[] animal[3];
        animal[3] = new Unicorn[num_unicorn];
        for (int i = 0; i < num_unicorn - 1; i++)
        {
            animal[3][i] = temp[i];
        }
        delete[] temp;
    }
}
/*********************************************************************
** Function:addbabymonkey
** Description:adds a baby monkey
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to check first if there was a monkey or not and then add it
void Zoo::addbabyMonkey()
{
    num_monkey++;
    if (num_monkey == 1)
    {
        animal[0] = new Monkey[num_monkey];
        animal[0][num_monkey - 1].setage(0);
        animal[0][num_monkey - 1].setprice(15000);
        animal[0][num_monkey - 1].setbabies(0);
        animal[0][num_monkey - 1].setfoodcost(0);
        animal[0][num_monkey - 1].setrevenue(1500 * 2);
        animal[0][num_monkey - 1].setstatus("baby");
        animal[0][num_monkey - 1].setalive(true);
    }
    else
    {
        Animal *temp = new Monkey[num_monkey - 1];
        for (int i = 0; i < num_monkey - 1; i++)
        {
            temp[i] = animal[0][i];
        }
        delete[] animal[0];
        animal[0] = new Monkey[num_monkey];
        for (int i = 0; i < num_monkey - 1; i++)
        {
            animal[0][i] = temp[i];
        }
        animal[0] = new Monkey[num_monkey];
        animal[0][num_monkey - 1].setage(0);
        animal[0][num_monkey - 1].setprice(15000);
        animal[0][num_monkey - 1].setbabies(0);
        animal[0][num_monkey - 1].setfoodcost(0);
        animal[0][num_monkey - 1].setrevenue(1500 * 2);
        animal[0][num_monkey - 1].setstatus("baby");
        animal[0][num_monkey - 1].setalive(true);
        delete[] temp;
    }
}
/*********************************************************************
** Function:addbabySO
** Description:adds a baby sea otter
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to check first if there was a sea otter or not and then add it
void Zoo::addbabySO()
{
    num_sea_otter++;
    if (num_sea_otter == 1)
    {
        animal[1] = new SO[num_sea_otter];
        animal[1][num_sea_otter - 1].setage(0);
        animal[1][num_sea_otter - 1].setprice(5000);
        animal[1][num_sea_otter - 1].setbabies(0);
        animal[1][num_sea_otter - 1].setfoodcost(0);
        animal[1][num_sea_otter - 1].setrevenue(250 * 2);
        animal[1][num_sea_otter - 1].setstatus("baby");
        animal[1][num_sea_otter - 1].setalive(true);
    }
    else
    {
        Animal *temp = new SO[num_sea_otter - 1];
        for (int i = 0; i < num_sea_otter - 1; i++)
        {
            temp[i] = animal[1][i];
        }
        delete[] animal[1];
        animal[1] = new SO[num_sea_otter];
        for (int i = 0; i < num_sea_otter - 1; i++)
        {
            animal[1][i] = temp[i];
        }
        animal[1] = new SO[num_sea_otter];
        animal[1][num_sea_otter - 1].setage(0);
        animal[1][num_sea_otter - 1].setprice(5000);
        animal[1][num_sea_otter - 1].setbabies(0);
        animal[1][num_sea_otter - 1].setfoodcost(0);
        animal[1][num_sea_otter - 1].setrevenue(250 * 2);
        animal[1][num_sea_otter - 1].setstatus("baby");
        animal[1][num_sea_otter - 1].setalive(true);
        delete[] temp;
    }
}
/*********************************************************************
** Function:addbabySloth
** Description:adds a baby sloth
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to check first if there was a sloth or not and then add it
void Zoo::addbabySloth()
{
    num_sloth++;
    if (num_sloth == 1)
    {
        animal[2] = new Sloth[num_sloth];
        animal[2][num_sloth - 1].setage(0);
        animal[2][num_sloth - 1].setprice(2000);
        animal[2][num_sloth - 1].setbabies(0);
        animal[2][num_sloth - 1].setfoodcost(0);
        animal[2][num_sloth - 1].setrevenue(100 * 2);
        animal[2][num_sloth - 1].setstatus("baby");
        animal[2][num_sloth - 1].setalive(true);
    }
    else
    {
        Animal *temp = new Sloth[num_sloth - 1];
        for (int i = 0; i < num_sloth - 1; i++)
        {
            temp[i] = animal[2][i];
        }
        delete[] animal[2];
        animal[2] = new Sloth[num_sloth];
        for (int i = 0; i < num_sloth - 1; i++)
        {
            animal[2][i] = temp[i];
        }
        animal[2] = new Sloth[num_sloth];
        animal[2][num_sloth - 1].setage(0);
        animal[2][num_sloth - 1].setprice(2000);
        animal[2][num_sloth - 1].setbabies(0);
        animal[2][num_sloth - 1].setfoodcost(0);
        animal[2][num_sloth - 1].setrevenue(100 * 2);
        animal[2][num_sloth - 1].setstatus("baby");
        animal[2][num_sloth - 1].setalive(true);
        delete[] temp;
    }
}
/*********************************************************************
** Function:addbabyU
** Description:adds a baby unicorn
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to check first if there was a unicorn or not and then add it
void Zoo::addbabyU()
{
    num_unicorn++;
    if (num_unicorn == 1)
    {
        animal[3] = new Unicorn[num_unicorn];
        animal[3][num_unicorn - 1].setage(0);
        animal[3][num_unicorn - 1].setprice(20000);
        animal[3][num_unicorn - 1].setbabies(0);
        animal[3][num_unicorn - 1].setfoodcost(0);
        animal[3][num_unicorn - 1].setrevenue(10000 * 2);
        animal[3][num_unicorn - 1].setstatus("baby");
        animal[3][num_unicorn - 1].setalive(true);
    }
    else
    {
        Animal *temp = new Unicorn[num_unicorn - 1];
        for (int i = 0; i < num_unicorn - 1; i++)
        {
            temp[i] = animal[3][i];
        }
        delete[] animal[3];
        animal[3] = new Unicorn[num_unicorn];
        for (int i = 0; i < num_unicorn - 1; i++)
        {
            animal[3][i] = temp[i];
        }
        animal[3] = new Unicorn[num_unicorn];
        animal[3][num_unicorn - 1].setage(0);
        animal[3][num_unicorn - 1].setprice(20000);
        animal[3][num_unicorn - 1].setbabies(0);
        animal[3][num_unicorn - 1].setfoodcost(0);
        animal[3][num_unicorn - 1].setrevenue(10000 * 2);
        animal[3][num_unicorn - 1].setstatus("baby");
        animal[3][num_unicorn - 1].setalive(true);
        delete[] temp;
    }
}
/*********************************************************************
** Function:store
** Description:store which you can buy
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to check how many animals will the user buy and then add them
void Zoo::store()
{
    int x;
    int num;
    int loop = 0;
    while (loop < 2)
    {
        cout << "which animal would you like to buy?"
             << "\t"
             << "1. Monkey"
             << "\t"
             << "2. Sea otter"
             << "\t"
             << "3. Sloth"
             << "\t" << "4. Unicorn"<<"\t"
             << "5. Exit the store" << endl;
                    while (!(cin >> x))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
        if (x == 1)
        {
            cout << "how many?" << endl;
            while (!(cin >> num))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
            if (num == 1)
            {
                addMonkey();
                deduction(15000);
                loop++;
            }
            else if (num == 2)
            {
                for (int i = 0; i < num; i++)
                {
                    addMonkey();
                    deduction(15000);
                    loop++;
                }
            }
        }
        else if (x == 2)
        {
            cout << "how many?" << endl;
                        while (!(cin >> num))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
            if (num == 1)
            {
                addSO();
                deduction(5000);
                loop++;
            }
            else if (num == 2)
            {
                for (int i = 0; i < num; i++)
                {
                    addSO();
                    deduction(5000);
                    loop++;
                }
            }
        }
        else if (x == 3)
        {
            cout << "how many?" << endl;
                        while (!(cin >> num))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
            if (num == 1)
            {
                addSloth();
                deduction(2000);
                loop++;
            }
            else if (num == 2)
            {
                for (int i = 0; i < num; i++)
                {
                    addSloth();
                    deduction(2000);
                    loop++;
                }
            }
        }
        else if (x == 4)
        {
             cout << "how many?" << endl;
                        while (!(cin >> num))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
            if (num == 1)
            {
                addU();
                deduction(20000);
                loop++;
            }
            else if (num == 2)
            {
                for (int i = 0; i < num; i++)
                {
                    addU();
                    deduction(20000);
                    loop++;
                }
            }
        }
        else if(x == 5){
            cout <<"Thank you for Purchasing"<<endl;
            loop+=2;
        }
    }
}
/*********************************************************************
** Function:profit
** Description:caluclates profits
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::profit(int x)
{
    wallet = wallet + x;
}
/*********************************************************************
** Function:sell
** Description:store which you can sell
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to check how many animals will the user sell and then add them
void Zoo::sell()
{
    int x;
    int num;
    int loop = 0;
    while (loop < 2)
    {
        cout << "which animal would you like to sell?"
             << "\t"
             << "1. Monkey"
             << "\t"
             << "2. Sea otter"
             << "\t"
             << "3. Sloth"
             << "\t" << "4. Unicorn"<<"\t"
             << "5. Exit the store" << endl;
                    while (!(cin >> x))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
        if (x == 1)
        {
            cout << "how many?" << endl;
                        while (!(cin >> num))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
            if (num <= num_monkey)
            {
                if (num == 1)
                {
                    animal[0][num_monkey - 1].setalive(false);
                    removeMonkey();
                    profit(7500);
                    loop += 2;
                }
            }
            else
            {
                cout << "you cannot sell monkies" << endl;
            }
        }
        else if (x == 2)
        {
            cout << "how many?" << endl;
            while (!(cin >> num))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
            if (num <= num_sea_otter)
            {
                if (num == 1)
                {
                    animal[1][num_sea_otter - 1].setalive(false);
                    removeSO();
                    profit(2500);
                    loop += 2;
                }
            }
            else
            {
                cout << "you cannot sell sea otter" << endl;
            }
        }
        else if (x == 3)
        {
            cout << "how many?" << endl;
                        while (!(cin >> num))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
            if (num <= num_sloth)
            {
                if (num == 1)
                {
                    animal[2][num_sloth - 1].setalive(false);
                    removeSloth();
                    profit(1000);
                    loop += 2;
                }
            }
            else
            {
                cout << "you cannot sell sea otter" << endl;
            }
        }
        else if(x == 4){
             cout << "how many?" << endl;
                        while (!(cin >> num))
			{
				cout << "Write numbers" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
            if (num <= num_unicorn)
            {
                if (num == 1)
                {
                    animal[3][num_unicorn - 1].setalive(false);
                    removeU();
                    profit(10000);
                    loop += 2;
                }
            }
            else
            {
                cout << "you cannot sell Unicorn" << endl;
            }
        }
        else if (x == 5)
        {
            loop += 2;
        }
    }
}
/*********************************************************************
** Function:removemonkey
** Description:removal of an animal
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::removeMonkey()
{
    int x = 0, index = 0;
    for (int i = 0; i < num_monkey; i++)
    {
        if (animal[0][i].getalive() == true)
            x++;
    }
    Animal *temp;
    temp = new Monkey[x];
    for (int i = 0; i < num_monkey; i++)
    {
        if (animal[0][i].getalive() == true)
        {
            temp[index] = animal[0][i];
            index++;
        }
    }
    delete[] animal[0];
    num_monkey = x;
    animal[0] = new Monkey[num_monkey];
    for (int i = 0; i < num_monkey; i++)
        animal[0][i] = temp[i];
    delete[] temp;
}
/*********************************************************************
** Function:removeSO
** Description:removal of an animal
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::removeSO()
{
    int x = 0, index = 0;
    for (int i = 0; i < num_sea_otter; i++)
    {
        if (animal[1][i].getalive() == true)
            x++;
    }
    Animal *temp;
    temp = new SO[x];
    for (int i = 0; i < num_sea_otter; i++)
    {
        if (animal[1][i].getalive() == true)
        {
            temp[index] = animal[1][i];
            index++;
        }
    }
    delete[] animal[1];
    num_sea_otter = x;
    animal[1] = new SO[num_sea_otter];
    for (int i = 0; i < num_sea_otter; i++)
        animal[1][i] = temp[i];
    delete[] temp;
}
/*********************************************************************
** Function:removeSloth
** Description:removal of an animal
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::removeSloth()
{
    int x = 0, index = 0;
    for (int i = 0; i < num_sloth; i++)
    {
        if (animal[2][i].getalive() == true)
            x++;
    }
    Animal *temp;
    temp = new Sloth[x];
    for (int i = 0; i < num_sloth; i++)
    {
        if (animal[2][i].getalive() == true)
        {
            temp[index] = animal[2][i];
            index++;
        }
    }
    delete[] animal[2];
    num_sloth = x;
    animal[2] = new Sloth[num_sloth];
    for (int i = 0; i < num_sloth; i++)
    {
        animal[2][i] = temp[i];
    }
    delete[] temp;
}
/*********************************************************************
** Function:removeU
** Description:removal of an animal
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void Zoo::removeU(){
    int x = 0, index = 0;
    for (int i = 0; i < num_unicorn; i++)
    {
        if (animal[3][i].getalive() == true)
            x++;
    }
    Animal *temp;
    temp = new Unicorn[x];
    for (int i = 0; i < num_unicorn; i++)
    {
        if (animal[3][i].getalive() == true)
        {
            temp[index] = animal[3][i];
            index++;
        }
    }
    delete[] animal[3];
    num_unicorn = x;
    animal[3] = new Unicorn[num_unicorn];
    for (int i = 0; i < num_unicorn; i++)
    {
        animal[3][i] = temp[i];
    }
    delete[] temp;
}
/*********************************************************************
** Function:events
** Description:evetns for the user
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to first generate a number and then do the events, and also i had to check if there was a animal there or not
void Zoo::events()
{
    int x;
    int z;
    srand(time(NULL));
    x = rand() % 5 + 1;
    if (x == 1)
    {
        z = rand() % 3 + 1;
        if (z == 1)
        {
            if (num_monkey > 0)
            {
                addbabyMonkey();
                num_babyM++;
                cout << "a baby monkey was born" << endl;
            }
            else
            {
                cout << "No babies were created" << endl;
            }
        }
        else if (z == 2)
        {
            if (num_sea_otter > 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    addbabySO();
                    num_babySO++;
                    cout << "a baby Sea Otter was born" << endl;
                }
            }
            else
            {
                cout << "No babies were created" << endl;
            }
        }
        else if (z == 3)
        {
            if (num_sloth > 0)
            {
                for (int i = 0; i < 5; i++)
                {
                    addbabySloth();
                    num_babyS++;
                    cout << "a baby Sloth was born" << endl;
                }
            }
            else
            {
                cout << "No babies were created" << endl;
            }
        }
        else if(z == 4){
             if (num_unicorn > 0)
            {
                for (int i = 0; i < 5; i++)
                {
                    addbabyU();
                    num_babyU++;
                    cout << "a baby Unicorn was born" << endl;
                }
            }
            else
            {
                cout << "No babies were created" << endl;
            }
        }
    }
    else if (x == 2)
    {
        sick();
    }
    else if (x == 3)
    {
        cout << "WE HIT THE JACKPOT!!! HIGH DEMAND"<<endl;
        bonus = rand() % 301 + 400;
    }
}
/*********************************************************************
** Function:sick
** Description:sick and then remove
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i first had to check if there is an animal and then check if the user had money or not for each animal
void Zoo::sick()
{
    int z;
    z = rand() % 4 + 1;
    if (z == 1)
    {
        if (num_monkey > 0)
        {
            cout << "Monkey is sick :("<<endl;
            animal[0][num_monkey - 1].setalive(false);
            if (wallet < 7500)
            {
                removeMonkey();
                cout << "You have lost a Monkey due to sickness R.I.P"<<endl;
            }
            else if(wallet > 7500)
            {
                if(animal[0][num_monkey - 1].getstatus() == "baby"){
                deduction(7500*2);
                cout << "You have cured a Baby Monkey from sickness :D"<<endl;
                animal[0][num_monkey - 1].setalive(true);
                }
                else{
                 deduction(7500);
                cout << "You have cured a Monkey from sickness :D"<<endl;
                animal[0][num_monkey - 1].setalive(true);
                }
            }
        }
    }
    else if (z == 2)
    {
        if (num_sea_otter > 0)
        {
            cout << "Sea Otter is sick :("<<endl;
            animal[1][num_sea_otter - 1].setalive(false);
            if (wallet < 2500)
            {
                removeSO();
                cout << "You have lost a Sea Otter due to sickness R.I.P"<<endl;
            }
            else if (wallet > 2500)
            {
                if(animal[1][num_sea_otter - 1].getstatus() == "baby"){
                deduction(2500*2);
                cout << "You have cured a Baby Sea Otter from sickness :D"<<endl;
                animal[1][num_sea_otter - 1].setalive(true);
                }
                else{
                 deduction(2500);
                cout << "You have cured a Sea Otter from sickness :D"<<endl;
                animal[1][num_sea_otter - 1].setalive(true);
                }
            }
        }
    }
    else if (z == 3)
    {
        if (num_sloth > 0)
        {
            cout << "Sloth is sick :("<<endl;
            animal[2][num_sloth - 1].setalive(false);
            if (wallet < 1000)
            {
                removeSloth();
                cout << "You have lost a Sloth due to sickness R.I.P"<<endl;
            }
            else if(wallet > 1000)
            {
                if(animal[2][num_sloth - 1].getstatus() == "baby"){
                deduction(1000*2);
                cout << "You have cured a Baby Sloth from sickness :D"<<endl;
                animal[2][num_sloth - 1].setalive(true);
                }
                else{
                deduction(1000);
                cout << "You have cured a Sloth from sickness :D"<<endl;
                animal[2][num_sloth - 1].setalive(true);
                }
            }
        }
    }
    else if(z == 4){
        if (num_unicorn > 0)
        {
            cout << "Unicorn is sick :("<<endl;
            animal[3][num_unicorn - 1].setalive(false);
            if (wallet < 2500)
            {
                removeU();
                cout << "You have lost a Sloth due to sickness R.I.P"<<endl;
            }
            else if(wallet > 2500)
            {
                if(animal[3][num_unicorn - 1].getstatus() == "baby"){
                deduction(2500*2);
                cout << "You have cured a Baby Sloth from sickness :D"<<endl;
                animal[3][num_unicorn - 1].setalive(true);
                }
                else{
                deduction(2500);
                cout << "You have cured a Sloth from sickness :D"<<endl;
                animal[3][num_unicorn - 1].setalive(true);
                }
            }
        }
    }
}
