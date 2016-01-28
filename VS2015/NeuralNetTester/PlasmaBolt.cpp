#include "PlasmaBolt.h"



PlasmaBolt::PlasmaBolt() :
AnimatedGameObject(
    Vector2D(0, 0),
    Vector2D(0, 0),
    Vector2D(0, 0),
    0,
    0,
    8,
    ".\\res\\pictures\\plasma_bolt_anim_11f.png",
    true,
    false,
    11,
    (1.0 / 5),
    AnimType::StartToEnd,
    false
    )
{
}


PlasmaBolt::~PlasmaBolt()
{
}

void PlasmaBolt::Tick(double dT)
{
    
}
