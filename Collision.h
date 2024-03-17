#include "BaseObject.h"
#include "Enum.h"
#include <cmath>

#ifndef COLLISION_H
#define COLLISION_H
class Collision {
    public:
        static bool test(BaseObject* obj1, BaseObject* obj2, CollisionDirection* direction, float delta_time);
};
#endif