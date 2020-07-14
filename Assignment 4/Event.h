#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>
using namespace std;
class Event{
   protected:
    string Who;
    string Message;
    public:
    Event();
    ~Event();
    void setWho(string);
    void setMessage(string);
   // Event getevent();
    virtual void action();
    string getMessage();
    string getWho();
    Event &operator=(const Event &);
};


#endif