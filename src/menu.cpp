#include "menu.hpp"

void menu::import_variable() {
    width = 1280.0f;
    height = 720.0f;
    background = LoadTexture("../assets/menu/Menu-fnaf.jpg");
    Play_Butt = {60, 300, 203, 33};
    button = LoadTexture("../assets/menu/fnaf_playButt.png");
    backMusic = LoadMusicStream("../song/fnaf_back_music.mp3");
}

bool menu::logic() {
    if(CheckCollisionPointRec(GetMousePosition(), Play_Butt)) {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            return true;
        }
    }
    else {
        return false;
    }
}

void menu::rendering() {
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(button, 60, 300, WHITE);
    DrawRectangleRec(Play_Butt, BLANK);
}

void menu::renderMusic() {
    PlayMusicStream(backMusic);
}

void menu::UpdateMusic() {
    UpdateMusicStream(backMusic);
}

void menu::unload() {
    UnloadTexture(background);
    UnloadTexture(button);
    UnloadMusicStream(backMusic);
}