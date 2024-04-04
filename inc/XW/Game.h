#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#include "BaseObject.h"
#include "GameWindow.h"
#include "Vector2.h"
#include "Timer.h"
#include "SoundPlayer.h"
#include <cmath>

#ifndef GAME_H
#define GAME_H
class Game {

    public:
        static Game* get_instance();
        static void shutdown();
        void show(bool doShow);
        bool is_running();
        GameWindow* get_window();
        void create_window(std::string title, Vector2 size);
        void add_game_object(BaseObject* object);
        void remove_game_object(BaseObject* object);
        std::vector<BaseObject*> get_game_objects();
        std::vector<BaseObject*> get_game_objects_by_name(std::string name);
        std::vector<BaseObject*> get_game_objects_by_class_name(std::string class_name);
        BaseObject* get_game_object_by_name(std::string name);
        void set_target_framerate(Uint32 target_framerate);
        void step();
        void run();
        void stop();
        int get_fps();

        ~Game();
    private:
        Game();
        static Game* instance;
        bool running;
        GameWindow* game_window;
        std::vector<BaseObject*> game_object_list;
        SDL_Event event;
        float game_fps;
        Timer* game_timer;
        int TARGET_FRAME_RATE = 144;
};
#endif