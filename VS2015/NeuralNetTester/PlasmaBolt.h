#ifndef PLASMABOLT_H
#define PLASMABOLT_H
#include "AnimatedGameObject.h"

class PlasmaBolt : public AnimatedGameObject
{
public:
    PlasmaBolt();
    ~PlasmaBolt();

    void Tick(double dT) override;
};

#endif // PLASMABOLT_H
