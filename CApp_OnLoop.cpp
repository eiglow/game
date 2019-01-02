#include "CApp.h"

void CApp::OnLoop(double deltaTime)
{
    // movement
    if (MoveRight)
        PlayerXvel += MoveSpeed*deltaTime;
    if (MoveLeft)
        PlayerXvel -= MoveSpeed*deltaTime;
    // friction
    PlayerXvel /= 1+MoveFriction*deltaTime;

    // speed limit
    if (PlayerXvel > MoveSpeedLimit)
        PlayerXvel = MoveSpeedLimit;
    if (PlayerXvel < 0-MoveSpeedLimit)
        PlayerXvel = 0-MoveSpeedLimit;

    // if speed is close to 0 and no movement keys are pressed, set it to 0
    if (!(MoveLeft || MoveRight) && (abs(PlayerXvel) < 1))
        PlayerXvel = 0;

    if (OnGround)
    {
        if (Jumping)
        {
            PlayerYvel = JumpHeight;
        }
        else
        {
            PlayerYvel = 0;
        }
    }
    else
    {
        PlayerYvel -= Gravity*deltaTime;
    }

    PlayerX += PlayerXvel*deltaTime;
    PlayerY += PlayerYvel*deltaTime;

    printf("%F, %F", PlayerXvel, PlayerYvel);
    if (OnGround)
        printf(", onGround");
    printf("\n");
}
