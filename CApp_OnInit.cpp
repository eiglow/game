#include "CApp.h"

bool CApp::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL_Init failed!" << std::endl;
        return false;
    }

    if (!CApp::SettingsInit())
    {
        std::cout << "Settings init failed!" << std::endl;
        return false;
    }

    if ((sdlWindow = SDL_CreateWindow(
                         "Epic game",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         std::stoi(CurrentSettings["ScreenWidth"]),
                         std::stoi(CurrentSettings["ScreenHeight"]),
                         0
                     )) == NULL)
    {
        std::cout << "Window creation failed!" << std::endl;
        return false;
    }

    if ((sdlRenderer = SDL_CreateRenderer(
                           sdlWindow,
                           -1,
                           SDL_RENDERER_ACCELERATED
                       )) == NULL)
    {
        std::cout << "Renderer creation failed!" << std::endl;
        return false;
    }

    Running = true;

    return true;
}
