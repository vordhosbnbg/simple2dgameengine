#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GSDrawable.h"
#include "PhysicalObject.h"

class GameObject : public GSDrawable, public PhysicalObject
{
public:
    GameObject();
    ~GameObject();
};

#endif // GAMEOBJECT_H
