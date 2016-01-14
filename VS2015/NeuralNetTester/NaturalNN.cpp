#include "NaturalNN.h"



NaturalNN::NaturalNN()
{
}


NaturalNN::~NaturalNN()
{
}

bool NaturalNN::RegisterInput(string inputName, int min, int max, function<int()> inputGetter)
{
    bool retVal = false;
    auto mapPair = ListOfIntInputs.insert(pair<string, shared_ptr<InputNeuron<int>>>(inputName, make_shared<InputNeuron<int>>(min, max)));
    if (mapPair.second) 
    {
        mapPair.first->second->RegisterInput(inputGetter);
        retVal = true;
    }
    return retVal;
}

bool NaturalNN::RegisterOutput(string outputName, int min, int max, function<void(int)> outputSetter)
{
    bool retVal = false;
    auto mapPair = ListOfIntOutputs.insert(pair<string, shared_ptr<OutputNeuron<int>>>(outputName, make_shared<OutputNeuron<int>>(min, max)));
    if (mapPair.second)
    {
        mapPair.first->second->RegisterOutput(outputSetter);
        retVal = true;
    }
    return retVal;
}


void NaturalNN::Initialize()
{
    // connect every input with every output
    for (auto iterInput = ListOfIntInputs.begin(); iterInput != ListOfIntInputs.end(); ++iterInput)
    {
        for (auto iterOutput = ListOfIntOutputs.begin(); iterOutput != ListOfIntOutputs.end(); ++iterOutput) 
        {
            // create new Connection object
            shared_ptr<Connection> new_connection = make_shared<Connection>(static_pointer_cast<Neuron>(iterInput->second), static_pointer_cast<Neuron>(iterOutput->second));
            // establish the reference to it in the neurons
            iterInput->second->ConnectOutput(new_connection);
            iterOutput->second->ConnectInput(new_connection);
        }
    }

}

void NaturalNN::RunOnce()
{
    // start signal propagation on all input neurons
    for (auto iterInput = ListOfIntInputs.begin(); iterInput != ListOfIntInputs.end(); ++iterInput) 
    {
        iterInput->second->StartPropagation();
    }

    for (auto iterOutput = ListOfIntOutputs.begin(); iterOutput != ListOfIntOutputs.end(); ++iterOutput) 
    {
        iterOutput->second->ResolveOutput(); // we wait here for each output to be resolved
    }

    // the outputs are computed
}
