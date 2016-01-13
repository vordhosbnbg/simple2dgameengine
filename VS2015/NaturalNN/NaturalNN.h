#ifndef NATURALNN_H
#define NATURALNN_H
#include <functional>
#include <map>
#include <string>
#include <memory>
#include "InputNeuron.h"
#include "OutputNeuron.h"

using namespace std;
class NaturalNN
{
public:
    NaturalNN();
    ~NaturalNN();
    bool RegisterInput(string inputName, int min, int max, function<int()> inputGetter);
    bool RegisterOutput(string outputName, int min, int max, function<void(int)> outputSetter);

    void Initialize();
private:

    map<string, shared_ptr<InputNeuron<int>>> ListOfIntInputs;
    map<string, shared_ptr<OutputNeuron<int>>> ListOfIntOutputs;

};

#endif // NATURALNN_H

