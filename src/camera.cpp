#include "camera.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void camera::import_variable(){
    current_room = 1;
    w = 1280.0f;
    h = 720.0f;
    map = LoadTexture("../assets/map.png");
    posMap = {w / 2 + 100, h / 2 + 100};
    for (int i = 1; i < 11; i++){
        string cam = "../assets/camera/" + to_string(i) + "Camera.png";
        Texture2D camera = LoadTexture(cam.c_str());
        Rectangle sourecTemp = {0.0f, 0.0f, 1280.0f, 720.0f};
        Rectangle destTemp = {0.0f, 0.0f, (float)w, (float)h};
        room.push_back(camera);
        source.push_back(sourecTemp);
        dest.push_back(destTemp);
    }
    //1
    button.push_back({926, 460, 60, 19});
    //2
    button.push_back({816, 496, 99, 90});
    //3
    button.push_back({827, 471, 73, 23});
    //4
    button.push_back({741, 504, 47, 58});
    //5
    button.push_back({776, 614, 25, 36});
    //6
    button.push_back({815, 655, 12, 6});
    //7
    button.push_back({906, 655, 9, 6});
    //8
    button.push_back({959, 610, 84, 62});
    //9
    button.push_back({971, 561, 63, 33});
    //10
    button.push_back({963, 492, 67, 31});
    shader = LoadShader(0, "../shader/first_shader.fs");
    if (!IsShaderValid(shader)){
        TraceLog(LOG_ERROR, "Critical invalid");
    }
}
void camera::switch_room(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        cout << GetMouseX() << " " << GetMouseY() << endl;

    }
     if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
    for(int i = 0; i < button.size(); i++){
        //DrawRectangleRec(button[i], WHITE);
        if(CheckCollisionRecs({(float)GetMouseX(), (float)GetMouseY(), 2, 3}, button[i])){
            cout << "Ai apasat pe camera: " << i << endl;
            current_room = i;
        }
    }
}

}
void camera::rendering(){
    BeginShaderMode(shader);
    DrawTexturePro(room[current_room], source[current_room], dest[current_room], {0.0f, 0.0f}, 0.0f, WHITE);
    EndShaderMode();
    DrawTextureEx(map, posMap, 0.0f, 0.4f, Fade(WHITE, 0.7f));
}