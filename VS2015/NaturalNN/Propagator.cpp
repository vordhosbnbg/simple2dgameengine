#include <thread>
#include "Propagator.h"



Propagator::Propagator(shared_ptr<Connection> startConnection)
{
    // start propagation in separate thread
    thread t(&Propagator::DoJob, this, startConnection);
}


Propagator::~Propagator()
{
    // wait with the destruction until job is done
    lock_guard<mutex> lock(busy);
}

void Propagator::DoJob(shared_ptr<Connection> startConnection)
{
    // if the destructor is already called we should exit immediately (and possibly indicate error)
    if (busy.try_lock())
    {
        // here we do propagation
        shared_ptr<Connection> currentConnection = startConnection;
        while ((*currentConnection).isOutput != true) 
        {
            (*currentConnection).ProcessSignal();
            (*currentConnection).SetProcessed(true);
        }
        

        busy.unlock();
    }
}

