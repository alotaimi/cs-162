#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using namespace std;
class Shape
{
protected:
    string name;
    string color;

public:
    Shape();
    void setname(string x);
    void setcolor(string x);
    int area();
    string getname();
    string getcolor();
    ~Shape();
};
#endif