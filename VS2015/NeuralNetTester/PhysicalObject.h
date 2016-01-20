#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H
#include "GUIDHolder.h"
#include "Vector2D.h"

class PhysicalObject : public virtual GUIDHolder
{
public:
    PhysicalObject(Vector2D pos, Vector2D dir, Vector2D vel, double objectMass, double frict, double colliderRadius);
    ~PhysicalObject();

    void AddForce(Vector2D newForce);
    void AddForceInDirection(double newtons);
    void Simulate(double dT);

protected:
    double mass;
    double frictionCoef;
    double radius;
    Vector2D direction;
    Vector2D position;
    Vector2D velocity;
    Vector2D force;
};

#endif // PHYSICALOBJECT_H
