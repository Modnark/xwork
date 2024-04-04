#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "BaseObject.h"

#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H
class TextObject : public BaseObject {

    public:

        // constructor
        TextObject(
            std::string text_content = "TextObject", 
            int font_size = 12, 
            Vector2 position = Vector2(0.0f, 0.0f), 
            std::string font_name = "Resources/fonts/arial.ttf"
        );
    
        // getters
        const char* get_text();
        
        // setters
        void set_font(std::string font_name);
        void set_content(std::string content);
        void set_font_size(int font_size);

        // overrides
        void draw() override;
        void update(float delta_time) override;

        // destructor
        ~TextObject() override;
    private:
        std::string text_content;
        std::string font_name;
        int font_size;        

        // misc internal functions
        void update_text_rect();
        void load_font(std::string font_name, int font_size);
        void unload_font();

        // SDL data
        TTF_Font* font;
        SDL_Surface* surface;
        SDL_Texture* texture;
};
#endif