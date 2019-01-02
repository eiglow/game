#ifndef _CAPP_H
#define _CAPP_H

#include <SDL.h>
#include <cmath>
#include <fstream>
#include <string>
#include <map>
#include <iostream>

class CApp
{
private:
    bool            Running;
    bool            Active;
    SDL_Window*     sdlWindow;
    SDL_Renderer*   sdlRenderer;

    float PlayerX    = 100;
    float PlayerY    = 300;
    float PlayerXvel = 0;
    float PlayerYvel = 0;

    bool Jumping   = false;
    bool MoveLeft  = false;
    bool MoveRight = false;
    bool OnGround  = false;

    float MoveSpeed = 1000;
    float MoveSpeedLimit = 500;
    float MoveFriction = 6;
    float JumpHeight = 300;
    float Gravity = 300;

    std::fstream SettingsFileStream;
    std::string SettingsFileName = "settings.cfg";
    // settings values will always be stored as strings, thus will need to be converted to appropriate types when used
    std::map<std::string, std::string> DefaultSettings =
    {
        {"ScreenWidth", "800"},
        {"ScreenHeight", "600"}
    };
    std::map<std::string, std::string> CurrentSettings;
    bool SettingsSave(void);
    bool SettingsInit(void);

public:
    CApp();
    int OnExecute(void);

    bool OnInit(void);
    void OnEvent(SDL_Event Event);
    void OnLoop(double deltaTime);
    void OnRender(double deltaTime);
    void OnCleanup(void);

};

#endif
