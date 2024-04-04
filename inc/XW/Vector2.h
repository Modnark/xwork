#ifndef VECTOR2_H
#define VECTOR2_H
class Vector2 {
    public:
        float X = 0.0f;
        float Y = 0.0f; 
        Vector2(float x, float y);
        bool operator==(Vector2 other);
        bool operator!=(Vector2 other);
};
#endif