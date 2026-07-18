#ifndef ANIMATRONICS_HPP
#define ANIMATRONICS_HPP
#include "../sablonClass.hpp"
#include <vector>

using namespace std;

class animatronics{
    public:
    int current_room;
    vector<imgClass> animatronic;
    void importVariable();
    void rendering();
    void logic();
    void unload();
};

#endif