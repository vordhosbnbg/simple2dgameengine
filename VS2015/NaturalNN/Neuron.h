#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <memory>
#include "Connection.h"

using namespace std;
class Connection;
class Neuron 
{
public:
    Neuron();
    ~Neuron();

private:
    vector<shared_ptr<Connection>> ListOfConnections;
};

#endif NEURON_H


