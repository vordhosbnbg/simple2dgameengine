#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <memory>
#include <mutex>
#include "Connection.h"
#include "GUIDHolder.h"

using namespace std;
class Connection;
class Neuron : public GUIDHolder
{
public:
    Neuron();
    ~Neuron();

    double GetValue();
    void AddToValue(double addition);
    void ResetValue();

    shared_ptr<Connection> GetNonBusyConnectionFromThisNeuron();
    shared_ptr<Connection> WaitUntilValueIsReadyAndReturnNextConnection();
    shared_ptr<Connection> GetNextLonelyPotentialConnection();

private:
    vector<shared_ptr<Connection>> ListOfOutputConnections;
    vector<shared_ptr<Connection>> ListOfInputConnections;
    
    double neuronValue;
    mutex neuronValue_mutex;

};

#endif NEURON_H


