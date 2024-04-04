#include "XW/EventManager.h"

EventManager* EventManager::instance = nullptr;
EventManager* EventManager::get_instance() {
    if(!instance)
        instance = new EventManager();
    return instance;
}

void EventManager::destroy_instance() {
    if(instance) {
        delete instance;
        instance = nullptr;
    }
}

void EventManager::add_reciever(EventReciever* reciever) {
    event_recievers.push_back(reciever);
}

void EventManager::remove_reciever(EventReciever* reciever) {
    for(int i = 0; i < event_recievers.size(); i++)
    {
        if(event_recievers.at(i) == reciever) {
            delete event_recievers.at(i);
            event_recievers.erase(event_recievers.begin() + i);
            break;
        }
    }
}

void EventManager::notify(XEvent event) {
    for(int i = 0; i < event_recievers.size(); i++)
    {
        if(event_recievers[i])
            event_recievers[i]->on_event(event);
    }
}

EventManager::EventManager() {}