#include <iostream>
#include <string>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
using namespace std;

void print_shape_info(Shape & x){
    cout << x.getcolor() << endl;
    cout << x.getname() << endl;
    cout << x.area()<<endl;
}
int main()
{
    float x, y, z;
    Shape *shape1;
    Shape *shape2;
    Shape *shape3;
    cout << "What's your Width" << endl;
    cin >> x;
    cout << "What's your Height" << endl;
    cin >> y;
    Rectangle rectangle(x,y);
    cout << "What's your Radius" << endl;
    cin >> z;
    Circle cirlce(z);
    Square square(x);
    shape1 = &rectangle;
    shape2 = &cirlce;
    shape3 = &square;
    print_shape_info(rectangle);
    print_shape_info(cirlce);
    print_shape_info(square);
}