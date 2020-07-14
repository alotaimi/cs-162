#ifndef ROOM_H
#define ROOM_H
#include "Event.h"
class Room{
    private:
    Event* event;
    bool has_event;
    string Who;
    string message;
    public:
    Room();
    ~Room();
    void setevent(Event* x);
    void sethas(bool x);
    string getWho();
    string getmessage();
    Event* getevent();
    bool gethas();
    void action();
    Room &operator=(const Room &old_obj);
};
#endif