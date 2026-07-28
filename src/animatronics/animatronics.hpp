#ifndef ANIMATRONICS_HPP
#define ANIMATRONICS_HPP
#include <raylib.h>
#include "../sablonClass.hpp"
#include <vector>

using namespace std;

class animatronics{
    public:
    int current_room, random_room;
    float timer;
    vector<imgClass> animatronic;
    void importVariable();
    void rendering();
    void logic();
    void unload();
};

#endif