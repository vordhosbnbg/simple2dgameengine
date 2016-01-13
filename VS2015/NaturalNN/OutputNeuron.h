#ifndef OUTPUTNEURON_H
#define OUTPUTNEURON_H

#include <memory>
#include "Neuron.h"
#include "NormalizedValue.h"

using namespace std;
template<class T>
class OutputNeuron : public Neuron
{
public:
    OutputNeuron(T min, T max) : output(make_unique<NormalizedValue<int>>(min, max))
    {
        isOutput = true;
    }
    ~OutputNeuron() 
    {
    }

    void RegisterOutput(function<void(T)> funcSetter) 
    {
        funcSetOutput = funcSetter;
    }

private:
    void ResolveOutput() 
    {
        if (funcSetOutput != NULL)
        {
            WaitUntilValueIsReady(); // wait
            output->SetNormalized(neuronValue); // set normalized
            funcSetOutput(output->Get()); // get proper and push it out
        }
    }

    unique_ptr<NormalizedValue<T>> output;
    function<void(T)> funcSetOutput;
};


#endif // OUTPUTNEURON_H

