#include <thread>
#include "Propagator.h"



Propagator::Propagator(shared_ptr<Neuron> startNeuron)
{
    // start propagation in separate thread
    thread t(&Propagator::DoJob, this, startNeuron);
}


Propagator::~Propagator()
{
    // wait until job is done
    lock_guard<mutex> lock(busy);

}

void Propagator::DoJob(shared_ptr<Neuron> startNeuron)
{
    // if the destructor is already called we should exit immediately (and possibly indicate error)
    if (busy.try_lock())
    {
        // here we do propagation
        busy.unlock();
    }
}

