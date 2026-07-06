#ifndef PAD_HPP
#define PAD_HPP
#include <vector>
#include "raylib.h"
using namespace std;
class animPad{
    public:
    vector<Texture2D> pad;
    int num, coef, result;
    float w, h, timer, timerX;
    Rectangle dest, source;
    bool tap;
    void importVariable();
    void logic();
    void startAnim();
};
#endif