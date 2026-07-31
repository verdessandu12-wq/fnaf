#ifndef MENU_HPP
#define MENU_HPP
#include "raylib.h"

class menu {
public:
    float width, height;

    Texture2D background;
    Texture2D NGbut;
    Texture2D arrow;
    Texture2D Cbut;

    Rectangle Play_Butt;
    Rectangle continue_Butt;
    Music backMusic;
    Sound click;

    void import_variable();
    void rendering();
    void renderMusic();
    void renderArrow1();
    void renderArrow2();
    void UpdateMusic();
    void unload();
    void unloadArrow();
    void clickSound();

    ~menu() {
        UnloadTexture(background);
        UnloadTexture(NGbut);
        UnloadTexture(Cbut);
    }
};

#endif