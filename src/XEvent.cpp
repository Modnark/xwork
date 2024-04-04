#include "XW/XEvent.h"

// TODO: integrate with SDL events somehow?

XEvent::XEvent(std::string event_id) {
    this->event_id = event_id;
}

std::string XEvent::get_event_id() {
    return event_id;
}