#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H
#include "GUIDHolder.h"
#include "Vector2D.h"
#include "TagHolder.h"

class PhysicalObject : public virtual GUIDHolder, public virtual TagHolder
{
public:
    PhysicalObject(Vector2D pos, Vector2D dir, Vector2D vel, double objectMass, double frict, double colliderRadius, bool collidable, bool impulse);
    ~PhysicalObject();

    void ApplyForce(Vector2D newForce);
    void ApplyForceInDirection(double newtons);
    void ApplyRotation(double degreesPerSecond);
    void SetVelocity(Vector2D vel);

    void SimulateForces(double dT);
    void MoveToNewPosition(double dT);
    void AddImpulse(Vector2D &foreginImpulse);
    Vector2D RemoveImpulse();
    bool IsCollidable();
    bool HasImpulse();
    bool IsColliding(shared_ptr<PhysicalObject> obj);
    bool IsMovingAwayFrom(shared_ptr<PhysicalObject> obj, double dT);
    virtual void Collide(const shared_ptr<PhysicalObject> obj);
    Vector2D position;
    Vector2D velocity;
    double mass;

protected:
    bool isCollidable;
    bool hasImpulse;
    double frictionCoef;
    double radius;
    double directionChange;
    Vector2D direction;
    Vector2D force;
};

#endif // PHYSICALOBJECT_H
