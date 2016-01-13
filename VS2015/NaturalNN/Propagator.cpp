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
        // here we do propagation until we get to output connection
        shared_ptr<Connection> currentConnection = startConnection;
        shared_ptr<Connection> tempConnection;
        shared_ptr<Connection> newConnection;
        while ((currentConnection != NULL) && (currentConnection->isOutput == false)) 
        {
            currentConnection->ProcessSignal();
            tempConnection = currentConnection->WaitUntilDestinationIsReadyAndReturnNextConnection(); // We wait here, untill all input connections are processed
            newConnection = currentConnection->GetDestinationNextLonelyPotentialConnection();
            while (newConnection != NULL)
            {
                // if there is lonely connection available, lets spawn a Popagator on it
                unique_ptr<Propagator> ptrPropagator = make_unique<Propagator>(newConnection);
                newConnection = currentConnection->GetDestinationNextLonelyPotentialConnection();
            }

            currentConnection = tempConnection; // we are finished with lonely connections, lets propagate further
        }
        if (currentConnection != NULL)
        {
            // we have reached the connection to the output neuron so we process the last connection and signal its status
            currentConnection->ProcessSignal();
        }
        else 
        {
            // we have reached a dead end (other propagators have taken the available output connections from the last reached neuron
            // we don't have a job anymore
        }

        busy.unlock(); // lets unlock the mutex (and continue with self-destruct)
    }
}

