#include "MiningBeam.h"



MiningBeam::MiningBeam() : 
    AnimatedGameObject(
        Vector2D(0,0),
        Vector2D(0,0),
        Vector2D(0,0),
        0,
        0,
        0,
        ".\\res\\pictures\\beam_anim.png",
        false,
        false,
        6,
        (1.0/5),
        AnimType::StartToEnd,
        true
        )
{
}


MiningBeam::~MiningBeam()
{
}
