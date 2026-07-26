#ifndef MENU_HPP
#define MENU_HPP
#include "raylib.h"
class menu {
    public:
        float width, height;
        Texture2D background, button;
        Rectangle Play_Butt;
        Music backMusic;
        void import_variable();
        void rendering();  
        void renderMusic();
        bool logic();
        void UpdateMusic();
        void unload();
        ~menu(){
            UnloadTexture(background);
            UnloadTexture(button);
        }
};
#endif