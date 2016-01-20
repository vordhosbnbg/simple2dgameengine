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
