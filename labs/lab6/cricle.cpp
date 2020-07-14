#include <iostream>
#include "circle.h"
using namespace std;

void Circle::setR(float x)
{
    radius = x;
}

float Circle::getR()
{
    return radius;
}
Circle::Circle()
{
    radius = 0.0;
}
int Circle::area()
{
    cout << radius * 2.0 << endl;
    return 0;
}