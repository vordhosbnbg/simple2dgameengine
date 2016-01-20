#ifndef NANOBOT_H
#define NANOBOT_H
#include "GameObject.h"

class Nanobot : public GameObject
{
public:
    Nanobot();
    ~Nanobot();

    void Tick(double dT) override;
};

#endif // NANOBOT_H
