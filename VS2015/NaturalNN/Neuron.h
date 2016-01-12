#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <memory>
#include "Connection.h"
#include <mutex>

using namespace std;
class Connection;
class Neuron 
{
public:
    Neuron();
    ~Neuron();

    double GetValue();
    void AddToValue(double addition);
    void ResetValue();

private:
    vector<shared_ptr<Connection>> ConnectionsFrom;
    vector<shared_ptr<Connection>> ConnectionsTo;
    
    double neuronValue;
    mutex neuronValue_mutex;

};

#endif NEURON_H


