#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "raylib.h"
using namespace std;
class camera {
    public:
    Texture2D room;
    int current_room;
    void rendering();
    void switch_room();

};
#endif