#include "PhysicalObject.h"



PhysicalObject::PhysicalObject(Vector2D pos, Vector2D dir, Vector2D vel, double objectMass, double frict, double colliderRadius, bool sleeping) : position(pos), direction(dir), mass(objectMass), frictionCoef(frict), radius(colliderRadius), directionChange(0), isSleeping(sleeping)
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
    if(velocity.Magnitude() > 1)
    {
        position += velocity * dT; // calculate position
    }
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

bool PhysicalObject::IsActive()
{
    return !isSleeping;
}

bool PhysicalObject::IsColliding(shared_ptr<PhysicalObject> obj)
{
    bool retVal = true;

    if (!isSleeping)
    {
        if (position.Distance(obj->position) > (radius + obj->radius))
        {
            retVal = false;
        }
    }

    return retVal;
}

bool PhysicalObject::IsMovingAwayFrom(shared_ptr<PhysicalObject> obj)
{
    bool retVal = position.Distance(obj->position) < (position + velocity).Distance(obj->position + obj->velocity);
    return retVal;
}

