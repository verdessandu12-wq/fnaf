#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "raylib.h"
#include <vector>
using namespace std;
class camera {
    public:
    float w, h;
    Shader shader;
    Texture2D map;
    Vector2 posMap;
    vector<Texture2D> room;
    vector<Rectangle> button;
    vector<Rectangle> dest, source;
    int current_room;
    void import_variable();
    void rendering();
    void switch_room();

};
#endif