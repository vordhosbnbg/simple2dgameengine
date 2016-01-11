#ifndef CONNECTION_H
#define CONNECTION_H

#include <memory>
#include "Neuron.h"

using namespace std;
class Neuron;
class Connection
{
public:
    Connection(shared_ptr<Neuron> first, shared_ptr<Neuron> second);
    ~Connection();

private:
    double Weight;
    shared_ptr<Neuron> Source;
    shared_ptr<Neuron> Destination;
};

#endif //CONNECTION_H
