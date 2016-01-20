#include "Nanobot.h"



Nanobot::Nanobot() : GameObject(Vector2D(0,0), Vector2D(0,0), Vector2D(0,0), 100, 0.3, 32, ".\\res\\pictures\\nanobot64.png")
{
}


Nanobot::~Nanobot()
{
}

void Nanobot::Tick(double dT)
{
    AddForceInDirection(0.2);
}

