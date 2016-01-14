#ifndef DATAITEM_H
#define DATAITEM_H
#include <vector>

using namespace std;
class DataItem
{
public:
    DataItem(int nbInputs, int nbOutputs);
    ~DataItem();

    void SetInput(int index, int value);
    int GetInput(int index);
    void SetOutput(int index, int value);
    int GetOutput(int index);
protected:
    vector<int> inputs;
    vector<int> outputs;
};

#endif // DATAITEM_H


