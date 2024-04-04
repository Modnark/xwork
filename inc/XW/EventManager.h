#include <vector>
#include "XEvent.h"
#include "EventReciever.h"

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
class EventManager {
    public:
        static EventManager* get_instance();
        static void destroy_instance();
        void add_reciever(EventReciever* reciever);
        void remove_reciever(EventReciever* reciever);
        void notify(XEvent event);
        ~EventManager();
    private:
        EventManager();
        static EventManager* instance;
        std::vector<EventReciever*> event_recievers;
};
#endif