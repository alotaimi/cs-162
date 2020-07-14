#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "student_db.h"
using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt"); //open the file

    if (!fin.is_open())
    {
        cout << "Error opening the file to read!!" << endl;
        return 1;
    }
    string arr[7] = {"Bishop", "Cregg", "Dunham", "Knope", "Lyman", "Seaborn", "Ziegler"};
    string tmp_string;
    int num_of_students;
    getline(fin, tmp_string);
    num_of_students = atoi(tmp_string.c_str());
    student *students = create_student_db(num_of_students);
    populate_student_db_info(students, num_of_students, fin);
    int z;
    cout << "what do you want to do?" << endl;
    cin >> z;
    if (z == 1)
    {
        sortid(students, num_of_students);
        for (int i = 0; i < num_of_students; i++)
        {
            cout << students[i].id << " " << students[i].fname << " " << students[i].lname << " " << students[i].major << endl;
        }
    }
    else if (z == 2)
    {
        sortmajor(students, num_of_students, arr);
        for (int i = 0; i < num_of_students; i++)
        {
            cout << students[i].id << " " << students[i].fname << " " << students[i].lname << " " << students[i].major << endl;
        }
    }
    delete_student_db_info(students, num_of_students);
}