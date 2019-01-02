#include "CApp.h"

void CApp::OnCleanup()
{
    SDL_DestroyRenderer(sdlRenderer);
    SDL_Quit();
    SettingsFileStream.close();
}
