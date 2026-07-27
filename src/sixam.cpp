#include "sixam.hpp"
#include "raylib.h"
#include <vector>
#include <string>
#include <iostream>

void sixam::importVariable(){
         w = 1280;
        h = 720;
    /*for (int i = 1; i < 47; i++){
        std::cout << i << "\t";
        std::string temp = "../assets/sixam/sixam" + std::to_string(i) + ".jpg";
        Texture2D tempTexture = LoadTexture(temp.c_str());
        Rectangle tempSource = {0, 0, 2880, 2160};
        Rectangle tempDest = {0, 0, w, h};
        Vector2 tempOrigin = {0, 0};
        float tempAngle = 0.0f;
        Color tempCol = WHITE;
        sixamobj.emplace_back(tempTexture, tempSource, tempDest, tempOrigin, 0.0f, tempCol);
    }*/
    end = LoadMusicStream("../song/sixam.mp3");
    numberi = 0;
    PlayMusicStream(end);
}
void sixam::rendering(){
    timer += GetFrameTime();
    DrawTexturePro(sixamobj[numberi].texture, sixamobj[numberi].source, sixamobj[numberi].dest, sixamobj[numberi].origin, sixamobj[numberi].angle, sixamobj[numberi].col);
    if(timer >= 0.1f){
        if(numberi != 17){
            numberi++;
            timer = 0.0f;
        }
        else if(numberi == 17 && timer >= 5.5f){
            numberi++;
            timer = 0.0f;
        }
    }
    if(numberi >= sixamobj.size()){
        numberi = 0;
    }
      
    UpdateMusicStream(end);
}
void sixam::logic(){
    globalTimer += GetFrameTime();
}