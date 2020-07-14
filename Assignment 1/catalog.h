/******************************************************
** Program: catalog.h
** Author: Mishary alotaibi
** Date: 04/12/2020
** Description: Structs and defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef __catalog__
#define __catalog__ value
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct wizard
{
    string name;
    int id;
    string password;
    string position_title;
    float beard_length;
};

struct spellbook
{
    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    struct spell *s;
};

struct spell
{
    string name;
    float success_rate;
    string effect;
};

spellbook *create_spellbooks(int);
spell *create_spells(int);
void populate_spell_data(spell *, int, ifstream &);
void printspellbook(spellbook);
void printspells(spell *, int);
void populate_spellbook_data(spellbook *, int, ifstream &);
void sortbypage(spellbook *, int);
void printspellbooks(spellbook *, int);
void printspells(spellbook *, int);
void sort_effect(string[], int, spellbook *, string);
void sort_avg(spellbook *, int, string);
bool DoesFileExist(const string &);
void delete_info(wizard *, spellbook *, int);
#endif
