#include "XW/Collision.h"

bool Collision::test(BaseObject* obj1, BaseObject* obj2, CollisionDirection* direction, float delta_time) {
    SDL_FRect bb1 = obj1->get_rect();
    SDL_FRect bb2 = obj2->get_rect();

    Vector2 velocity1 = obj1->get_velocity();
    Vector2 velocity2 = obj2->get_velocity();

    bb1.x += velocity1.X * delta_time;
    bb1.y += velocity1.Y * delta_time;
    bb2.x += velocity2.X * delta_time;
    bb2.y += velocity2.Y * delta_time;

    if (bb1.x + bb1.w <= bb2.x || bb1.x >= bb2.x + bb2.w || bb1.y + bb1.h <= bb2.y || bb1.y >= bb2.y + bb2.h) {
        *direction = COLLISION_NONE;
        return false;
    } else {
        float dx = (bb2.x + bb2.w / 2) - (bb1.x + bb1.w / 2);
        float dy = (bb2.y + bb2.h / 2) - (bb1.y + bb1.h / 2);
        float combinedHalfWidths = (bb1.w + bb2.w) / 2;
        float combinedHalfHeights = (bb1.h + bb2.h) / 2;
        float overlapX = combinedHalfWidths - fabs(dx);
        float overlapY = combinedHalfHeights - fabs(dy);

        if (overlapX > 0 && overlapY > 0) {
            if (overlapX < overlapY) {
                if (dx > 0) {
                    *direction = COLLISION_LEFT;
                } else {
                    *direction = COLLISION_RIGHT;
                }
            } else {
                if (dy > 0) {
                    *direction = COLLISION_TOP;
                } else {
                    *direction = COLLISION_BOTTOM;
                }
            }

            return true;
        } else {
            *direction = COLLISION_NONE;
            return false;
        }
    }
}
