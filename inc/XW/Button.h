#include "SpriteObject.h"
#include "TextObject.h"
#include <string>
#include "EventManager.h"
#include "Game.h"

#ifndef BUTTON_H
#define BUTTON_H

class Button : public SpriteObject {
    public:
        Button(
            std::string button_text = "Button", 
            std::string button_texture = "Resources/png/null.png",
            std::string event_id = "NULL",
            Vector2 button_position = Vector2(0.0f, 0.0f), 
            Vector2 button_size = Vector2(32.0f, 16.0f) 
            );

        ~Button() override;

        void draw() override;
        void update(float delta_time) override;
        void event_update(SDL_Event e) override;
        void on_click();
    private:
        std::string button_text;
        std::string button_texture;
        TextObject* txt_obj = nullptr;
        std::string event_id;
};

#endif