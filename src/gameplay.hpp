#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
#include "raylib.h"
class gameplay {
    public:
    Texture2D office;
    float x, y, cameraX;
    Vector2 origin;
    Rectangle texture_rect, dest;
    void import_variable();
    void rendering();
    void move_camera();
    ~gameplay(){
        UnloadTexture(office);
    }

};
#endif