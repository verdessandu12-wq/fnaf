#include "raylib.h"
#include "Ixel.hpp"
#include <vector>
#include <string>

using namespace std;

void Ixel::importVariable(){
    for(int i = 0; i < 1; i++){
        string tempTexture = "Ixel" + to_string(i);
        animatronic.emplace_back(tempTexture);
    }
    nightCoef = 1;
    current_room_animatronic = 3;
}
void Ixel::logic(){
    timer += GetFrameTime();
}
void Ixel::rendering(){
    if(current_room_animatronic == camera1.current_room){
        DrawTexturePro(animatronic[current_room_animatronic].texture, animatronic[current_room_animatronic].source, animatronic[current_room_animatronic].dest, animatronic[current_room_animatronic].origin, animatronic[current_room_animatronic].angle, animatronic[current_room_animatronic].col);
    }

}