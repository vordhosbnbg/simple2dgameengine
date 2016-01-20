#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H
#include "GUIDHolder.h"
#include "Vector2D.h"

class PhysicalObject : public GUIDHolder
{
public:
    PhysicalObject(Vector2D pos, Vector2D dir, Vector2D vel, double objectMass, double frict);
    ~PhysicalObject();

    void AddForce(Vector2D newForce);
    void Simulate(double dT);

private:
    double mass;
    double frictionCoef;
    Vector2D direction;
    Vector2D position;
    Vector2D velocity;
    Vector2D force;
};

#endif // PHYSICALOBJECT_H
