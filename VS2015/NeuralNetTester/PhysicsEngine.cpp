#include "PhysicsEngine.h"
#include <iostream>


PhysicsEngine::PhysicsEngine()
{
}


PhysicsEngine::~PhysicsEngine()
{
}

void PhysicsEngine::AddPhysicalObject(shared_ptr<PhysicalObject> obj)
{
    lock_guard<mutex> lock(ListOfPhysicalObjects_mutex);
    ListOfPhysicalObjects.push_back(obj);
}

void PhysicsEngine::RemovePhysicalObject(shared_ptr<PhysicalObject> obj)
{
    lock_guard<mutex> lock(ListOfPhysicalObjectsToRemove_mutex);
    ListOfPhysicalObjectsToRemove.push(obj);
}


void PhysicsEngine::Simulate(double dT)
{
    lock_guard<mutex> lock(ListOfPhysicalObjects_mutex);
    for (auto iterPobj = ListOfPhysicalObjects.begin(); iterPobj != ListOfPhysicalObjects.end(); ++iterPobj)
    {
        (*iterPobj)->SimulateForces(dT);
    }
    FindCollisions();
    ResolveCollisions(dT);
    RemovePhysicalObjectsFromList();
    for (auto iterPobj = ListOfPhysicalObjects.begin(); iterPobj != ListOfPhysicalObjects.end(); ++iterPobj)
    {
        (*iterPobj)->MoveToNewPosition(dT);
    }
}

int PhysicsEngine::FindCollisions()
{
    int retVal = 0;
    for (auto iterObj1 = ListOfPhysicalObjects.begin(); iterObj1 != ListOfPhysicalObjects.end(); ++iterObj1)
    {
        if ((*iterObj1)->IsCollidable())
        {
            for (auto iterObj2 = next(iterObj1); iterObj2 != ListOfPhysicalObjects.end(); ++iterObj2)
            {
                if ((*iterObj2)->IsCollidable())
                {
                    if ((*iterObj1)->IsColliding((*iterObj2)))
                    {
                        ListOfPairsThatCollide.push_back(make_pair((*iterObj1), (*iterObj2)));
                    }
                }
            }
        }
    }
    retVal = ListOfPairsThatCollide.size();
    if (retVal > 0)
    {
        PrintDebug(("Found " + to_string(retVal) + " collisions.\n").c_str());
    }
    return retVal;
}

void PhysicsEngine::ResolveCollisions(double dT)
{
    for (auto iterCollidePair = ListOfPairsThatCollide.begin(); iterCollidePair != ListOfPairsThatCollide.end(); ++iterCollidePair) 
    {
        PrintDebug(("Resolving collision between GUID: " + to_string(iterCollidePair->first->guid) + " and GUID:" + to_string(iterCollidePair->second->guid) + "\n").c_str());
        if (iterCollidePair->first->HasImpulse() && iterCollidePair->second->HasImpulse())
        {
            if (!iterCollidePair->first->IsMovingAwayFrom(iterCollidePair->second, dT))
            {
                PrintDebug("Objects are colliding and moving towards eachother.\n");
                PrintDebug((string("Positions: First(") + to_string(iterCollidePair->first->position.X) + "," + to_string(iterCollidePair->first->position.Y) + "); Second(" + to_string(iterCollidePair->second->position.X) + "," + to_string(iterCollidePair->second->position.Y) + ")\n").c_str());
                PrintDebug((string("Old Velocities: First(") + to_string(iterCollidePair->first->velocity.X) + "," + to_string(iterCollidePair->first->velocity.Y) + "); Second(" + to_string(iterCollidePair->second->velocity.X) + "," + to_string(iterCollidePair->second->velocity.Y) + ")\n").c_str());
                Vector2D firstVel = iterCollidePair->first->velocity;
                Vector2D secondVel = iterCollidePair->second->velocity;
                double firstMass = iterCollidePair->first->mass;
                double secondMass = iterCollidePair->second->mass;
                iterCollidePair->first->velocity = (firstVel * (firstMass - secondMass) + (secondVel * secondMass * 2)) / (firstMass + secondMass);
                iterCollidePair->second->velocity = (secondVel * (secondMass - firstMass) + (firstVel * firstMass * 2)) / (firstMass + secondMass);
                //Vector2D impulseFirst = iterCollidePair->first->RemoveImpulse();
                //Vector2D impulseSecond = iterCollidePair->second->RemoveImpulse();
                //iterCollidePair->first->AddImpulse(impulseSecond);
                //iterCollidePair->second->AddImpulse(impulseFirst);
                PrintDebug((string("New Velocities: First(") + to_string(iterCollidePair->first->velocity.X) + "," + to_string(iterCollidePair->first->velocity.Y) + "); Second(" + to_string(iterCollidePair->second->velocity.X) + "," + to_string(iterCollidePair->second->velocity.Y) + ")\n").c_str());
            }
        }
        iterCollidePair->first->Collide(iterCollidePair->second);
        iterCollidePair->second->Collide(iterCollidePair->first);
    }
    ListOfPairsThatCollide.clear();
}

void PhysicsEngine::RemovePhysicalObjectsFromList()
{
    lock_guard<mutex> lock1(ListOfPhysicalObjectsToRemove_mutex);
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
