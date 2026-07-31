#ifndef IXEL_HPP
#define IXEL_HPP
#include "raylib.h"
#include "animatronics.hpp"
#include "../camera.hpp"
class Ixel : public animatronics {
    public:
    float w, h;
    camera &camera1;
    Shader shader;
    Ixel(camera &cam) : camera1(cam){}
    void importVariable()override;
    void rendering()override;
    void logic()override;
};

#endif