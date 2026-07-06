#include "pad.hpp"
#include <vector>
#include "raylib.h"
#include <string>
#include <chrono>
#include <iostream>

using namespace std;
void animPad::importVariable(){
    for(int i = 1; i < 5; i++){
        string path = "../assets/pad/pad" + to_string(i) + ".png";
        Texture2D temp = LoadTexture(path.c_str());
        pad.push_back(temp);
    }
    source = {0, 0, 2112, 1320};
    w = 1280;
    h = 720;
    dest = {0, 0, w, h};
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
        cout << "good" << endl;
        tap = false;
    }
    if(coef == -1 && num <= 0){
        coef = -coef;
        num = 0;
        tap = false;
    }
    timer += GetFrameTime();
    if(timer >= 0.05f){
    cout << num << endl;
    num += coef;
    timer = 0.0f;
    }
}
}
void animPad::startAnim(){
    if(tap){
        DrawTexturePro(pad[num], source, dest, {0.0f, 0.0f}, 0.0f, WHITE);
    }
}

