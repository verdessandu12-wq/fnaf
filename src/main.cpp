#include "menu.hpp"
#include "gameplay.hpp"
#include "camera.hpp"
#include "sixam.hpp"
#include "screamer.hpp"
#include "pad.hpp"
#include "animatronics/Ixel.hpp"
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

int main() {
    scen currentScen = scen::menu;
    float w = 1280, h = 720;
    bool inCamera = false;
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(w, h, "FNaF");
    InitAudioDevice();

    Shader vignette = LoadShader(0, "../shader/vignete.fs");

    //CLASS OBJECTS
    gameplay game1;
    camera camera1;
    animPad pad;
    sixam sixamh;
    menu menu1;

    //CLASS ANIMATRONICS OBJECTS
    Ixel ixel1;
    //PlayMusicStream(game1.ambient);

    //IMPORT VARIABLES
    game1.import_variable();
    camera1.import_variable();
    pad.importVariable();
    sixamh.importVariable();   
    menu1.import_variable();
    ixel1.importVariable();

    //IMPORTANT VARIABLES
    menu1.renderMusic();
    Music ambient = LoadMusicStream("../song/ambient.mp3");

    PlayMusicStream(ambient);

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        //UpdateMusicStream(game1.ambient);
        pad.logic();

        static bool isHovered = false; 

        if (currentScen == scen::menu) {
            menu1.UpdateMusic();
            ixel1.logic();

            bool collision = CheckCollisionPointRec(GetMousePosition(), menu1.Play_Butt);

            if (collision) {
                if (isHovered == false) {
                    menu1.clickSound();
                    isHovered = true;
                }

                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentScen = scen::gameplay;
                }
            } else {
                isHovered = false; 
            }
        }

        if(IsKeyPressed(KEY_ESCAPE)){
            break;
        } 

        if (currentScen != scen::menu) {
            UpdateMusicStream(ambient);

            if(IsKeyPressed(KEY_C)){
                currentScen = scen::sixam;
            }
            if(IsKeyPressed(KEY_SPACE) && !pad.tap){
                inCamera = !inCamera;
                pad.tap = true;
            }
            if(inCamera && pad.num >= 3 && currentScen != scen::sixam && currentScen != scen::menu){
                currentScen = scen::camera;
            }
            if(!inCamera && currentScen != scen::sixam && currentScen != scen::menu){
            currentScen = scen::gameplay;
            }
        }
        
        if (currentScen == scen::gameplay){
        game1.move_camera();
        SetMusicVolume(ambient, 1.0f);
        }
        if (currentScen == scen::camera){
        camera1.switch_room();
        ixel1.rendering();
        SetMusicVolume(ambient, 0.5f);
        }
        if (currentScen == scen::sixam){
        sixamh.logic();
        }
        if(sixamh.globalTimer >= sixamh.final){
            currentScen == scen::sixam;
        }
    BeginDrawing();
            ClearBackground({0, 0, 0, 255});
            
            if (currentScen == scen::menu){
                menu1.rendering();
                if (CheckCollisionPointRec(GetMousePosition(), menu1.Play_Butt)) {
                    menu1.renderArrow();
                }
            }

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
    menu1.unload();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}