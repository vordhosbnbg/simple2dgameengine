#ifndef GUIDHOLDER_H
#define GUIDHOLDER_H
#include <Rpc.h>
#include <memory>
#include <stdint.h>
#include <string>

using namespace std;
class GUIDHolder
{
public:
    GUIDHolder();
    GUIDHolder(GUIDHolder& obj);
    ~GUIDHolder();
    bool GUIDHolder::CompareWithObject(GUIDHolder& obj);
    string GUIDToString();
    uint64_t guid;

};


#endif // GUIDHOLDER_H


