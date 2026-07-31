#include "menu.hpp"

void menu::import_variable() {
    width = 1280.0f;
    height = 720.0f;
    background = LoadTexture("../assets/menu/Menu-fnaf.jpg");
    Play_Butt = {125, 350, 203, 33};
    continue_Butt = {125, 425, 204, 34};
    NGbut = LoadTexture("../assets/menu/fnaf_playButt.png");
    Cbut = LoadTexture("../assets/menu/449.png");
    backMusic = LoadMusicStream("../song/2017-youtube-background-music-low-quality.mp3");
    arrow = LoadTexture("../assets/menu/arrow.png");
    click = LoadSound("../song/button_off.mp3");
}

void menu::rendering() {
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(NGbut, 125, 350, WHITE);
    DrawTexture(Cbut, 125, 425, WHITE);
    DrawRectangleRec(Play_Butt, BLANK);
    DrawRectangleRec(continue_Butt, BLANK);

}

void menu::renderMusic() {
    PlayMusicStream(backMusic);
}

void menu::clickSound() {
    PlaySound(click);
}

void menu::renderArrow1() {
    DrawTexture(arrow, 75, 350, WHITE);
}

void menu::renderArrow2() {
    DrawTexture(arrow, 75, 425, WHITE);
}

void menu::UpdateMusic() {
    SetMusicVolume(backMusic, 0.1f);
    UpdateMusicStream(backMusic);
    
}

void menu::unload() {
    UnloadTexture(background);
    UnloadTexture(NGbut);
    UnloadTexture(Cbut);
    UnloadMusicStream(backMusic);
}