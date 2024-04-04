#ifndef COLOR3_H
#define COLOR3_H
class Color3 {
    public:
        int r = 255;
        int g = 255;
        int b = 255;
        Color3(int r, int g, int b);
        bool operator==(Color3 other);
        bool operator!=(Color3 other);
};
#endif