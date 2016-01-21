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

void PhysicsEngine::RemovePhysicalObject(shared_ptr<PhysicalObject> obj)
{
    lock_guard<mutex> lock(ListOfPhysicalObjectsToRemove_mutex);
    ListOfPhysicalObjectsToRemove.push(obj);
}


void PhysicsEngine::Simulate(double dT)
{
    for (auto iterPobj = ListOfPhysicalObjects.begin(); iterPobj != ListOfPhysicalObjects.end(); ++iterPobj) 
    {
        (*iterPobj)->Simulate(dT);
    }
    FindCollisions();
    ResolveCollisions();
}

int PhysicsEngine::FindCollisions()
{
    int retVal = 0;
    for (auto iterObj1 = ListOfPhysicalObjects.begin(); iterObj1 != ListOfPhysicalObjects.end(); ++iterObj1)
    {
        for (auto iterObj2 = next(iterObj1); iterObj2 != ListOfPhysicalObjects.end(); ++iterObj2) 
        {
            if ((*iterObj1)->IsColliding((*iterObj2))) 
            {
                ListOfPairsThatCollide.push_back(make_pair((*iterObj1), (*iterObj2)));
            }
        }
    }
    return retVal;
}

void PhysicsEngine::ResolveCollisions()
{
    for (auto iterCollidePair = ListOfPairsThatCollide.begin(); iterCollidePair != ListOfPairsThatCollide.end(); ++iterCollidePair) 
    {
        Vector2D impulseFirst = iterCollidePair->first->RemoveImpulse();
        Vector2D impulseSecond = iterCollidePair->second->RemoveImpulse();
        iterCollidePair->first->AddImpulse(impulseSecond);
        iterCollidePair->second->AddImpulse(impulseFirst);
    }
    ListOfPairsThatCollide.clear();
}

void PhysicsEngine::RemovePhysicalObjectsFromList()
{
    lock_guard<mutex> lock(ListOfPhysicalObjectsToRemove_mutex);
    while (!ListOfPhysicalObjectsToRemove.empty())
    {
        auto DrawableToRemove = ListOfPhysicalObjectsToRemove.front();
        ListOfPhysicalObjectsToRemove.pop(); // we remove the drawable from this list always

        for (auto iterPhysObj = ListOfPhysicalObjects.begin(); iterPhysObj != ListOfPhysicalObjects.end(); ++iterPhysObj)
        {
            // if we find it in the physical object list we remove it from there
            if ((*iterPhysObj)->CompareWithObject((*DrawableToRemove)))
            {
                ListOfPhysicalObjects.erase(iterPhysObj);
                break;
            }
        }
    }

}
