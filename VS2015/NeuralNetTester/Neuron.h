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

    void ConnectInput(shared_ptr<Connection> conn);
    void ConnectOutput(shared_ptr<Connection> conn);

    shared_ptr<Connection> GetNonBusyConnectionFromThisNeuron();
    shared_ptr<Connection> WaitUntilValueIsReadyAndReturnNextConnection();
    shared_ptr<Connection> GetNextLonelyPotentialConnection();

    bool isOutput;

protected:
    void WaitUntilValueIsReady();
    vector<shared_ptr<Connection>> ListOfOutputConnections;
    vector<shared_ptr<Connection>> ListOfInputConnections;
    
    double neuronValue;
    mutex neuronValue_mutex;

};

#endif NEURON_H


