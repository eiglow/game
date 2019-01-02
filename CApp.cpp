#include "CApp.h"

CApp::CApp() {}

int CApp::OnExecute()
{
    if (OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    Running = false, Active = true;
    while (Active)
    {
        while (SDL_PollEvent(&Event))
        {
            OnEvent(Event);
        }

        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() ) / 1000;

        if (Running)
        {
            OnLoop(deltaTime);
            if (!Active) break;
        }
        OnRender(deltaTime);
        SDL_RenderPresent(sdlRenderer);
    }

    OnCleanup();

    return 0;
}

int main()
{
    CApp theApp;
    return theApp.OnExecute();
}
