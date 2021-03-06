#include "PhysicalObject.h"



PhysicalObject::PhysicalObject(Vector2D pos, Vector2D dir, Vector2D vel, double objectMass, double frict, double colliderRadius, bool collidable, bool impulse) : position(pos), direction(dir), mass(objectMass), frictionCoef(frict), radius(colliderRadius), directionChange(0), isCollidable(collidable), hasImpulse(impulse)
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

void PhysicalObject::SetVelocity(Vector2D vel)
{
    velocity = vel;
}


void PhysicalObject::SimulateForces(double dT)
{
    if (mass > 0)
    {
        velocity += (force / mass) * dT; // calculate velocity
    }
    velocity *= (1 - frictionCoef * dT) ;
    direction = Vector2D::CreateVectorFromAngle(direction.GetAngle() + directionChange*dT);
    directionChange = 0;
    force = 0;
}

void PhysicalObject::MoveToNewPosition(double dT)
{
    if (velocity.Magnitude() > 1)
    {
        position += velocity * dT; // calculate position
    }
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

bool PhysicalObject::IsCollidable()
{
    return isCollidable;
}

bool PhysicalObject::HasImpulse()
{
    return hasImpulse;
}

bool PhysicalObject::IsColliding(shared_ptr<PhysicalObject> obj)
{
    bool retVal = false;

    if (position.Distance(obj->position) < (radius + obj->radius))
    {
        retVal = true;
    }
    return retVal;
}

bool PhysicalObject::IsMovingAwayFrom(shared_ptr<PhysicalObject> obj, double dT)
{
    bool retVal = position.Distance(obj->position) < (position + velocity * dT).Distance(obj->position + obj->velocity * dT);
    return retVal;
}

