#ifndef PROPAGATOR_H
#define PROPAGATOR_H

#include <memory>
#include <mutex>
#include "Neuron.h"

using namespace std;
class Propagator
{
public:
    Propagator(shared_ptr<Connection> startConnection);
    ~Propagator();

    void DoJob(shared_ptr<Connection> startConnection);

private:
    mutex busy;
};

#endif //PROPAGATOR_H