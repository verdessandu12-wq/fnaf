#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
#include "raylib.h"
#include <vector>
#include "sablonClass.hpp"
using namespace std;
class gameplay {
    public:
    Texture2D office;
    float x, y, cameraX;
    Vector2 origin;
    Rectangle texture_rect, dest;
    int current_mindbar, status_mindbar, timer_mindbar, coef_mindbar;
    vector<imgClass> mindbar;
    bool gameover;
    void import_variable();
    void rendering();
    void mindbar_logic();
    void mindbar_rendering();
    void move_camera();
    ~gameplay(){
        UnloadTexture(office);
    }

};
#endif