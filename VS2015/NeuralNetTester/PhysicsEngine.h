#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include <vector>
#include <memory>
#include <mutex>
#include <queue>
#include "PhysicalObject.h"

using namespace std;
class PhysicsEngine
{
public:
    PhysicsEngine();
    ~PhysicsEngine();

    void AddPhysicalObject(shared_ptr<PhysicalObject> obj);
    void RemovePhysicalObject(shared_ptr<PhysicalObject> obj);
    void Simulate(double dT);
    int FindCollisions();
    void ResolveCollisions(double dT);
private:
    void RemovePhysicalObjectsFromList();
    vector<pair<shared_ptr<PhysicalObject>, shared_ptr<PhysicalObject>>> ListOfPairsThatCollide;
    vector<shared_ptr<PhysicalObject>> ListOfPhysicalObjects;
    mutex ListOfPhysicalObjects_mutex;
    queue<shared_ptr<PhysicalObject>> ListOfPhysicalObjectsToRemove;
    mutex ListOfPhysicalObjectsToRemove_mutex;
};

#endif // PHYSICSENGINE_H
