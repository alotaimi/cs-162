#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
private:
    float width;
    float height;

public:
    Rectangle(float x, float);
    void setW(float x);
    void setH(float x);
    float getW();
    float getH();
    int area();
    Rectangle();
};
#endif