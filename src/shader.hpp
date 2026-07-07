#ifndef SHADER_HPP
#define SHADER_HPP
#include "raylib.h"
class shaderClass{
    public:
    Shader firstShader;
    void init();
    void render();
    void cleanUp();
};
#endif