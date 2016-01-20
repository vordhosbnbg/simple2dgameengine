#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GSDrawable.h"
#include "PhysicalObject.h"

class GameObject : public GSDrawable, public PhysicalObject
{
public:
    GameObject(Vector2D &position, Vector2D &direction, Vector2D &velocity, double mass, double friction, string pathToTexture);
    ~GameObject();

    string GetTexturePath();
private:
    string texturePath;

};

#endif // GAMEOBJECT_H
