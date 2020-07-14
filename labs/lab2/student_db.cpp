#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "student_db.h"
using namespace std;

student *create_student_db(int x)
{
	student *cs = new student[x];
	return cs;
}

void populate_student_db_info(student *students, int x, ifstream &y)
{
	for (int i = 0; i < x; i++)
	{
		y >> students[i].id >> students[i].fname >> students[i].lname >> students[i].major;
	}
}
void delete_student_db_info(student *students, int x)
{
	delete[] students;
}
void sortid(student *students, int x)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = i + 1; j < x; j++)
		{
			student test;
			if (students[i].id > students[j].id)
			{

				test = students[i];
				students[i] = students[j];
				students[j] = test;
			}
		}
	}
}
void sortmajor(student *students, int x, string arr[7])
{
	for (int z = 0; z < 7; z++)
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = i + 1; j < x; j++)
			{
				student test;
				if (arr[z] == students[i].lname)
				{
				}
			}
		}
	}
}
