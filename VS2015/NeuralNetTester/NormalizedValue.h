#ifndef NORMALIZEDVALUE_H
#define NORMALIZEDVALUE_H
#include <mutex>

using namespace std;
template<class T>
class NormalizedValue
{
public:
    NormalizedValue<T>::NormalizedValue(T min, T max) :
        minVal(min),
        maxVal(max),
        rangeVal(max - min),
        reciprocalRangeVal(1 / (max - min))
    {

    }


    NormalizedValue<T>::~NormalizedValue()
    {
    }


    T NormalizedValue<T>::Get()
    {
        lock_guard<mutex> lock(value_mutex);
        T retVal = (T)(normalizedValue*rangeVal + minVal);
        return retVal;
    }


    void NormalizedValue<T>::Set(T val)
    {
        lock_guard<mutex> lock(value_mutex);
        normalizedValue = (val - minVal)*(reciprocalRangeVal);
    }


    double NormalizedValue<T>::GetNormalized()
    {
        lock_guard<mutex> lock(value_mutex);
        return normalizedValue;
    }


    void NormalizedValue<T>::SetNormalized(double val)
    {
        lock_guard<mutex> lock(value_mutex);
        normalizedValue = val;
    }

private:
    T minVal;
    T maxVal;
    const T rangeVal;
    const T reciprocalRangeVal;
    double normalizedValue;

    mutex value_mutex;
};

#endif //NORMALIZEDVALUE_H