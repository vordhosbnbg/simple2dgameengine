#include "Asteroid.h"



Asteroid::Asteroid() : 
    GameObject(
        Vector2D(0, 0), // position
        Vector2D(0, 0), // direction
        Vector2D(0, 0), // velocity
        1000, // mass
        0.1, // friction
        50, // collider radius
        ".\\res\\pictures\\asteroid_sq.png", // texture
        false
        )
{
}


Asteroid::~Asteroid()
{
}
