#include "GameObject.h"



GameObject::GameObject(Vector2D & position, Vector2D & direction, Vector2D & velocity, double mass, double friction, double colliderRadius, string pathToTexture, bool isCollidable, bool hasImpulse) : PhysicalObject(position, direction, velocity, mass, friction, colliderRadius, isCollidable, hasImpulse), texturePath(pathToTexture)
{
}

GameObject::~GameObject()
{
}

void GameObject::SetPosition(Vector2D pos)
{
    position = pos;
    dstRect->SetRectPosition((pos.X - (srcRect->GetRectWidth() * zoomLevel)/2), (pos.Y - (srcRect->GetRectHeight() * zoomLevel)/2));
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

void GameObject::Die()
{
    registeredEngine->RemoveGameObject(shared_from_this());
}
