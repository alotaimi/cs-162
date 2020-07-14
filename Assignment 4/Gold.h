#ifndef GOLD_H
#define GOLD_H
#include "Event.h"
class Gold : public Event{
    public:
    Gold();
    ~Gold();
    void action();
    Gold &operator=(const Gold &old_obj);
};
#endif