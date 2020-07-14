#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"
class Square : public Rectangle
{
public:
    Square(float x);
    int area();
};

#endif