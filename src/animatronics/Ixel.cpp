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
        string tempString = "../assets/animatronics/Ixel" + to_string(1) + ".png";
        Texture2D tempTexture = LoadTexture(tempString.c_str());
        Rectangle sourceTemp = {0.0f, 0.0f, (float)tempTexture.width, (float)tempTexture.height};
        Rectangle destTemp = {0.0f, 0.0f, (float)tempTexture.width / 4, (float)tempTexture.height / 4};
        Vector2 originTemp = {0.0f, 0.0f};
        animatronic.emplace_back(tempTexture, sourceTemp, destTemp, originTemp, 0.0f, WHITE);
    }
    nightCoef = 1;
    current_room_animatronic = 2;
}
void Ixel::logic(){
    timer += GetFrameTime();
    if(timer >= 5.0f * nightCoef){
        int tempRandom = GetRandomValue(0, 100);
        switch(current_room_animatronic){
        case 0:
        if(tempRandom <= 50)current_room_animatronic = 1;
        else if(tempRandom > 50){
            if(tempRandom % 2 == 0){
                current_room_animatronic = 9;
            }
            else if(tempRandom % 2 != 0){
                current_room_animatronic = 8;
            }
        }
        timer = 0.0f;
        break;
        case 1:
        if(tempRandom <= 50)current_room_animatronic = 3;
        else if(tempRandom > 50){
            if(tempRandom % 2 == 0){
                current_room_animatronic = 9;
            }
            else if(tempRandom % 2 != 0){
                current_room_animatronic = 8;
            }
        }
        /*else if(tempRandom >= 99){
            if(tempRandom % 2 == 0){
                current_room_animatronic = 5;
            }
            else if(tempRandom % 2 != 0){
                current_room_animatronic = 6;
            }
        }*/

        timer = 0.0f;
        break;
        case 2:
        if(tempRandom <= 40)current_room_animatronic = 3;
        else if(tempRandom > 40 && tempRandom < 99)current_room_animatronic = 1;
        else if(tempRandom >= 99)current_room_animatronic = 0;
        timer = 0.0f;
        break;
        case 3:
        if(tempRandom <= 30)current_room_animatronic = 1;
        else if(tempRandom > 30)current_room_animatronic = 4;

        timer = 0.0f;
        break;
        case 4:
        if(tempRandom <= 20)current_room_animatronic = 1;
        if(tempRandom > 20)current_room_animatronic = 5;

        timer = 0.0f;
        break;
        case 5:
        current_room_animatronic = 2;

        timer = 0.0f;
        break;
        case 6:
        current_room_animatronic = 2;

        timer = 0.0f;
        break;
        case 7:
        if(tempRandom <= 25){
            if(tempRandom % 2 == 0){
                current_room_animatronic = 9;
            }
            else if(tempRandom % 2 != 0){
                current_room_animatronic = 8;
            }
        }
        else if(tempRandom > 25 && tempRandom <= 40)current_room_animatronic = 1;
        else if(tempRandom > 40){
            current_room_animatronic = 6;
        }

        timer = 0.0f;
        break;
        case 8:
        if(tempRandom <= 5)current_room_animatronic = 9;
        else if(tempRandom > 5 && tempRandom <= 70)current_room_animatronic = 7;
        else if (tempRandom > 70)current_room_animatronic = 1;

        timer = 0.0f;
        break;
        case 9:
        if(tempRandom <= 5)current_room_animatronic = 8;
        else if(tempRandom > 5 && tempRandom <= 70)current_room_animatronic = 4;
        else if (tempRandom > 70)current_room_animatronic = 1;

        timer = 0.0f;
        break;
                
        }
        cout << endl << tempRandom << " " << current_room_animatronic << endl;
    }
}
void Ixel::rendering(){
    if(current_room_animatronic == camera1.current_room){
    BeginShaderMode(shader);
        DrawTexturePro(animatronic[current_room_animatronic].texture, animatronic[current_room_animatronic].source, animatronic[current_room_animatronic].dest, animatronic[current_room_animatronic].origin, animatronic[current_room_animatronic].angle, animatronic[current_room_animatronic].col);
    EndShaderMode();
    }
    if(IsKeyPressed(KEY_H)){
        cout << "\nCR: " << camera1.current_room << "\n";
    }
}