#include "GameObject.h"



GameObject::GameObject(Vector2D & position, Vector2D & direction, Vector2D & velocity, double mass, double friction, string pathToTexture) : PhysicalObject(position, direction, velocity, mass, friction)
{
}

GameObject::~GameObject()
{
}

string GameObject::GetTexturePath()
{
    return texturePath;
}
