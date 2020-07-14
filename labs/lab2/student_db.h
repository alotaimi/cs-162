#include <string>
#include <iostream>
using namespace std;

struct student
{
    int id;
    string fname;
    string lname;
    string major;
};
student *create_student_db(int);
void populate_student_db_info(student *, int, ifstream &);
void delete_student_db_info(student *, int);
void sortmajor(student *, int, string arr[]);
void sortid(student *, int);
