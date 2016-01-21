#include "Nanobot.h"



Nanobot::Nanobot() : GameObject(Vector2D(0,0), Vector2D(0,0), Vector2D(0,0), 100, 0.3, 32, ".\\res\\pictures\\nanobot64.png"), is_moving(false)
{
}


Nanobot::~Nanobot() 
{
}

void Nanobot::Tick(double dT)
{
    if (is_moving)
    {
        ApplyForceInDirection(0.2);
        ApplyRotation(10);
    }
}

void Nanobot::StartMovement()
{
    is_moving = true;
}

void Nanobot::StopMovement()
{
    is_moving = false;
}

