#include "XW/BaseObject.h"
#include "XW/Game.h"
#include "XW/DebugUtils.h"

BaseObject::BaseObject() {
    GameWindow* game_window = Game::get_instance()->get_window();
    if (game_window) {
        renderer = game_window->get_renderer();
    } else {
        DebugUtils::PrintOutput(Console, Error, "[BaseObject::BaseObject()] Window is NULL.\n");
    }

    object_class_name = "BaseObject";
    object_name = "BaseObject";
}

Vector2 BaseObject::get_position() {
    return position;
}

Vector2 BaseObject::get_size() {
    return size;
}

Vector2 BaseObject::get_velocity() {
    return velocity;
}

void BaseObject::set_velocity(Vector2 new_velocity) {
    velocity = new_velocity;
}

void BaseObject::set_active(bool is_active) {
    active = is_active;
}

bool BaseObject::is_active() {
    return active;
}

void BaseObject::set_visible(bool is_visible) {
    visible = is_visible;
}

bool BaseObject::is_visible() {
    return visible;
}

SDL_FRect BaseObject::get_rect() {
    return obj_rect;
}

void BaseObject::set_size(Vector2 new_size) {
    size = new_size;
}

void BaseObject::set_position(Vector2 new_position) {
    position = new_position;
}

std::string BaseObject::get_name() {
    return object_name;
}

std::string BaseObject::get_class_name() {
    return object_class_name;
}

void BaseObject::set_name(std::string new_name) {
    object_name = new_name;
}

// Destructor
BaseObject::~BaseObject() {
    printf("~BaseObject()\n");
}

// Overrides
void BaseObject::update(float delta_time) {};
void BaseObject::draw() {};
void BaseObject::event_update(SDL_Event event) {};
