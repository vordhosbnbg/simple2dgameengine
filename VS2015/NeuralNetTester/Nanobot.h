#ifndef NANOBOT_H
#define NANOBOT_H
#include "GameObject.h"

class Nanobot : public GameObject
{
public:
    Nanobot();
    ~Nanobot();

    void Tick(double dT) override;
    void StartMovement();
    void StopMovement();
private:
    bool is_moving;
};

#endif // NANOBOT_H
