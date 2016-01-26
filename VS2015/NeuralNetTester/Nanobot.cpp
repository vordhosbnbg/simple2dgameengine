#include "Nanobot.h"
#include "MiningBeam.h"
#include "PlasmaBolt.h"
#include "ThermalBlast.h"


Nanobot::Nanobot() : 
    GameObject(
        Vector2D(0,0), // position
        Vector2D(0,0), // direction
        Vector2D(0,0), // velocity
        100, // mass
        0.1, // friction
        30, // collider radius
        ".\\res\\pictures\\blue_bot64.png", // texture
        false
        ), 
    is_moving(false),
    is_mining(false)
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
    if (is_mining)
    {
        beam->SetPosition(GetPosition() + GetDirection() * 70);
        beam->SetDirection(GetDirection());
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

void Nanobot::StartMining()
{
    beam = make_shared<MiningBeam>();
    beam->SetPosition(GetPosition() + GetDirection()*70);
    beam->SetDirection(GetDirection());

    registeredEngine->AddGameObject(beam);
    is_mining = true;
}

void Nanobot::StopMining()
{
    is_mining = false;
    registeredEngine->RemoveGameObject(beam);
}

void Nanobot::Shoot()
{
    shared_ptr<ThermalBlast> bolt = make_shared<ThermalBlast>();
    bolt->SetPosition(GetPosition() + GetDirection() * 40);
    bolt->SetDirection(GetDirection());
    bolt->SetVelocity(GetDirection() * 200);
    bolt->SetZoom(0.25);
    registeredEngine->AddGameObject(bolt);
}

