#include "XW/Color3.h"

Color3::Color3(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

bool Color3::operator==(Color3 other) {
    return r == other.r && g == other.g && b == other.b;
}

bool Color3::operator!=(Color3 other) {
    return r != other.r || g != other.g || b != other.b;
}