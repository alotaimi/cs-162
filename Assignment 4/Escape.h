#ifndef ESCAPE_H
#define ESCAPE_H
#include "Event.h"
class Escape : public Event{
    public:
    Escape();
    ~Escape();
    void action();
    Escape &operator=(const Escape &old_obj);
};
#endif