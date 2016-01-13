#ifndef NORMALIZEDVALUE_H
#define NORMALIZEDVALUE_H
#include <mutex>

using namespace std;
template<class T>
class NormalizedValue
{
public:
    NormalizedValue(T min, T max);
    ~NormalizedValue();

    T Get();
    void Set(T val);

    double GetNormalized();
    void SetNormalized(double val);

private:
    T minVal;
    T maxVal;
    const T rangeVal;
    const T reciprocalRangeVal;
    double normalizedValue;

    mutex value_mutex;
};

#endif //NORMALIZEDVALUE_H