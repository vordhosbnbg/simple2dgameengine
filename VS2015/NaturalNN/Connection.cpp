#include "Connection.h"


Connection::Connection(shared_ptr<Neuron> source, shared_ptr<Neuron> destination)
{
    Source = source;
    Destination = destination;

    destSetEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
}

Connection::~Connection()
{
    CloseHandle(destSetEvent);
}

HANDLE Connection::GetDestinationSetEvent()
{
    return destSetEvent;
}
