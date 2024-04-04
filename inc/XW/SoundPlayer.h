#include <SDL_mixer.h>
#include <string>
#include "StringUtils.h"
#include "DebugUtils.h"

#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H
class SoundPlayer {
    public:
        static SoundPlayer* get_instance();
        static void destroy_instance();
        void play_sfx(std::string file_name, int channel, int loops);
        void play_music(std::string file_name, int loops);
    private:
        static SoundPlayer* instance;

        Mix_Chunk* load_sfx(std::string sfx_name);
        Mix_Music* load_music(std::string music_name);

        SoundPlayer();
        ~SoundPlayer();
};
#endif