#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "Vector2.h"

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
class GameWindow {

    public:
        GameWindow(std::string title, Vector2 size);
        GameWindow();
        void show(bool doShow);
        Vector2 get_size();
        bool is_visible();
        SDL_Renderer* get_renderer();
        SDL_Window* get_window();
        bool is_initialized();
        ~GameWindow();
    private:
        Vector2 size = Vector2(0.0f,0.0f);;
        bool visible;
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
};
#endif