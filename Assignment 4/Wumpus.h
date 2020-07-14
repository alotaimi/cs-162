#ifndef WUMPUS_H
#define WUMPUS_H
#include "Event.h"
class Wumpus : public Event{
    public:
    Wumpus();
    ~Wumpus();
    void action();
    Wumpus &operator=(const Wumpus &old_obj);
};
#endif