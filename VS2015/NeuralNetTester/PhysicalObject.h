#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H
#include "GUIDHolder.h"
#include "Vector2D.h"

class PhysicalObject : public virtual GUIDHolder
{
public:
    PhysicalObject(Vector2D pos, Vector2D dir, Vector2D vel, double objectMass, double frict, double colliderRadius);
    ~PhysicalObject();

    void ApplyForce(Vector2D newForce);
    void ApplyForceInDirection(double newtons);
    void ApplyRotation(double degreesPerSecond);

    void Simulate(double dT);
    void AddImpulse(Vector2D &foreginImpulse);
    Vector2D RemoveImpulse();
    bool IsColliding(shared_ptr<PhysicalObject> obj);
protected:
    virtual void Collide(shared_ptr<PhysicalObject> obj);
    double mass;
    double frictionCoef;
    double radius;
    double directionChange;
    Vector2D direction;
    Vector2D position;
    Vector2D velocity;
    Vector2D force;
};

#endif // PHYSICALOBJECT_H
