#include "Nanobot.h"
#include "MiningBeam.h"
#include "PlasmaBolt.h"
#include "ThermalBlast.h"
#include <iostream>

Nanobot::Nanobot() :
    GameObject(
        Vector2D(0, 0), // position
        Vector2D(0, 0), // direction
        Vector2D(0, 0), // velocity
        100, // mass
        0.1, // friction
        32, // collider radius
        ".\\res\\pictures\\blue_bot64.png", // texture
        true,
        true
        ),
    is_moving(false),
    is_mining(false),
    brain(make_shared<NaturalNN>()),
    health(2000),
    energy(500)
{
    AddTag(Tag::Nanobot_type);
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
    if(energy > 50)
    {
        energy -= 50;
        shared_ptr<ThermalBlast> blast = make_shared<ThermalBlast>();
        blast->SetPosition(GetPosition() + GetDirection() * 50);
        blast->SetDirection(GetDirection());
        blast->SetVelocity(GetDirection() * 200);
        blast->SetZoom(0.25);
        registeredEngine->AddGameObject(blast);
    }
}

void Nanobot::ReceiveDamage(double dmg)
{
    PrintDebug(string("Nanobot receives " + to_string(dmg) + " dmg.\n").c_str());
    PrintDebug((("Old health: ")+ to_string(health) + "\n").c_str());
    health -= dmg;
    PrintDebug((("New health: ") + to_string(health) + "\n").c_str());
    if (health <= 0)
    {
        PrintDebug("New health: \n");
        Die();
    }
}

