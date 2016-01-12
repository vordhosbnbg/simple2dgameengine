#include "Neuron.h"

Neuron::Neuron()
{
}

Neuron::~Neuron()
{
}

double Neuron::GetValue()
{
    std::lock_guard<mutex> lock(neuronValue_mutex);
    return neuronValue;
}

void Neuron::AddToValue(double addition)
{
    std::lock_guard<mutex> lock(neuronValue_mutex);
    neuronValue += addition;
}

void Neuron::ResetValue()
{
    std::lock_guard<mutex> lock(neuronValue_mutex);
    neuronValue = 0;
}
