#include "PhysicalObject.h"



PhysicalObject::PhysicalObject(Vector2D pos, Vector2D dir, Vector2D vel, double objectMass, double frict, double colliderRadius) : position(pos), direction(dir), mass(objectMass), frictionCoef(frict), radius(colliderRadius)
{
}

PhysicalObject::~PhysicalObject()
{
}

void PhysicalObject::ApplyForce(Vector2D newForce)
{
    force += newForce;
}

void PhysicalObject::ApplyForceInDirection(double newtons)
{
    force += direction * newtons;
}

void PhysicalObject::ApplyRotation(double degreesPerSecond)
{
    directionChange += degreesPerSecond;
}


void PhysicalObject::Simulate(double dT)
{
    velocity += (force / mass) * dT; // calculate velocity
    //velocity -= (velocity * frictionCoef * dT);
    position += velocity * dT; // calculate position
    direction += Vector2D::CreateVectorFromAngle(directionChange);
    force = 0;
}
