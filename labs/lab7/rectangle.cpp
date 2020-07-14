#include <iostream>
#include "rectangle.h"
using namespace std;

Rectangle::Rectangle(float x , float z){
    name = "Rectangle";
    color = "Red";
    width = x;
    height = z;
}
void Rectangle::setW(float x)
{
    width = x;
}
void Rectangle::setH(float x)
{
    height = x;
}
float Rectangle::getW()
{
    return width;
}
float Rectangle::getH()
{
    return height;
}
int Rectangle::area()
{
    return width * height;
}
Rectangle::Rectangle()
{
    width = 0;
    width = 0;
}
