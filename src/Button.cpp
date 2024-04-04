#include "XW/Button.h"
#include "XW/XEvent.h"
#include "XW/EventManager.h"

Button::Button(std::string button_text, std::string button_texture, std::string event_id, Vector2 button_position, Vector2 button_size) {
    this->button_text = button_text;
    this->button_texture = button_texture;
    this->event_id = event_id;
    texture_name = button_texture;
    
    position = button_position;
    size = button_size;

    object_name = "Button";
    object_class_name = "Button";

    Game* game = Game::get_instance();

    if(button_text != "") {
        txt_obj = new TextObject(button_text, 16, Vector2(position.X + size.X / 2, position.Y + size.Y / 2), "Resources/fonts/c64.ttf");
        game->add_game_object(txt_obj);
    }
    
    load_texture();
}

Button::~Button() {

}

void Button::draw() {
    SpriteObject::draw();
}

void Button::event_update(SDL_Event event) {
    switch(event.type) {
        case SDL_MOUSEBUTTONUP:
            if(event.button.button == SDL_BUTTON_LEFT) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                if(mouseX > position.X && mouseX < position.X + size.X) {
                    if(mouseY > position.Y && mouseY < position.Y + size.Y) {
                        on_click();
                    }
                }
            }
            break;       
    }
}

void Button::on_click() {
    EventManager::get_instance()->notify(XEvent(event_id));
}

void Button::update(float delta_time) {
    SpriteObject::update(delta_time);

    if(txt_obj)
        txt_obj->set_position(Vector2(position.X + size.X / 2, position.Y + size.Y / 2));
}