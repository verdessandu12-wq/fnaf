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
    posMap = {w / 2 + 100, h / 2};
    //PlayMusicStream(game1.ambient);
    for (int i = 1; i < 11; i++){
        //Color colorTemp = 
        string cam = "../assets/camera/" + to_string(i) + "Camera.png";
        Texture2D cameraTemp = LoadTexture(cam.c_str());
        Rectangle sourceTemp = {0.0f, 0.0f, (float)cameraTemp.width, (float)cameraTemp.height};
        Rectangle destTemp = {0.0f, 0.0f, (float)w, (float)h};
        Vector2 originTemp = {0.0f, 0.0f};
        cameraVec.emplace_back(cameraTemp, sourceTemp, destTemp, originTemp, 0.0f, WHITE);
        //camera.emplace_back(cameraTemp, sourceTemp, destTemp, originTemp, 0.0f, GRAY);
    }
    //1
    button.push_back({1059 ,375, 40, 25});
    //2
    button.push_back({880 ,534, 40, 25});
    //3
    button.push_back({871 ,376, 40, 25});
    //4
    button.push_back({785, 497,40, 25});
    //5
    button.push_back({791, 592, 40, 25});
    //6
    button.push_back({854, 653, 40, 25});
    //7
    button.push_back({987, 653, 40, 25});
    //8
    button.push_back({1074, 588, 40, 25});
    //9
    button.push_back({1077, 434, 40, 25});
    //10
    button.push_back({1085 ,512, 40, 25});

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
        Vector2 mousePosTemp = GetMousePosition();
       if(CheckCollisionPointRec(mousePosTemp, button[i]))
            //cout << "Ai apasat pe camera: " << i << endl;
            current_room = i;
        
    }
}

}
void camera::rendering(){
    BeginShaderMode(shader);
    DrawTexturePro(cameraVec[current_room].texture, cameraVec[current_room].source, cameraVec[current_room].dest, cameraVec[current_room].origin, cameraVec[current_room].angle, cameraVec[current_room].col);
    EndShaderMode();
    //DrawTextureEx(map, posMap, 0.0f, 0.4f, Fade(WHITE, 0.7f));
    DrawRectangleRec(button[current_room], WHITE);
    int cr = current_room + 1;
    string current_cam = to_string(cr);
    DrawText(current_cam.c_str(), button[current_room].x + button[current_room].width / 2 - 15.0f / 2, button[current_room].y + button[current_room].height / 2 - 15.0f / 2, 15, GREEN);
    DrawTextureEx(map, posMap, 0.0f, 0.6f, Fade(WHITE,0.4f));
    for(int i = 0; i < button.size(); i++){
        int tempCR = i + 1;
            DrawRectangleRec(button[i], {145, 145, 145, 255});
            string current_cam = "CAM\n" + to_string(tempCR);
    DrawText(current_cam.c_str(), button[i].x + button[i].width / 2 - 10, button[i].y + button[i].height / 2 - 10, 10, GREEN);
    }
}