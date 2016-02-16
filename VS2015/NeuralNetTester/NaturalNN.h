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
    bool RegisterInput(string inputName, double min, double max, function<double()> inputGetter);
    bool RegisterOutput(string outputName, double min, double max, function<void(double)> outputSetter);

    void Initialize();

    void RunOnce();
private:

    map<string, shared_ptr<InputNeuron<double>>> ListOfIntInputs;
    map<string, shared_ptr<OutputNeuron<double>>> ListOfIntOutputs;

};

#endif // NATURALNN_H

