#include "menu.hpp"
#include "gameplay.hpp"
#include "camera.hpp"
#include "sixam.hpp"
#include "screamer.hpp"
#include "pad.hpp"
#include "raylib.h"
#include <iostream>

using namespace std;

enum class scen{
    menu,
    gameplay,
    camera,
    screamer,
    sixam,
    pad
};

int main(int argc, char *argv[]){
    scen currentScen = scen::gameplay;
    float w = 1280, h = 720;
    bool inCamera = false;
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(w, h, "FNaF");
    InitAudioDevice();
    gameplay game1;
    camera camera1;
    animPad pad;
    sixam sixamh;
    game1.import_variable();
    camera1.import_variable();
    pad.importVariable(); 
    sixamh.importVariable();
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        pad.logic();
        if(IsKeyPressed(KEY_ESCAPE)){
            break;
        }
        if(IsKeyPressed(KEY_C)){
            currentScen = scen::sixam;
        }
        if(IsKeyPressed(KEY_SPACE) && !pad.tap){
            inCamera = !inCamera;
            pad.tap = true;
        }
        if(inCamera && pad.num >= 3 && currentScen != scen::sixam){
            currentScen = scen::camera;
        }
        if(!inCamera && currentScen != scen::sixam){
            currentScen = scen::gameplay;
        }
        if (currentScen == scen::gameplay){
        game1.move_camera();
        }
        if (currentScen == scen::camera){
        camera1.switch_room();
        }
        if (currentScen == scen::sixam){
        sixamh.logic();
        }
        if(sixamh.globalTimer >= sixamh.final){
            currentScen == scen::sixam;
        }
    BeginDrawing();
            ClearBackground({0, 0, 0, 255});
            if (currentScen == scen::gameplay){
                game1.rendering();
            }
            if (currentScen == scen::camera){
                camera1.rendering();
            }
            if (currentScen != scen::sixam && currentScen != scen::screamer && currentScen != scen::menu){
                pad.startAnim();
            }
            if (currentScen == scen::sixam){
                sixamh.rendering();
            }
    EndDrawing();
    }
    //cout << game1.fx << "\n" << game1.fy << "\n" << game1.wf << "\n" << game1.hf;
    for(int i = 0; i < 46; i++){
    UnloadTexture(sixamh.sixamobj[i].texture);
    }
    CloseAudioDevice();
    CloseWindow();
    return 0;
}