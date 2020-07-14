#include <iostream>
#include "square.h"
using namespace std;

Square::Square(float x)
{
    setW(x);
}
int Square::area()
{
    cout << getW() * 2 << endl;
    return 0;
}