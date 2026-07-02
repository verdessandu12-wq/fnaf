#include "gameplay.hpp"
#include "raylib.h"

using namespace std;
void gameplay::import_variable(){
    x = 400.0f;
    y = 3.5f;
    fx = 600.0f;
    fy = 311.0f;
    rfx = 0;
    rfy = 10;
    wf = 231;
    hf = 180;
    coef = 1;
    frameCount = 0;
    frameFan = 0;
    cameraX = 0.0f;
    office = LoadTexture("../assets/office.png");
    fans = LoadTexture("../assets/fan.png");
    fan = LoadMusicStream("../song/fanFnaf.mp3");
    PlayMusicStream(fan);
}
void gameplay::rendering(){
    frameCount++;
    origin = {cameraX, 0.0f};
    texture_rect = {x, y, 800.0f, 721.0f};
    dest = {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};
    fan_origin = {0.0f, 0.0f};
    fan_rect = {rfx, rfy, 140.0f, 180.0f};
    fan_dest = {fx, fy, wf, hf};
    if(frameCount > 4){
        frameFan++;
        frameCount = 0;
    }
    if(frameFan >= 3){
        frameFan = 0;
    }
    rfx = fan_rect.width * frameFan;
    DrawTexturePro(office, texture_rect, dest,  origin, 0.0f,  WHITE);
    DrawTexturePro(fans, fan_rect, fan_dest,  fan_origin, 0.0f,  WHITE);
}
void gameplay::move_camera(){
    /*
    fx = GetMouseX();
    fy = GetMouseY();
     */
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        rfx += coef;
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
        rfy += coef;
    }
       
    if (IsKeyDown(KEY_A) && x > 0){
        x -= 20;
        fx += 32;
    }
    if (IsKeyDown(KEY_D) && x < 1600 - 800){
        x += 20;
        fx -= 32;
    }

    if (IsKeyPressed(KEY_S)){
        coef = -coef;
    }
        
    UpdateMusicStream(fan);
}