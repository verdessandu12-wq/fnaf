#include "menu.hpp"

void menu::import_variable() {
    width = 1280.0f;
    height = 720.0f;
    background = LoadTexture("../assets/menu/Menu-fnaf.jpg");
    Play_Butt = {125, 350, 203, 33};
    button = LoadTexture("../assets/menu/fnaf_playButt.png");
    backMusic = LoadMusicStream("../song/2017-youtube-background-music-low-quality.mp3");
    arrow = LoadTexture("../assets/menu/arrow.png");
    click = LoadSound("../song/button_off.mp3");

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
    DrawTexture(button, 125, 350, WHITE);
    DrawRectangleRec(Play_Butt, BLANK);
}

void menu::renderMusic() {
    PlayMusicStream(backMusic);
}

void menu::clickSound() {
    PlaySound(click);
}

void menu::renderArrow() {
    DrawTexture(arrow, 75, 350, WHITE);
}

void menu::UpdateMusic() {
    SetMusicVolume(backMusic, 0.1f);
    UpdateMusicStream(backMusic);
    
}

void menu::unload() {
    UnloadTexture(background);
    UnloadTexture(button);
    UnloadMusicStream(backMusic);
}