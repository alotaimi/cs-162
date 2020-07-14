#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
class Circle : public Shape
{
private:
    float radius;

public:
    void setR(float x);
    float getR();
    int area();
    Circle();
};
#endif