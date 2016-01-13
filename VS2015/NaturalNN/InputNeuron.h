#ifndef INPUTNEURON_H
#define INPUTNEURON_H

#include <memory>
#include "Neuron.h"
#include "NormalizedValue.h"


template<class T>
class InputNeuron : public Neuron
{
public:
    InputNeuron(T min, T max) : input(make_unique<NormalizedValue<int>>(min, max))
    {

    }

    ~InputNeuron() 
    {

    }

    void InjectInput(T val)
    {
        input->Set(val);
        neuronValue = input->GetNormalized();
    }

    void InjectInput()
    {
        if (funcGetInput != NULL)
        {
            input->Set(funcGetInput()); // set proper
            neuronValue = input->GetNormalized(); // get normalized and set in in the neuron
        }
    }

    void RegisterInput(function<T()> funcGetter) 
    {
        funcGetInput = funcGetter;
    }

private:
    unique_ptr<NormalizedValue<T>> input;
    function<T()> funcGetInput;
};

#endif // !INPUTNEURON_H
