#ifndef THERMALBLAST_H
#define THERMALBLAST_H
#include "AnimatedGameObject.h"

class ThermalBlast : public GameObject
{
public:
    ThermalBlast();
    ~ThermalBlast();

    void Tick(double dT) override;
};

#endif // THERMALBLAST_H
