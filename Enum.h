#ifndef ENUM_H
#define ENUM_H
enum OutputLevel {
    Console,
    ScreenSpace,
    ConsoleScreenSpace
};

enum OutputType {
    General,
    Info,
    Warn,
    Error
};

enum CollisionDirection {
    COLLISION_NONE,
    COLLISION_TOP,
    COLLISION_BOTTOM,
    COLLISION_LEFT,
    COLLISION_RIGHT
};

#endif