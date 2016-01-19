#include "DataItem.h"



DataItem::DataItem(int nbInputs, int nbOutputs)
{
    inputs.resize(nbInputs);
    outputs.resize(nbOutputs);
}

DataItem::~DataItem()
{

}

void DataItem::SetInput(int index, int value)
{
    if (index < inputs.size()) 
    {
        inputs[index] = value;
    }
}

int DataItem::GetInput(int index)
{
    return 0;
}

void DataItem::SetOutput(int index, int value)
{
    if (index < outputs.size())
    {
        outputs[index] = value;
    }
}

int DataItem::GetOutput(int index)
{
    return 0;
}
