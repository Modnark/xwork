#include "Vector2.h"
#include <SDL2/SDL.h>
#include <string>

#ifndef BASEOBJECT_H
#define BASEOBJECT_H
class BaseObject {
    public:
        BaseObject();

        Vector2 get_position();
        Vector2 get_size();
        Vector2 get_velocity();
        void set_size(Vector2 new_size);
        void set_position(Vector2 new_position);
        void set_velocity(Vector2 new_velocity);
        void set_active(bool is_active);
        bool is_active();
        void set_visible(bool is_visible);
        bool is_visible();     

        SDL_FRect get_rect();

        virtual void update(float delta_time);
        virtual void draw();
        virtual void event_update(SDL_Event event);
        std::string get_name();
        std::string get_class_name();
        void set_name(std::string new_name);

        virtual ~BaseObject();
    protected:
        Vector2 position = Vector2(0.0f,0.0f);
        Vector2 size = Vector2(0.0f,0.0f);
        Vector2 velocity = Vector2(0.0f, 0.0f);
        SDL_FRect obj_rect;
        SDL_Renderer* renderer;
        bool active = true;
        bool visible = true;
        std::string object_class_name;
        std::string object_name;
};
#endif