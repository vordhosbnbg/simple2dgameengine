#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <string>

using namespace std;
class ResourceManager
{
public:
    ResourceManager(string basePathToResources);
    ~ResourceManager();
private:
    string basePath;
};

#endif // RESOURCEMANAGER_H
