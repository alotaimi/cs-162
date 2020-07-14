#ifndef BATS_H
#define BATS_H
#include "Event.h"
class Bats : public Event{
    public:
    Bats();
    ~Bats();
    void action();
    Bats &operator=(const Bats &old_obj);
};
#endif