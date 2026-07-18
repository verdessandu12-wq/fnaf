#include "gameplay.hpp"
#include "raylib.h"

using namespace std;
void gameplay::import_variable(){
    x = 400.0f;
    y = 0.0f;
    cameraX = 0.0f;
    office = LoadTexture("../assets/office.jpg");
    //fans = LoadTexture("../assets/fan.png");
    //fan = LoadMusicStream("../song/fanFnaf.mp3");
    //PlayMusicStream(fan);
}
void gameplay::rendering(){
    origin = {0.0f, 0.0f};
    texture_rect = {x, y, 3000.0f, 2160.0f};
    dest = {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};
    DrawTexturePro(office, texture_rect, dest,  origin, 0.0f,  WHITE);
}
void gameplay::move_camera(){
    if (IsKeyDown(KEY_A) && x > 0){
        x -= 20;
    }                                                                                                          
    if (IsKeyDown(KEY_D) && x < 4300 - texture_rect.width){
        x += 20;
    }
}