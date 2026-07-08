#include "pad.hpp"
#include "shader.hpp"
#include <vector>
#include "raylib.h"
#include <string>
#include <chrono>
#include <iostream>

using namespace std;
void animPad::importVariable(){
    w = 1280;
    h = 720;
    for(int i = 1; i < 5; i++){
        string path = "../assets/pad/pad" + to_string(i) + ".png";
        Texture2D temp = LoadTexture(path.c_str());
        Rectangle tempDest = {0, 0, w, h};
        Rectangle tempSource = {0, 0, 2112, 1320};
        Vector2 tempOrigin = {0.0f, 0.0f};
        pad.emplace_back(temp, tempSource, tempDest, tempOrigin, 0.0f, WHITE);
    }
    shader1.init();
    
  
    tap = false;
    num = 1;
    coef = 1;
    result = 4;
}
void animPad::logic(){
    if(tap){
    if(coef == 1 && num >= 3){
        coef = -coef;
        num = 3;
        tap = false;
    }
    if(coef == -1 && num <= 0){
        coef = -coef;
        num = 0;
        tap = false;
    }
    timer += GetFrameTime();
    if(timer >= 0.05f){
    num += coef;
    timer = 0.0f;
    }
}
}
void animPad::startAnim(){
    //BeginShaderMode(shader1.firstShader);
    if(tap){
        DrawTexturePro(pad[num].texture, pad[num].source, pad[num].dest, pad[num].origin, pad[num].angle, pad[num].col);
    }
    //EndShaderMode();
}
void animPad::unload(){
    shader1.cleanUp();
}

