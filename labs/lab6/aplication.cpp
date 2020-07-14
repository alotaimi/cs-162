#include <iostream>
#include <string>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
using namespace std;

int main()
{
    float x, y, z;
    Shape shape;
    Rectangle rectangle;
    Circle cirlce;
    cout << "What's your Width" << endl;
    cin >> x;
    rectangle.setW(x);
    cout << "What's your Height" << endl;
    cin >> y;
    rectangle.setH(y);
    cout << "What's your Radius" << endl;
    cin >> z;
    cirlce.setR(z);
    Square square(x);
    rectangle.area();
    cirlce.area();
    square.area();
}