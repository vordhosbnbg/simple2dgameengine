#include "NormalizedValue.h"



template<class T>
NormalizedValue<T>::NormalizedValue(T min, T max) : 
    minVal(min),
    maxVal(max), 
    rangeVal(max - min), 
    reciprocalRangeVal(1/(max-min))
{

}

template<class T>
NormalizedValue<T>::~NormalizedValue()
{
}

template<class T>
T NormalizedValue<T>::Get()
{
    lock_guard<mutex> lock(value_mutex);
    T retVal = normalizedValue*rangeVal + minVal;
    return retVal;
}

template<class T>
void NormalizedValue<T>::Set(T val)
{
    lock_guard<mutex> lock(value_mutex);
    normalizedValue = (val - minVal)*(reciprocalRangeVal)
}

template<class T>
double NormalizedValue<T>::GetNormalized()
{
    lock_guard<mutex> lock(value_mutex);
    return normalizedValue;
}

template<class T>
void NormalizedValue<T>::SetNormalized(double val)
{
    lock_guard<mutex> lock(value_mutex);
    normalizedValue = val;
}

