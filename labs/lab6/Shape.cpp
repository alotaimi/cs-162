#include "shape.h"
#include <iostream>
#include <string>
using namespace std;

Shape::Shape()
{
    name = "Nothing";
    color = "No Color";
}
void Shape::setname(string x)
{
    name = x;
}
void Shape::setcolor(string x)
{
    color = x;
}
int Shape::area()
{
}
string Shape::getname()
{
    return name;
}
string Shape::getcolor()
{
    return color;
}
Shape::~Shape() {}