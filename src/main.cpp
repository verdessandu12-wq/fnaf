#include "menu.hpp"
#include "gameplay.hpp"
#include "camera.hpp"
#include "sixam.hpp"
#include "screamer.hpp"
#include "raylib.h"
#include <iostream>

using namespace std;

enum class scen{
    menu,
    gameplay,
    camera,
    screamer,
    sixam
};

int main(int argc, char *argv[]){
    scen currentScen = scen::camera;
    float w = 1280, h = 720;
    bool inCamera = false;
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(w, h, "FNaF");
    InitAudioDevice();
    gameplay game1;
    camera camera1;
    game1.import_variable();
    camera1.import_variable();
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_ESCAPE)){
            break;
        }
        if(IsKeyPressed(KEY_SPACE)){
            inCamera = !inCamera;
        }
        if(inCamera){
            currentScen = scen::camera;
        }
        if(!inCamera){
            currentScen = scen::gameplay;
        }
        if (currentScen == scen::gameplay){
        game1.move_camera();
        }
        if (currentScen == scen::camera){
        camera1.switch_room();
        }
    BeginDrawing();
            ClearBackground({0, 0, 0, 255});
            if (currentScen == scen::gameplay){
            game1.rendering();
            }
            if (currentScen == scen::camera){
            camera1.rendering();
            }
            
    EndDrawing();
    }
    cout << game1.fx << "\n" << game1.fy << "\n" << game1.wf << "\n" << game1.hf;
    CloseAudioDevice();
    CloseWindow();
    return 0;
}