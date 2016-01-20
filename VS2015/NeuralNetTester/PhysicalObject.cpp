#include "PhysicalObject.h"



PhysicalObject::PhysicalObject(Vector2D pos, Vector2D dir, Vector2D vel, double objectMass, double frict) : position(pos), direction(dir), mass(objectMass), frictionCoef(frict)
{
}

PhysicalObject::~PhysicalObject()
{
}

void PhysicalObject::AddForce(Vector2D newForce)
{
    force += newForce;
}

void PhysicalObject::Simulate(double dT)
{
    force -= (force * frictionCoef); // calculate friction
    velocity += (force / mass) * dT; // calculate velocity
    position += velocity * dT; // calculate position
}
