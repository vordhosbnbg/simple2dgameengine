#include "Connection.h"


Connection::Connection(shared_ptr<Neuron> source, shared_ptr<Neuron> destination)
{
    Source = source;
    Destination = destination;
}

Connection::~Connection()
{
}
