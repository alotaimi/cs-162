/******************************************************
** Program: Zoo.h
** Author: Mishary alotaibi
** Date: 5/92020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef ZOO_H
#define ZOO_H
#include "Animal.h"
#include "SO.h"
#include "Monkey.h"
#include "Sloth.h"
#include "Unicorn.h"
class Zoo
{
private:
    int revenue;
    int num_monkey;
    int num_babyM;
    int num_sea_otter;
    int num_babySO;
    int num_sloth;
    int num_babyS;
    int num_unicorn;
    int num_babyU;
    int num_animals;
    int wallet;
    int bonus;
    int fcost;
    Animal *animal[4];

public:
    Zoo();
    ~Zoo();

    void setnumM(int x);
    void setnumSO(int x);
    void setnumSloth(int x);
    void setnum_unicorn(int x);
    void setnumA();
    void setfcost();
    void setrevenue();
    void setwallet();
    void deduction(int x);
    void profit(int x);

    int getwallet();
    int getnum_animals();
    int getnum_monkey();
    int getnum_sea_otter();
    int getnum_sloth();
    int getnum_unicorn();

    void store();
    void sell();
    void sick();
    void displayer();
    void addMonkey();
    void addSO();
    void addSloth();
    void addU();
    void addbabyMonkey();
    void addbabySO();
    void addbabySloth();
    void addbabyU();

    void removeMonkey();
    void removeSO();
    void removeSloth();
    void removeU();
    void newround();
    void events();
    void totalcost();
};
#endif