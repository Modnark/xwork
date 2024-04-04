#include <SDL2/SDL_image.h>
#include "BaseObject.h"
#include <string>
#include "Color3.h"

#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H
class SpriteObject : public BaseObject {
    public:
        SpriteObject(
            std::string texture_name = "Resources/png/null.png",
            Vector2 position = Vector2(0.0f, 0.0f), Vector2 size = Vector2(1.0f, 1.0f)
        );

        void draw() override;
        void update(float delta_time) override;
        void load_texture();
        
        void set_color_mod(Color3 color_mod);
        Color3 get_color_mod();

        void set_alpha(int alpha);
        int get_alpha();

        std::string texture_name;

        ~SpriteObject() override;
    private:
        void update_dest_rect(Vector2 position, Vector2 size);

        Color3 color_mod = Color3(255, 255, 255);
        int alpha = 255;
        
        SDL_Surface* surface;
        SDL_Texture* texture;        
};
#endif