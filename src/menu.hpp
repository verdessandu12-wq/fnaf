#ifndef MENU_HPP
#define MENU_HPP
#include "raylib.h"

class menu {
public:
    float width, height;

    Texture2D background;
    Texture2D button;
    Texture2D arrow;

    Rectangle Play_Butt;
    Music backMusic;
    Sound click;

    void import_variable();
    void rendering();
    void renderMusic();
    void renderArrow();
    void UpdateMusic();
    void unload();
    void unloadArrow();
    void clickSound();

    ~menu() {
        UnloadTexture(background);
        UnloadTexture(button);
    }
};

#endif