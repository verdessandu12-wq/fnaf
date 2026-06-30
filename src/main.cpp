#include "menu.hpp"
#include "gameplay.hpp"
#include "camera.hpp"
#include "sixam.hpp"
#include "screamer.hpp"
#include "raylib.h"

using namespace std;

int main(int argc, char *argv[]){
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
        game1.move_camera();
    BeginDrawing();
            ClearBackground({0, 0, 0, 255});
            game1.rendering();
    EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();
    return 0;
}