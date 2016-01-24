#include "GameObject.h"



GameObject::GameObject(Vector2D & position, Vector2D & direction, Vector2D & velocity, double mass, double friction, double colliderRadius, string pathToTexture, bool isSleeping) : PhysicalObject(position, direction, velocity, mass, friction, colliderRadius, isSleeping), texturePath(pathToTexture)
{
}

GameObject::~GameObject()
{
}

void GameObject::SetPosition(Vector2D pos)
{
    position = pos;
    SetRectPosition((int)(pos.X-GetRectWidth()/2), (int)(pos.Y-GetRectHeight()/2));
}

Vector2D GameObject::GetPosition()
{
    return position;
}

void GameObject::SetDirection(Vector2D dir)
{
    direction = dir;
    direction = direction.Normalize();
    SetDrawableRotation(dir.GetAngle());
}

Vector2D GameObject::GetDirection()
{
    return direction;
}

void GameObject::Update(double dT)
{
    Tick(dT);
    SetPosition(position);
    SetDrawableRotation(direction.GetAngle());
}

void GameObject::Tick(double dT)
{
}

void GameObject::RegisterWithEngine(GameEngine * eng)
{
    registeredEngine = eng;
    SetTexture(registeredEngine->GetTexture(texturePath));
}

string GameObject::GetTexturePath()
{
    return texturePath;
}
