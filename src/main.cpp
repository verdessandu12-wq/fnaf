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
    //Здравствуйте! Если вы хотите протестировать код в файле menu.cpp, просто замените scene::gameplay на scene::menu (для Demian).
    scen currentScen = scen::gameplay;
    float w = GetScreenWidth(), h = GetScreenHeight();
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(w, h, "FNaF");
    InitAudioDevice();
    gameplay game1;
    game1.import_variable();
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_ESCAPE)){
            break;
        }
        if (currentScen == scen::gameplay){
        game1.move_camera();
        }
    BeginDrawing();
            ClearBackground({0, 0, 0, 255});
            if (currentScen == scen::gameplay){
            game1.rendering();
            }
    EndDrawing();
    }
    cout << game1.fx << "\n" << game1.fy << "\n" << game1.wf << "\n" << game1.hf;
    CloseAudioDevice();
    CloseWindow();
    return 0;
}