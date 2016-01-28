#include "TagHolder.h"



TagHolder::TagHolder()
{
}


TagHolder::~TagHolder()
{
}

void TagHolder::AddTag(Tag tag)
{
    setOfTags.insert(tag);
}

bool TagHolder::HasTag(Tag tag)
{
    bool retVal = false;
    if (setOfTags.find(tag) != setOfTags.end()) 
    {
        retVal = true;
    }
    return retVal;
}
