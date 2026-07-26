#ifndef MENU_HPP
#define MENU_HPP
#include "raylib.h"
class menu {
    public:
        float width, height;
<<<<<<< HEAD
        Texture2D background;
        Texture2D button;
        Texture2D arrow;
=======
        Texture2D background, button;
>>>>>>> 53b073fa4bd0c2aac3315bb30189a0024771da83
        Rectangle Play_Butt;
        Music backMusic;
        void import_variable();
        void rendering();  
        void renderMusic();
        void renderArrow();
        bool logic();
        void UpdateMusic();
        void unload();
<<<<<<< HEAD
        void unloadArrow();
=======
        ~menu(){
            UnloadTexture(background);
            UnloadTexture(button);
        }
>>>>>>> 53b073fa4bd0c2aac3315bb30189a0024771da83
};
#endif