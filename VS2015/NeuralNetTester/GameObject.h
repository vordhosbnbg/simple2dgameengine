#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GSDrawable.h"
#include "PhysicalObject.h"

class GameObject : public GSDrawable, public PhysicalObject
{
public:
    GameObject(Vector2D &position, Vector2D &direction, Vector2D &velocity, double mass, double friction, double colliderRadius, string pathToTexture);
    ~GameObject();

    void SetPosition(Vector2D pos);
    Vector2D GetPosition();
    void SetDirection(Vector2D dir);
    Vector2D GetDirection();
    void Update(double dT);

    virtual void Tick(double dT);


    string GetTexturePath();
private:
    string texturePath;

};

#endif // GAMEOBJECT_H
