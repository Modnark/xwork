#include "SoundPlayer.h"

// TODO: cleanup & make easier to use externally

SoundPlayer* SoundPlayer::instance = nullptr;
SoundPlayer* SoundPlayer::get_instance() {
    if(!instance)
        instance = new SoundPlayer();
    return instance;
}

SoundPlayer::SoundPlayer() {
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        DebugUtils::PrintOutput(Console, Error, StringUtils::Format("SoundPlayer::SoundPlayer() Failed: %s\n", Mix_GetError()));
    }
}

SoundPlayer::~SoundPlayer() {
    Mix_Quit();
    if(instance) {
        delete instance;
    }
}

Mix_Chunk* SoundPlayer::load_sfx(std::string sfx_name) {
    Mix_Chunk* sfx = Mix_LoadWAV(sfx_name.c_str());
    if(sfx == nullptr) {
        DebugUtils::PrintOutput(Console, Error, "SoundPlayer::load_sfx() Failed: Mix_LoadWAV returned NULL\n");
    }

    return sfx; 
}

Mix_Music* SoundPlayer::load_music(std::string music_name) {
    Mix_Music* music = Mix_LoadMUS(music_name.c_str());
    if(music == nullptr) {
        DebugUtils::PrintOutput(Console, Error, "SoundPlayer::load_music() Failed: Mix_LoadMUS returned NULL\n");
    }

    return music; 
}

void SoundPlayer::play_music(std::string file_name, int loops) {
    Mix_Music* mus = load_music(file_name);
    if(mus) 
        Mix_PlayMusic(mus, loops);
}

void SoundPlayer::play_sfx(std::string file_name, int channel, int loops) {
    Mix_Chunk* sfx = load_sfx(file_name);
    if(sfx) 
        Mix_PlayChannel(channel, sfx, loops);
}