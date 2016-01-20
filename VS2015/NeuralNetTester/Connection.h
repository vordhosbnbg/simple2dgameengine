#ifndef CONNECTION_H
#define CONNECTION_H

#include <memory>
#include <mutex>
#include <Windows.h>
#include "Neuron.h"
#include "GUIDHolder.h"

using namespace std;
class Neuron;
class Connection : public virtual GUIDHolder
{
public:
    Connection(shared_ptr<Neuron> source, shared_ptr<Neuron> destination);
    ~Connection();

    void ProcessSignal();
    bool IsProcessed();
    void SetProcessed(bool val);
    bool IsBusy();
    void SetBusy(bool val);
    bool IfNotBusySetBusy();

    shared_ptr<Connection> WaitUntilDestinationIsReadyAndReturnNextConnection();
    shared_ptr<Connection> GetDestinationNextLonelyPotentialConnection();
    HANDLE GetDestinationSetEvent();
    bool IsOutput();

private:
    double Weight;
    bool processed;
    mutex processed_mutex;
    bool busy;
    mutex busy_mutex;
    shared_ptr<Neuron> Source;
    shared_ptr<Neuron> Destination;


    HANDLE destSetEvent;
};

#endif //CONNECTION_H
