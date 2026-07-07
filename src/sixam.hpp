#ifndef SIXAM_HPP
#define SIXAM_HPP
#include "raylib.h"
#include "sablonClass.hpp"
#include <vector>
class sixam {
    public:
    float w, h, timer;
    int numberi;
    std::vector<imgClass> sixamobj;
    void importVariable();
    void rendering();
    void logic();
};
#endif