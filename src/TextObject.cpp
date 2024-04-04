#include "XW/TextObject.h"

#include "XW/StringUtils.h"
#include "XW/DebugUtils.h"

#include <stdexcept>

TextObject::TextObject
(
    std::string text_content, 
    int font_size, 
    Vector2 position, 
    std::string font_file_name
) 
{
    // set values
    this->text_content = text_content;
    this->font_name = font_file_name;
    this->font_size = font_size;
    this->position = position;

    // set them to null so they aren't garbage
    this->surface = nullptr;
    this->texture = nullptr;
    this->font = nullptr;

    object_name = "TextObject";
    object_class_name = "TextObject";

    try {
        this->load_font(this->font_name, this->font_size);
        this->update_text_rect();
    } catch(const std::runtime_error& e) {
        DebugUtils::PrintOutput(Console, Error, std::string(e.what()));
    }
}

void TextObject::update_text_rect() {
    Vector2 pos = this->get_position();
    Vector2 new_size = Vector2(this->surface->w, this->surface->h);
    this->set_size(new_size);

    this->obj_rect = {pos.X, pos.Y, new_size.X, new_size.Y};
}

void TextObject::load_font(std::string font_name, int font_size) {
    std::string error_text = "TextObject::load_font() Failed: %s\n";

    this->font = TTF_OpenFont(font_name.c_str(), font_size);
    if (this->font == nullptr)
        throw std::runtime_error(StringUtils::Format(error_text.c_str(), StringUtils::Format("TTF_OpenFont failed for \"%s\"", font_name.c_str()).c_str()).c_str());
    
    this->surface = TTF_RenderText_Blended_Wrapped(this->font, this->text_content.c_str(), SDL_Color{255, 255, 255, 255}, 800);
    if (this->surface == nullptr)
        throw std::runtime_error(StringUtils::Format(error_text.c_str(), "TTF_RenderText_Blended_Wrapped() returned nullptr\n").c_str());
        
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
    if (this->texture == nullptr)
        throw std::runtime_error(StringUtils::Format(error_text.c_str(), "SDL_CreateTextureFromSurface() returned nullptr\n").c_str());
}

void TextObject::unload_font() {
    if(surface)
        SDL_FreeSurface(surface);
    
    if(texture)
        SDL_DestroyTexture(texture);

    if(font)
        TTF_CloseFont(font);

    surface = nullptr;
    texture = nullptr;
    font = nullptr;
}

void TextObject::set_font(std::string new_font_name) {
    if(font) {
        if(font_name == new_font_name)
            return;

        unload_font();
        font_name = new_font_name;
        load_font(font_name, font_size);
        update_text_rect();
    } else {
        DebugUtils::PrintOutput(Console, Error, "TextObject::set_font() Failed: Font is NULL\n");
    }  
}

void TextObject::set_content(std::string new_content) {
    if(font) {
        if(text_content == new_content)
            return;
        unload_font();
        text_content = new_content;
        load_font(font_name, font_size);
        update_text_rect();
    } else {
        DebugUtils::PrintOutput(Console, Error, "TextObject::set_content() Failed: Font is NULL\n");
    }  
}

void TextObject::set_font_size(int new_font_size) {
    if(font) {
        if(font_size == new_font_size)
            return;
        font_size = new_font_size;
        unload_font();
        load_font(font_name, font_size);
        update_text_rect();
    } else {
        DebugUtils::PrintOutput(Console, Error, "TextObject::set_font_size() Failed: Font is NULL\n");
    }
}

void TextObject::draw() {
    if(this->font) 
        SDL_RenderCopyF(this->renderer, this->texture, nullptr, &this->obj_rect);
}

void TextObject::update(float delta_time) {
    update_text_rect();
}

TextObject::~TextObject() {
    printf("~TextObject()\n");

    if(this->surface)
        SDL_FreeSurface(this->surface);
        
    if(this->texture)
        SDL_DestroyTexture(this->texture);
        
    if(this->font)
        TTF_CloseFont(this->font);
}