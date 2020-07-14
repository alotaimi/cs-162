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
    virtual int area() = 0;
    string getname();
    string getcolor();
};
bool operator>(const Shape &x, const Shape &z);
bool operator<(const Shape & x, const Shape & z);

#endif