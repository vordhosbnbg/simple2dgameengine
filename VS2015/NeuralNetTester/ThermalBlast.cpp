#include "ThermalBlast.h"



ThermalBlast::ThermalBlast() :
    GameObject(
        Vector2D(0, 0),
        Vector2D(0, 0),
        Vector2D(0, 0),
        0,
        0,
        3,
        ".\\res\\pictures\\shot_pow_12.png",
        false
        )
{
}


ThermalBlast::~ThermalBlast()
{
}

void ThermalBlast::Tick(double dT)
{

}