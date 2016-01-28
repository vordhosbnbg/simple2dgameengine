#include "ThermalBlast.h"
#include "Nanobot.h"
#include <iostream>

ThermalBlast::ThermalBlast() :
    GameObject(
        Vector2D(0, 0),
        Vector2D(0, 0),
        Vector2D(0, 0),
        0,
        0,
        3,
        ".\\res\\pictures\\shot_pow_12.png",
        true,
        false
        ),
    damage_amount(50)
{
}


ThermalBlast::~ThermalBlast()
{
}

void ThermalBlast::Tick(double dT)
{

}

void ThermalBlast::Collide(const shared_ptr<PhysicalObject> obj)
{
    if (obj->HasTag(Tag::Nanobot_type))
    {
        auto bot = static_pointer_cast<Nanobot, PhysicalObject>(obj);
        PrintDebug("Thermal blast hits!\n");
        PrintDebug("ThermalBlast GUID:");
        PrintDebug(to_string(this->guid).c_str());
        PrintDebug((string("\nBlast(") + to_string(this->position.X) + "," + to_string(this->position.Y) + "); Nanobot(" + to_string(obj->position.X) + "," + to_string(obj->position.Y) + ")\n").c_str());
        bot->ReceiveDamage(damage_amount);
    }
    
    Die();
}
