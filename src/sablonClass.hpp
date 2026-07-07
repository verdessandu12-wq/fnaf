#ifndef SABLONCLASS_HPP
#define SABLONCLASS_HPP
#include "raylib.h"
class imgClass{
    public:
    Texture2D texture;
    Rectangle source, dest;
    Vector2 origin;
    float angle;
    Color col;
    imgClass(Texture2D tex, Rectangle sour, Rectangle des, Vector2 ori, float ang,  Color co) : texture(tex), source(sour), dest(des), origin(ori), angle(ang), col(co) {}
};
#endif