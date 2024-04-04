#include "XW/GameWindow.h"

GameWindow::GameWindow(std::string title, Vector2 size) {
    this->size = size;
    window = nullptr;
    renderer = nullptr;

    SDL_CreateWindowAndRenderer(
        size.X, size.Y,
        SDL_WINDOW_HIDDEN, &window, &renderer
    );

    SDL_SetWindowTitle(window, title.c_str());
}

GameWindow::GameWindow() {}

void GameWindow::show(bool doShow) {
    visible = doShow;
    SDL_ShowWindow(window);
}

Vector2 GameWindow::get_size() {
    return size;
}

bool GameWindow::is_visible() {
    return visible;
}

SDL_Renderer* GameWindow::get_renderer() {
    return renderer;
}

SDL_Window* GameWindow::get_window() {
    return window;
}

bool GameWindow::is_initialized() {
    return window != nullptr;
}

GameWindow::~GameWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    renderer = nullptr;
    window = nullptr;
}