#include <SDL2/SDL.h>

#ifndef TIMER_H
#define TIMER_H
class Timer {
    public:
        static Timer* get_instance();
        
        void update();
        void reset();
        float get_delta_time();

        void set_time_scale(float time_scale);
        float get_time_scale();
    private:
        static Timer* instance;
        
        float delta_time;
        float time_scale;

        Uint32 start_ticks;
        Uint32 elapsed_ticks;

        Timer();
        ~Timer();
};
#endif