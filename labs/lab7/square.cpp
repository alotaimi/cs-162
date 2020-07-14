#include <iostream>
#include "square.h"
using namespace std;

Square::Square(float x)
{
    name = "Square";
    color = "Green";
    setW(x);
}
int Square::area()
{
    return getW() * 2;
}