#include "raylib.h"
#include "shader.hpp"

void shaderClass::init(){
    firstShader = LoadShader(nullptr, "../shader/first_shader.fs");
}
void shaderClass::render(){

}
void shaderClass::cleanUp(){
    UnloadShader(firstShader);
}