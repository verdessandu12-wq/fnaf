#include "menu.hpp"

void menu::import_variable() {
    width = 1280.0f;
    height = 720.0f;
    background = LoadTexture("../assets/menu/Menu-fnaf.jpg");
    Play_Butt = {125, 350, 203, 33};
    button = LoadTexture("../assets/menu/fnaf_playButt.png");
    backMusic = LoadMusicStream("../song/fnaf_back_music.mp3");
    arrow = LoadTexture("../assets/menu/arrow.png");
}

void menu::rendering() {
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(button, 125, 350, WHITE);
    DrawRectangleRec(Play_Butt, BLANK);
}

void menu::renderMusic() {
    PlayMusicStream(backMusic);
}

void menu::renderArrow() {
    DrawTexture(arrow, 75, 350, WHITE);
}

void menu::UpdateMusic() {
    UpdateMusicStream(backMusic);
}

void menu::unload() {
    UnloadTexture(background);
    UnloadTexture(button);
    UnloadMusicStream(backMusic);
}