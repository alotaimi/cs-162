#ifndef PIT_H
#define PIT_H
#include "Event.h"
class Pit : public Event{
    public:
    Pit();
    ~Pit();
    void action();
    Pit &operator=(const Pit &old_obj);
};
#endif