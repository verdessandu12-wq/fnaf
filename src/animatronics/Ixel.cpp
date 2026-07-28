#include "raylib.h"
#include "Ixel.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void Ixel::importVariable(){
    w = 1280;
    h = 720;
    shader = LoadShader(0, "../shader/first_shader_animatronics.fs");
    for(int i = 1; i < 11; i++){
        string tempString = "../assets/animatronics/Ixel" + to_string(i) + ".png";
        Texture2D tempTexture = LoadTexture(tempString.c_str());
        Rectangle sourceTemp = {0.0f, 0.0f, (float)tempTexture.width, (float)tempTexture.height};
        Rectangle destTemp = {0.0f, 0.0f, (float)tempTexture.width / 4, (float)tempTexture.height / 4};
        Vector2 originTemp = {0.0f, 0.0f};
        animatronic.emplace_back(tempTexture, sourceTemp, destTemp, originTemp, 0.0f, WHITE);
    }
    nightCoef = 1;
    current_room_animatronic = 0;
}
void Ixel::logic(){
    timer += GetFrameTime();
    //cout << "Logica merge";
}
void Ixel::rendering(int current_room){
    if(timer >= 1.1f){
    cout << current_room;
    timer = 0;
    }
    if(current_room_animatronic == camera1.current_room){
    BeginShaderMode(shader);
        DrawTexturePro(animatronic[current_room_animatronic].texture, animatronic[current_room_animatronic].source, animatronic[current_room_animatronic].dest, animatronic[current_room_animatronic].origin, animatronic[current_room_animatronic].angle, animatronic[current_room_animatronic].col);
    EndShaderMode();
    }
    if(IsKeyPressed(KEY_H)){
        cout << "\nCR: " << camera1.current_room << "\n";
    }
}