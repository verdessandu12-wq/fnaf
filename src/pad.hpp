#ifndef PAD_HPP
#define PAD_HPP
#include <vector>
#include "raylib.h"
#include "shader.hpp"
#include "sablonClass.hpp"
using namespace std;
class animPad{
    public:
    shaderClass shader1;
    vector<imgClass> pad;
    int num, coef, result;
    float w, h, timer, timerX;
    bool tap;
    void importVariable();
    void logic();
    void startAnim();
    void unload();
};
#endif