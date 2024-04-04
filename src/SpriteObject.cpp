#include "XW/SpriteObject.h"

#include "XW/StringUtils.h"
#include "XW/DebugUtils.h"

#include <stdexcept>
#include <filesystem>

SpriteObject::SpriteObject(std::string texture_name, Vector2 position, Vector2 size) {
    surface = nullptr;
    texture = nullptr;
    this->texture_name = texture_name;
    this->position = position;
    this->size = size;
    
    object_name = "SpriteObject";
    object_class_name = "SpriteObject";

    try {
        load_texture();
    } catch(const std::runtime_error& e) {
        DebugUtils::PrintOutput(Console, Error, std::string(e.what()));
    }    
}

void SpriteObject::update_dest_rect(Vector2 position, Vector2 size) {
    obj_rect = {position.X, position.Y, size.X, size.Y};
}

void SpriteObject::draw() {
    if(texture)
        SDL_RenderCopyF(renderer, texture, nullptr, &obj_rect);
}

void SpriteObject::update(float delta_time) {
    update_dest_rect(position, size);
}

void SpriteObject::load_texture() {
    bool texture_exists = std::filesystem::exists(texture_name);
    if (!texture_exists) {
        DebugUtils::PrintOutput(Console, Warn, StringUtils::Format("SpriteObject::SpriteObject() failed to load \"%s\".\n", texture_name.c_str()));
        texture_name = "Resources/png/null.png";
    }    
    
    if(surface) {
        surface = nullptr;
        SDL_FreeSurface(surface);
    }
        
    if(texture) {
        texture = nullptr;
        SDL_DestroyTexture(texture);
    }
            
    std::string error_text = "SpriteObject::load_texture() Failed: %s\n";
    update_dest_rect(position, size);

    surface = IMG_Load(texture_name.c_str());
    if(surface == nullptr)
        throw std::runtime_error(StringUtils::Format(error_text.c_str(), StringUtils::Format("IMG_Load failed for \"%s\"", texture_name.c_str()).c_str()).c_str());

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    
    // Dispose of surface after conversion
    SDL_FreeSurface(surface);
    surface = nullptr;
    
    if(texture == nullptr)
        throw std::runtime_error(StringUtils::Format(error_text.c_str(), "SDL_CreateTextureFromSurface() returned nullptr\n").c_str());

    SDL_SetTextureColorMod(texture, color_mod.r, color_mod.g, color_mod.b);
    SDL_SetTextureAlphaMod(texture, alpha); 
}

void SpriteObject::set_color_mod(Color3 color_mod) {
    if(color_mod != this->color_mod) {
        this->color_mod = color_mod;
        load_texture();
    }
}

Color3 SpriteObject::get_color_mod() {
    return color_mod;
}

void SpriteObject::set_alpha(int alpha) {
    if(alpha != this->alpha) {
        this->alpha = alpha;
        load_texture(); 
    }
}

int SpriteObject::get_alpha() {
    return alpha;
}

SpriteObject::~SpriteObject() {
    printf("~SpriteObject()\n");
    if(surface)
        SDL_FreeSurface(surface);
    if(texture)
        SDL_DestroyTexture(texture);
}