#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include <vector>
#include <memory>
#include "PhysicalObject.h"

using namespace std;
class PhysicsEngine
{
public:
    PhysicsEngine();
    ~PhysicsEngine();

    void AddPhysicalObject(shared_ptr<PhysicalObject> obj);
    void Simulate(double dT);
private:
    vector<shared_ptr<PhysicalObject>> ListOfPhysicalObjects;
};

#endif // PHYSICSENGINE_H
