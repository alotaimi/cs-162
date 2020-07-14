/******************************************************
** Program: Animal.h
** Author: Mishary alotaibi
** Date: 5/92020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <ctime>
#include <cstdio>
using namespace std;
class Animal
{
protected:
    int age;
    int price;
    int babies;
    int foodcost;
    int revenue;
    string status;
    bool alive;

public:
    Animal();
    ~Animal();

    void setage(int x);
    void setprice(int x);
    void setbabies(int x);
    void setfoodcostt(int x, int z);
    void setfoodcost(int x);
    void setrevenue(int x);
    void setstatus(string x);
    void setalive(bool x);

    int getage();
    int getprice();
    int getbabies();
    int getfoodcost();
    int getrevenue();
    string getstatus();
    bool getalive();

    Animal &operator=(const Animal &old_obj);
};
#endif