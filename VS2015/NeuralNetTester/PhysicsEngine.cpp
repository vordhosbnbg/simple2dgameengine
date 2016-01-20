#include "PhysicsEngine.h"



PhysicsEngine::PhysicsEngine()
{
}


PhysicsEngine::~PhysicsEngine()
{
}

void PhysicsEngine::AddPhysicalObject(shared_ptr<PhysicalObject> obj)
{
    ListOfPhysicalObjects.push_back(obj);
}

void PhysicsEngine::Simulate(double dT)
{

}
