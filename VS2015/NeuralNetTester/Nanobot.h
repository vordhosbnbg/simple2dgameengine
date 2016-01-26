#ifndef NANOBOT_H
#define NANOBOT_H
#include "GameObject.h"
#include "MiningBeam.h"

class Nanobot : public GameObject
{
public:
    Nanobot();
    ~Nanobot();

    void Tick(double dT) override;
    void StartMovement();
    void StopMovement();
    void StartMining();
    void StopMining();
    void Shoot();
private:
    bool is_moving;
    bool is_mining;
    shared_ptr<MiningBeam> beam;
};

#endif // NANOBOT_H
