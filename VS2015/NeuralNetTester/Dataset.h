#ifndef DATASET_H
#define DATASET_H
#include <vector>
#include "DataItem.h"


using namespace std;
class Dataset
{
public:
    Dataset();
    ~Dataset();

protected:
    vector<DataItem> CollectionOfData;
};


#endif // !DATASET_H

