#include <iostream>
#include "rectangle.h"
using namespace std;

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
float Rectangle::area()
{
    cout << width * height << endl;
    return 0;
}
Rectangle::Rectangle()
{
    width = 0;
    width = 0;
}
