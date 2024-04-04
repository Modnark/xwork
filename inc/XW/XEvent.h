#ifndef XEVENT_H
#define XEVENT_H

#include <string>
class XEvent {
    public:
        XEvent(std::string event_id);
        std::string get_event_id();
    private:
        std::string event_id;
};

#endif