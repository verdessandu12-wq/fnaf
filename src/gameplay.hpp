#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
#include "raylib.h"
class gameplay {
    public:
    int frameCount, frameFan, coef;
    Texture2D office, fans;
    float x, y, cameraX, fx, fy, rfx, rfy, wf, hf;
    Vector2 origin, fan_origin;
    Rectangle texture_rect, dest, fan_rect, fan_dest;
    Music fan;
    void import_variable();
    void rendering();
    void move_camera();

};
#endif