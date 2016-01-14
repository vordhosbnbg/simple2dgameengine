#include "Neuron.h"

Neuron::Neuron() : isOutput(false)
{
}

Neuron::~Neuron()
{
}

double Neuron::GetValue()
{
    std::lock_guard<mutex> lock(neuronValue_mutex);
    return neuronValue;
}

void Neuron::AddToValue(double addition)
{
    std::lock_guard<mutex> lock(neuronValue_mutex);
    neuronValue += addition;
}

void Neuron::ResetValue()
{
    std::lock_guard<mutex> lock(neuronValue_mutex);
    neuronValue = 0;
}

void Neuron::ConnectInput(shared_ptr<Connection> conn)
{
    ListOfInputConnections.push_back(conn);
}

void Neuron::ConnectOutput(shared_ptr<Connection> conn)
{
    ListOfOutputConnections.push_back(conn);
}



shared_ptr<Connection> Neuron::GetNonBusyConnectionFromThisNeuron()
{
    shared_ptr<Connection> retVal;
    for (auto iter = ListOfOutputConnections.begin(); iter != ListOfOutputConnections.end(); ++iter)
    {
        if (!(**iter).IsProcessed())
        {
            retVal = *iter;
        }
    }

    return retVal;
}

shared_ptr<Connection> Neuron::WaitUntilValueIsReadyAndReturnNextConnection()
{
    shared_ptr<Connection> retVal = NULL; // return NULL by default (if we have 0 non-busy output connections)
    WaitUntilValueIsReady();
    
    // all input connections have been processed so now we return the next output connection
    for (auto iterConn = ListOfOutputConnections.begin(); iterConn != ListOfOutputConnections.end(); ++iterConn)
    {
        if ((*iterConn)->IfNotBusySetBusy()) 
        {
            retVal = *iterConn; // return the first non-busy connection
            break;
        }
    }
    
    return retVal;
}


shared_ptr<Connection> Neuron::GetNextLonelyPotentialConnection()
{
    shared_ptr<Connection> retVal = NULL;
    
    // if we have more outputs than inputs, then we have potential lonely connections
    if ((ListOfOutputConnections.size() - ListOfInputConnections.size()) > 0)
    {
        for (auto iterConn = ListOfOutputConnections.begin(); iterConn != ListOfOutputConnections.end(); ++iterConn)
        {
            if ((*iterConn)->IfNotBusySetBusy())
            {
                retVal = *iterConn;
                break;
            }
        }
    }

    return retVal;
}

void Neuron::WaitUntilValueIsReady()
{
    vector<HANDLE> ListOfEvents; // create new vector for the HANDLES
    ListOfEvents.resize(ListOfInputConnections.size()); // make it the same size as the number of connections in
    auto iterHandle = ListOfEvents.begin();
    for (auto iterConn = ListOfInputConnections.begin(); iterConn != ListOfInputConnections.end(); ++iterConn, ++iterHandle)
    {
        *iterHandle = (*iterConn)->GetDestinationSetEvent();
    }
    // Now we should have all handles from incomming connections' set events
    // So lets wait
    // (we can reasonably expect that size of the input connection list will be much less than 0x7FFFFFFF)
    WaitForMultipleObjects((DWORD)ListOfEvents.size(), ListOfEvents.data(), TRUE, INFINITE);
}

