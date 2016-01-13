#ifndef INPUTNEURON_H
#define INPUTNEURON_H

#include <memory>
#include "Neuron.h"
#include "NormalizedValue.h"

template<class T>
class InputNeuron : public Neuron
{
public:
    InputNeuron(T min, T max);
    ~InputNeuron();

    void InjectInput(T val);

private:
    unique_ptr<NormalizedValue<T>> input;
};


#endif // !INPUTNEURON_H

