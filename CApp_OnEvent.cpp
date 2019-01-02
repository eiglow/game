#include "CApp.h"

void CApp::OnEvent(SDL_Event Event)
{
    // only process 1 event at a time, since this gets called in a loop for each event
    switch (Event.type)
    {
    case SDL_QUIT:
        Active = false;
        return;
    case SDL_KEYDOWN:
        switch (Event.key.keysym.sym)
        {
        case SDLK_w:
            Jumping   = true;
            break;
        case SDLK_a:
            MoveLeft  = true;
            break;
        case SDLK_d:
            MoveRight = true;
            break;
        case SDLK_p:
            Running = !Running;
            break;
        }
        break;
    case SDL_KEYUP:
        switch (Event.key.keysym.sym)
        {
        case SDLK_w:
            Jumping   = false;
            break;
        case SDLK_a:
            MoveLeft  = false;
            break;
        case SDLK_d:
            MoveRight = false;
            break;
        }
        break;
    }

}
