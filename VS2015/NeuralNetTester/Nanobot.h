#ifndef NANOBOT_H
#define NANOBOT_H
#include "GameObject.h"
#include "MiningBeam.h"
#include "NaturalNN.h"
#include "TagHolder.h"

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
    void ReceiveDamage(double dmg);

private:
    bool is_moving;
    bool is_mining;
    shared_ptr<MiningBeam> beam;
    shared_ptr<NaturalNN> brain;

    double health;
    double energy;
};

#endif // NANOBOT_H
