#ifndef THERMALBLAST_H
#define THERMALBLAST_H
#include "AnimatedGameObject.h"

class ThermalBlast : public GameObject
{
public:
    ThermalBlast();
    ~ThermalBlast();

    void Tick(double dT) override;
    void Collide(const shared_ptr<PhysicalObject> obj) override;

private:
    double damage_amount;
};

#endif // THERMALBLAST_H
