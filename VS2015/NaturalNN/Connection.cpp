#include "Connection.h"


Connection::Connection(shared_ptr<Neuron> source, shared_ptr<Neuron> destination, bool outputConnection) : Source(source), Destination(destination), isOutput(outputConnection)
{
    destSetEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
}

Connection::~Connection()
{
    CloseHandle(destSetEvent);
}

void Connection::ProcessSignal()
{
    auto x = Source->GetValue();
    auto y = x / (1 + abs(x));
    Destination->AddToValue(y);
    SetProcessed(true);
}

bool Connection::IsProcessed()
{
    lock_guard<mutex> lock(processed_mutex);
    return processed;
}

void Connection::SetProcessed(bool val)
{
    lock_guard<mutex> lock(processed_mutex);
    processed = val;
    if (val) 
    {
        SetEvent(destSetEvent); // signal that the connection has been processed
    }
    else 
    {
        ResetEvent(destSetEvent);
    }
}

bool Connection::IsBusy()
{
    lock_guard<mutex> lock(busy_mutex);
    return busy;
}

void Connection::SetBusy(bool val)
{
    lock_guard<mutex> lock(busy_mutex);
    busy = val;
}

bool Connection::IfNotBusySetBusy()
{
    bool retVal = false;

    lock_guard<mutex> lock(busy_mutex);
    if(!busy)
    {
        busy = true;
        retVal = true;
    }
    
    return retVal;
}

shared_ptr<Connection> Connection::WaitUntilDestinationIsReadyAndReturnNextConnection()
{
    return Destination->WaitUntilValueIsReadyAndReturnNextConnection();
}


shared_ptr<Connection> Connection::GetDestinationNextLonelyPotentialConnection()
{
    shared_ptr<Connection> retVal = NULL;
    if (Destination) 
    {
        retVal = Destination->GetNextLonelyPotentialConnection();
    }
    return retVal;
}

HANDLE Connection::GetDestinationSetEvent()
{
    return destSetEvent;
}
