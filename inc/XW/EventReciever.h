#include "XEvent.h"

// Base class for any object that recieves events
#ifndef EVENTRECIEVER_H
#define EVENTRECIEVER_H
class EventReciever {
    public:
        virtual void on_event(XEvent event) {}
};
#endif