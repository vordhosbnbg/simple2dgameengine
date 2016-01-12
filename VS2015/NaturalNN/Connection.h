#ifndef CONNECTION_H
#define CONNECTION_H

#include <memory>
#include <Windows.h>
#include "Neuron.h"

using namespace std;
class Neuron;
class Connection
{
public:
    Connection(shared_ptr<Neuron> first, shared_ptr<Neuron> second);
    ~Connection();

    HANDLE GetDestinationSetEvent();

private:
    double Weight;
    shared_ptr<Neuron> Source;
    shared_ptr<Neuron> Destination;

    HANDLE destSetEvent;
};

#endif //CONNECTION_H
