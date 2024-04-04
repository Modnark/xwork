#include "XW/Game.h"
#include "XW/DebugUtils.h"
#include <iostream>

Game* Game::instance = nullptr;
Game* Game::get_instance() {
    if(!instance)
        instance = new Game();
    return instance;
}

void Game::shutdown() {
    if(instance) {
        delete instance;
        instance = nullptr;
    }
}

Game::Game() {
    DebugUtils::PrintOutput(Console, Info, "[Game::Game()] Initializing...\n");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 || TTF_Init() != 0) {
        printf("SDL_Init(SDL_INIT_VIDEO | SDL_INIT_VIDEO) failed!\n");
    }

    DebugUtils::PrintOutput(Console, Info, "[Game::Game()] Initialized.\n");

    game_timer = Timer::get_instance();
}

bool Game::is_running() {
    return running;
}

void Game::run() {
    running = true;
}

void Game::stop() {
    running = false;
}

void Game::create_window(std::string title, Vector2 size) {
    if (game_window) {
        DebugUtils::PrintOutput(Console, Warn, "[Game::create_window()] Window is already created.\n");
        return;
    }

    game_window = new GameWindow(title, size);
    
    if (!game_window) {
        DebugUtils::PrintOutput(Console, Error, "[Game::create_window()] Failed to create window.\n");
        return;
    }

    DebugUtils::PrintOutput(Console, Info, "[Game::create_window()] Window created successfully.\n");
}

void Game::set_target_framerate(Uint32 target_framerate) {
    TARGET_FRAME_RATE = target_framerate;
}

GameWindow* Game::get_window() {
    if (!game_window) {
        DebugUtils::PrintOutput(Console, Error, "[Game::get_window()] Window is NULL.\n");
        return nullptr;
    }
    return game_window;
}

/*
 * Name: Game::add_game_object
 * Description: Pushes a specified BaseObject* to game_object_list
*/
void Game::add_game_object(BaseObject* object) {
    game_object_list.push_back(object);
}

/*
 * Name: Game::remove_game_object
 * Description: Removes specified BaseObject* from game_object_list
*/
void Game::remove_game_object(BaseObject* object) {
    for(int i = 0; i < game_object_list.size(); i++)
    {
        if(game_object_list.at(i) == object) {
            delete game_object_list.at(i);
            game_object_list.erase(game_object_list.begin() + i);
            break;
        }
    }
}

/*
 * Name: Game::get_game_objects
 * Description: Gets all BaseObject* instances within game_object_list
 * Returns: std::vector<BaseObject*> containing all game objects
*/
std::vector<BaseObject*> Game::get_game_objects() {
    return game_object_list;
}

/*
 * Name: Game::get_game_objects_by_name
 * Description: Gets all BaseObject* instances within game_object_list that have the matching "name"
 * Returns: std::vector<BaseObject*> containing all found instances
*/
std::vector<BaseObject*> Game::get_game_objects_by_name(std::string name) {
    std::vector<BaseObject*> name_game_object_list;
    for (const auto& obj : game_object_list) {
        if (obj->get_name() == name) {
            name_game_object_list.push_back(obj);
        }
    }
    return name_game_object_list;
}

/*
 * Name: Game::get_game_object_by_name
 * Description: Gets a BaseObject* instance within game_object_list that has the matching "name"
 * Returns: BaseObject* that shares the same name, otherwise returns nullptr
*/
BaseObject* Game::get_game_object_by_name(std::string name) {
    for (const auto& obj : game_object_list) {
        if (obj->get_name() == name) {
            return obj;
        }
    }    
    return nullptr;
}

/*
 * Name: Game::get_game_objects_by_class_name
 * Description: Gets all BaseObject* instances within game_object_list that have the matching "class_name"
 * Returns: std::vector<BaseObject*> containing all found instances
*/
std::vector<BaseObject*> Game::get_game_objects_by_class_name(std::string class_name) {
    std::vector<BaseObject*> class_name_game_object_list;
    for (const auto& obj : game_object_list) {
        if (obj->get_class_name() == class_name) {
            class_name_game_object_list.push_back(obj);
        }
    }
    return class_name_game_object_list;
}

int Game::get_fps() {
    return ceil(game_fps);
}

// TODO: clean!
void Game::step() {
    if(!game_window)
        return;

    game_timer->update();

    bool is_event = SDL_PollEvent(&event);
    if (is_event && event.type == SDL_QUIT) {
        DebugUtils::PrintOutput(Console, Warn, "[Game::step_event] Caught SDL_QUIT | Quitting...\n");
        running = false;
    }

    float step_delta_time = game_timer->get_delta_time();

    if(step_delta_time >= (1.0f/TARGET_FRAME_RATE)) {
        game_fps = 1.0f / step_delta_time;

        for(int i = 0; i < game_object_list.size(); i++) {
            BaseObject* obj = game_object_list.at(i);
            if(obj->is_active())
                obj->update(step_delta_time);
        }
        game_timer->reset();
    }

    SDL_SetRenderDrawColor(game_window->get_renderer(), 0, 0, 0, 0);
    SDL_RenderClear(game_window->get_renderer());

    for(int i = 0; i < game_object_list.size(); i++) {
        BaseObject* obj = game_object_list.at(i);
        if (is_event && obj->is_active())
            obj->event_update(event);

        if(obj->is_visible())
            obj->draw();
    }

    SDL_RenderPresent(game_window->get_renderer());
}

Game::~Game() {
    DebugUtils::PrintOutput(Console, Warn, "[Game::~Game()] Shutting down...\n");
    Timer::destroy_instance();
    SoundPlayer::destroy_instance();    

    for(int i = 0; i < game_object_list.size(); i++)
    {
        printf("Deleting object with name: %s\n", game_object_list.at(i)->get_name().c_str());
        delete game_object_list.at(i);
    }
    game_object_list.clear();

    // Might move this next to delete instance, not sure why it's up here :?
    if(game_window) {
        delete game_window;
        game_window = nullptr;
    }
    
    TTF_Quit();
    SDL_Quit();
}