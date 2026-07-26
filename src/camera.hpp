#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "raylib.h"
#include <vector>
#include "gameplay.hpp"
#include "sablonClass.hpp"
using namespace std;
class camera {
    public:
    gameplay game1;
    float w, h;
    Shader shader;
    vector<imgClass> camera;
    vector<Rectangle> button;
    Texture2D map;
    Vector2 posMap;
    int current_room;
    void import_variable();
    void rendering();
    void switch_room();
    ~camera(){
        for(int i = 0; i < camera.size(); i++){
            UnloadTexture(camera[i].texture);
        }
        UnloadTexture(map);
    }

};
#endif