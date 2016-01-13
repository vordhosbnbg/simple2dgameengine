#include "InputNeuron.h"

template<class T>
InputNeuron<T>::InputNeuron(T min, T max) : input(make_unique(min, max))
{

}

template<class T>
InputNeuron<T>::~InputNeuron()
{
}

template<class T>
void InputNeuron<T>::InjectInput(T val)
{
    input->Set(val);
    neuronValue = input->GetNormalized();
}
