#include "XW/Vector2.h"

Vector2::Vector2(float x, float y) {
    this->X = x;
    this->Y = y;
}

bool Vector2::operator==(Vector2 other) {
    return X == other.X && Y == other.Y;
}

bool Vector2::operator!=(Vector2 other) {
    return X != other.X || Y != other.Y;
}