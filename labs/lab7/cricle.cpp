#include <iostream>
#include "circle.h"
using namespace std;

Circle::Circle(float x){
    name = "Cirlce";
    color = "Yellow";
    radius = x;
}
void Circle::setR(float x)
{
    radius = x;
}

float Circle::getR()
{
    return radius;
}
/*Circle::Circle()
{
    radius = 0.0;
}*/
int Circle::area()
{
    return radius * 2.0;
}