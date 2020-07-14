/******************************************************
** Program: wizard_catalog.cpp
** Author: Mishary alotaibi
** Date: 04/12/2020
** Description: sorting books,sorting spells,
** Input: id,passowrd,chocies
** Output: sorting everything
******************************************************/
#include "catalog.h" // use this (.h) file
using namespace std;
/*********************************************************************
** Function: create_spellbooks
** Description: creates spellbooks array
** Parameters: int
** Pre-Conditions:none
** Post-Conditions:array
*********************************************************************/
spellbook *create_spellbooks(int x)
{
    spellbook *book = new spellbook[x];
    return book;
}
/*********************************************************************
** Function:create_spell
** Description:creates spell array
** Parameters: int
** Pre-Conditions:none
** Post-Conditions:array
*********************************************************************/
spell *create_spells(int x)
{
    spell *sp = new spell[x];
    return sp;
}
/*********************************************************************
** Function: populate_spell_data
** Description: fill information
** Parameters: struct, int , stream
** Pre-Conditions:file
** Post-Conditions: filling array
*********************************************************************/
void populate_spell_data(spell *s, int z, ifstream &y)
{
    y >> s->name >> s->success_rate >> s->effect;
}
/*********************************************************************
** Function: printspellbook
** Description: prints spellbook
** Parameters: struct
** Pre-Conditions:none
** Post-Conditions: displaying books
*********************************************************************/
void printspellbook(spellbook x)
{

    cout << x.title << " " << x.author << " " << x.num_pages << " " << x.edition << " " << x.num_spells << endl;
}
/*********************************************************************
** Function:printspells
** Description:prints spells
** Parameters: struct,int
** Pre-Conditions:2 inputs
** Post-Conditions:displaying spells
*********************************************************************/
void printspells(spell *s, int num_spells)
{
    for (int i = 0; i < num_spells; i++)
    {
        cout << s[i].name << " " << s[i].success_rate << " " << s[i].effect << endl;
    }
}
/*********************************************************************
** Function:populate_spellbook_data
** Description:filling spellbook
** Parameters:struct,int,file
** Pre-Conditions:struct,int,file
** Post-Conditions: filling out spellbook
*********************************************************************/
void populate_spellbook_data(spellbook *x, int z, ifstream &y)
{
    for (int i = 0; i < z; i++)
    {
        y >> x[i].title >> x[i].author >> x[i].num_pages >> x[i].edition >> x[i].num_spells;
        x[i].s = create_spells(z);
        for (int j = 0; j < x[i].num_spells; j++)
        {
            populate_spell_data(&(x[i].s[j]), x[i].num_spells, y);
        }
    }
}
/*********************************************************************
** Function:sortbypage
** Description:sorting by pages
** Parameters: struct,int
** Pre-Conditions:struct,int
** Post-Conditions: sorting by pages
*********************************************************************/
void sortbypage(spellbook *book, int num_of_spellbooks)
{
    for (int i = 0; i < num_of_spellbooks; i++)
    {
        for (int j = i + 1; j < num_of_spellbooks; j++)
        {
            spellbook temp;
            if (book[i].num_pages > book[j].num_pages)
            {
                temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            }
        }
    }
}
/*********************************************************************
** Function:printspellbooks
** Description:print spellbooks
** Parameters:struct,int
** Pre-Conditions:none
** Post-Conditions: dispalying spellbooks
*********************************************************************/
void printspellbooks(spellbook *x, int z)
{
    for (int i = 0; i < z; i++)
    {
        cout << x[i].title << " " << x[i].author << " " << x[i].num_pages << " " << x[i].edition << " " << x[i].num_spells << endl;
        printspells(x[i].s, x[i].num_spells);
    }
}
/*********************************************************************
** Function:printspells
** Description:printing spells
** Parameters:struct,int
** Pre-Conditions:none
** Post-Conditions:displaying spells
*********************************************************************/
void printspells(spellbook *x, int z)
{
    for (int i = 0; i < z; i++)
    {
        cout << x[i].title << " " << x[i].author << " " << x[i].num_pages << " " << x[i].edition << " " << x[i].num_spells << endl;
    }
}
/*********************************************************************
** Function:sort_effect
** Description:sorting effect + to check if he is a student or not
** Parameters:arry,int,struct,string
** Pre-Conditions:if student or other
** Post-Conditions:sorting effects
*********************************************************************/
void sort_effect(string arr[5], int n, spellbook *x, string status)
{
    if (status == "Student")
    {
        for (int z = 0; z < 5; z++) // loop through arr
        {
            for (int y = 0; y < n; y++) // loop through spellbook
            {
                for (int j = 0; j < x[y].num_spells; j++) // loop through spells
                {
                    if (x[y].s[j].effect == "death" || x[y].s[j].effect == "poison")
                    {
                        if (arr[z] == x[y].s[j].effect)
                        {
                        x[y].s[j].effect = " ";
                        x[y].s[j].name = " ";
                        }
                    }
                }
            }
        }
    }
    else
    {
        for (int z = 0; z < 5; z++) // loop through arr
        {
            for (int y = 0; y < n; y++) // loop through spellbook
            {
                for (int j = 0; j < x[y].num_spells; j++) // loop through spells
                {
                    if (arr[z] == x[y].s[j].effect)
                    {
                    }
                }
            }
        }
    }
}
/*********************************************************************
** Function:sort_avg
** Description:sort avg success + to check if he is a student or not
** Parameters:struct,int,string
** Pre-Conditions:struct,int,string
** Post-Conditions: sort avg success
*********************************************************************/
void sort_avg(spellbook *book, int num_of_spellbooks, string status)
{
    if (status == "Student")
    {
        float counter = 0.0;
        float suc = 0.00;
        for (int i = 0; i < num_of_spellbooks; i++)
        {
            counter = 0.0;
            suc = 0.00;
            for (int j = 0; j < book[i].num_spells; j++)
            {
                if (book[i].s[j].effect != "death" && book[i].s[j].effect != "poison")
                {
                    counter++;
                    suc += float(book[i].s[j].success_rate);
                }
            }
            if (counter == 0.0)
            {
                book[i].avg_success_rate = 0.0;
            }
            else
            {
                book[i].avg_success_rate = suc / (counter);
            }
        }
    }
    else
    {
        float suc = 0.00;
        for (int i = 0; i < num_of_spellbooks; i++)
        {
            suc = 0.00;
            for (int j = 0; j < book[i].num_spells; j++)
            {
                suc += float(book[i].s[j].success_rate);
            }
            book[i].avg_success_rate = suc / (book[i].num_spells);
        }
    }
    for (int i = 0; i < num_of_spellbooks; i++)
    {
        for (int j = i + 1; j < num_of_spellbooks; j++)
        {
            spellbook temp;
            if (book[i].avg_success_rate > book[j].avg_success_rate)
            {
                temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            }
        }
    }
}
/*********************************************************************
** Function:DoesFileExist
** Description:check the file
** Parameters:string
** Pre-Conditions:string
** Post-Conditions:true or false
*********************************************************************/
bool DoesFileExist(const string &name)
{
    ifstream f(name.c_str());
    return f.good();
}
/*********************************************************************
** Function:delete_info
** Description:deleting all used memory
** Parameters:struct,struct,int
** Pre-Conditions:number of spellbooks
** Post-Conditions:deleted memory
*********************************************************************/
void delete_info(wizard *profile,spellbook *book, int z){
    delete [] profile;
for(int i = 0; i < z; i++){
  delete [] book[i].s;
  }
  delete [] book;
  profile = NULL;
  book = NULL;
}



