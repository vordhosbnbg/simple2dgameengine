#include "PhysicalObject.h"



PhysicalObject::PhysicalObject(Vector2D pos, Vector2D dir, Vector2D vel, double objectMass, double frict, double colliderRadius) : position(pos), direction(dir), mass(objectMass), frictionCoef(frict), radius(colliderRadius), directionChange(0)
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
    velocity *= (1 - frictionCoef * dT) ;
    position += velocity * dT; // calculate position
    direction = Vector2D::CreateVectorFromAngle(direction.GetAngle() + directionChange*dT);
    directionChange = 0;
    force = 0;
}

void PhysicalObject::Collide(shared_ptr<PhysicalObject> obj)
{

}

void PhysicalObject::AddImpulse(Vector2D & foreginImpulse)
{
    velocity += foreginImpulse / mass;
}

Vector2D PhysicalObject::RemoveImpulse()
{
    Vector2D retVal = velocity * mass;
    velocity = 0;
    return retVal;
}

bool PhysicalObject::IsColliding(shared_ptr<PhysicalObject> obj)
{
    bool retVal = true;

    if (position.Distance(obj->position) > (radius + obj->radius)) 
    {
        retVal = false;
    }

    return retVal;
}

