#include "Timer.h"

Timer* Timer::instance = nullptr;

Timer* Timer::get_instance() {
    if(instance == nullptr)
        instance = new Timer();

    return instance;
}

Timer::Timer() {
    reset();
    time_scale = 1.0f;
}

void Timer::reset() {
    start_ticks = SDL_GetTicks();
    elapsed_ticks = 0;
    delta_time = 0.0f;
}

float Timer::get_delta_time() {
    return delta_time;
}

void Timer::set_time_scale(float time_scale) {
    this->time_scale = time_scale;
}

float Timer::get_time_scale() {
    return time_scale;
}

void Timer::update() {
    elapsed_ticks = SDL_GetTicks() - start_ticks;
    delta_time = elapsed_ticks * 0.001f;
}

Timer::~Timer() {
    if(instance) {
        delete instance;
        instance = nullptr;
    }
}
