#ifndef IXEL_HPP
#define IXEL_HPP
#include "raylib.h"
#include "animatronics.hpp"
#include "../camera.hpp"
class Ixel : public animatronics {
    public:
    camera camera1;
    void importVariable() override;
    void rendering() override;
    void logic() override;
};

#endif