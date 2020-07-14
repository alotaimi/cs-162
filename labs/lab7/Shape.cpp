#include "shape.h"
#include <iostream>
#include <string>
using namespace std;

Shape::Shape()
{
    name = "Nothing";
    color = "No Color";
}
bool operator>(const Shape &x, const Shape &z){
    if(x > z){
       return true;
    }
    else{
        return false;
    }
}
bool operator<(const Shape &x, const Shape &z){
    if(x < z){
       return true;
    }
    else{
        return false;
    }
}
void Shape::setname(string x)
{
    name = x;
}
void Shape::setcolor(string x)
{
    color = x;
}
string Shape::getname()
{
    return name;
}
string Shape::getcolor()
{
    return color;
}