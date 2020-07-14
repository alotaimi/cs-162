/******************************************************
** Program: emp_hours.h
** Author: Mishary alotaibi
** Date: 04/26/2020
** Description: structs and defentations 
** Input: NONE
** Output: NONE
******************************************************/
#ifndef EMP_HOURS_H
#define EMP_HOURS_H

#include <string>
using namespace std;

struct employee
{
  int id;
  string password;
  string first_name;
  string last_name;
};

struct hours
{
  string day;
  string open_hour;
  string close_hour;
};

struct orders
{
  int num_order;
  string name_order;
  string credit_num;
  string phone_num;
  string order;
};

#endif