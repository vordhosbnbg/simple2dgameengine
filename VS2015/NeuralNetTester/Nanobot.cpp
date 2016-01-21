#include "Nanobot.h"



Nanobot::Nanobot() : 
    GameObject(
        Vector2D(0,0), // position
        Vector2D(0,0), // direction
        Vector2D(0,0), // velocity
        100, // mass
        0.1, // friction
        30, // collider radius
        ".\\res\\pictures\\blue_bot64.png" // texture
        ), 
    is_moving(false)
{
}


Nanobot::~Nanobot() 
{
}

void Nanobot::Tick(double dT)
{
    if (is_moving)
    {
        ApplyForceInDirection(1500);
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

