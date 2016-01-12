#include "Connection.h"


Connection::Connection(shared_ptr<Neuron> source, shared_ptr<Neuron> destination, bool outputConnection) : Source(source), Destination(destination), isOutput(outputConnection)
{
    destSetEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
}

Connection::~Connection()
{
    CloseHandle(destSetEvent);
}

void Connection::ProcessSignal()
{
    auto x = (*Source).GetValue();
    auto y = x / (1 + abs(x));
    (*Destination).AddToValue(y);
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
}

HANDLE Connection::GetDestinationSetEvent()
{
    return destSetEvent;
}
