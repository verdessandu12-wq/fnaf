#include "camera.hpp"
#include "Ixel.hpp"
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
    //PlayMusicStream(game1.ambient);
    for (int i = 1; i < 11; i++){
        string cam = "../assets/camera/" + to_string(i) + "Camera.png";
        Texture2D cameraTemp = LoadTexture(cam.c_str());
        Rectangle sourceTemp = {0.0f, 0.0f, (float)cameraTemp.width, (float)cameraTemp.height};
        Rectangle destTemp = {0.0f, 0.0f, (float)w, (float)h};
        Vector2 originTemp = {0.0f, 0.0f};
        camera.emplace_back(cameraTemp, sourceTemp, destTemp, originTemp, 0.0f, WHITE);
    }
    //1
    button.push_back({926, 460, 60, 20});
    //2
    button.push_back({815, 496, 101, 93});
    //3
    button.push_back({827, 471, 74, 24});
    //4
    button.push_back({741, 504, 48, 62});
    //5
    button.push_back({776, 614, 26, 38});
    //6
    button.push_back({815, 655, 13, 7});
    //7
    button.push_back({906, 655, 10, 7});
    //8
    button.push_back({959, 610, 84, 63});
    //9
    button.push_back({970, 561, 65, 34});
    //10
    button.push_back({963, 492, 67, 32});
    shader = LoadShader(0, "../shader/first_shader.fs");
    if (!IsShaderValid(shader)){
        TraceLog(LOG_ERROR, "Critical invalid");
    }
}
void camera::switch_room(){
    //UpdateMusicStream(game1.ambient);
    //SetMusicVolume(game1.ambient, 0.5f);
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        //cout << GetMouseX() << " " << GetMouseY() << endl;

    }
     if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
    for(int i = 0; i < button.size(); i++){
        //DrawRectangleRec(button[i], WHITE);
        if(CheckCollisionRecs({(float)GetMouseX(), (float)GetMouseY(), 2, 3}, button[i])){
            //cout << "Ai apasat pe camera: " << i << endl;
            current_room = i;
        }
    }
}

}
void camera::rendering(){
    BeginShaderMode(shader);
    DrawTexturePro(camera[current_room].texture, camera[current_room].source, camera[current_room].dest, camera[current_room].origin, camera[current_room].angle, camera[current_room].col);
    EndShaderMode();
    DrawTextureEx(map, posMap, 0.0f, 0.4f, Fade(WHITE, 0.7f));
    DrawRectangleRec(button[current_room], WHITE);
    int cr = current_room + 1;
    string current_cam = to_string(cr);
    DrawText(current_cam.c_str(), button[current_room].x + button[current_room].width / 2 - 15 / 2, button[current_room].y + button[current_room].height / 2 - 15 / 2, 15, GREEN);
    
}