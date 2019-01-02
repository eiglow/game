#include "CApp.h"

void CApp::OnRender(double deltaTime)
{
    SDL_SetRenderDrawColor(sdlRenderer, 50, 60, 75, 255);
    SDL_RenderClear(sdlRenderer);

    SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
    SDL_Rect playerRect;
    playerRect.x = PlayerX;
    playerRect.y = 480-PlayerY;
    playerRect.w = 32;
    playerRect.h = 32;
    SDL_RenderDrawRect(sdlRenderer, &playerRect);

    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
    SDL_Rect groundRect;
    groundRect.x = 0;
    groundRect.y = 360;
    groundRect.w = 640;
    groundRect.h = 120;
    SDL_RenderFillRect(sdlRenderer, &groundRect);

    OnGround = SDL_HasIntersection(&playerRect, &groundRect);
}
