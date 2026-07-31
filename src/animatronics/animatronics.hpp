#ifndef ANIMATRONICS_HPP
#define ANIMATRONICS_HPP
#include <raylib.h>
#include "../sablonClass.hpp"
#include <vector>

using namespace std;

class animatronics{
    public:
    int current_room_animatronic, random_room;
    float timer, nightCoef;
    vector<imgClass> animatronic;
    virtual void importVariable() = 0;
    virtual void rendering() = 0;
    virtual void logic() = 0;
    ~animatronics(){
        for(int i = 0; i < animatronic.size(); i++){
            UnloadTexture(animatronic[i].texture);
        }
    }
};

#endif