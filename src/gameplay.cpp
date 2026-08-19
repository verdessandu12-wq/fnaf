#include "gameplay.hpp"
#include "raylib.h"
#include "stb_image.h"
#include <string>
#include <format>
using namespace std;

void gameplay::import_variable(){
    x = 400.0f;
    y = 0.0f;
    cameraX = 0.0f;
    timer_mindbar = 0;
    status_mindbar = 100;
    coef_mindbar = 1;
    current_mindbar = 5;
    office = LoadTexture("../assets/office.jpg");
    gameover = false;
    //PlayMusicStream(ambient);
    for (int i = 0; i < 6; i++){
        string tempText = format("../assets/mind-bar/mindbar{}.png", i);
        Texture2D tempTex = LoadTexture(tempText.c_str());
        Rectangle tempSource = {0, 0, (float)tempTex.width, (float)tempTex.height};
        Rectangle tempDest = {1280.0f - (float)tempTex.width, 50, 100, 200};
        Vector2 tempOrigin = {0.0f, 0.0f};
        float tempAngle = 0.0f;
        mindbar.emplace_back(tempTex, tempSource, tempDest, tempOrigin, tempAngle, WHITE);
    }
}
void gameplay::rendering(){
    origin = {0.0f, 0.0f};
    texture_rect = {x, y, 3500.0f, 2160.0f};
    dest = {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};
    DrawTexturePro(office, texture_rect, dest,  origin, 0.0f,  WHITE);
    //SetMusicVolume(ambient, 1.0f);

    
}
void gameplay::move_camera(){
    if (IsKeyDown(KEY_A) && x > 0){
        x -= 40;
    }                                                                                                          
    if (IsKeyDown(KEY_D) && x < 4300 - texture_rect.width){
        x += 40;
    }
}
void gameplay::mindbar_logic(){
    timer_mindbar += GetFrameTime();
    if(timer_mindbar >= 0.5f * coef_mindbar){
        status_mindbar--;
        if(status_mindbar >= 80){
            current_mindbar = 5;
        }
        if(status_mindbar < 80 && status_mindbar >= 60){
            current_mindbar = 4;
        }
        if(status_mindbar < 60 && status_mindbar >= 40){
            current_mindbar = 3;
        }
        if(status_mindbar < 40 && status_mindbar >= 20){
            current_mindbar = 2;
        }
        if(status_mindbar < 20 && status_mindbar > 0){
            current_mindbar = 1;
        }
        if(status_mindbar <= 0){
            current_mindbar = 0;
            gameover = true;
        }
        timer_mindbar = 0;
    }
}
void gameplay::mindbar_rendering(){
        DrawTexturePro(mindbar[current_mindbar].texture, mindbar[current_mindbar].source, mindbar[current_mindbar].dest, mindbar[current_mindbar].origin, mindbar[current_mindbar].angle, mindbar[current_mindbar].col);
}