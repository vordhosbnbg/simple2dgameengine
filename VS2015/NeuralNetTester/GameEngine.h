#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "GraphicsDriver.h"
#include "PhysicsEngine.h"
#include "GameObject.h"

class GameEngine
{
public:
    GameEngine();
    ~GameEngine();

    bool IsRunning();
    void StartEngine();
    void StopEngine();
    void AddGameObject(shared_ptr<GameObject> obj);
    void RemoveGameObject(shared_ptr<GameObject> obj);

    shared_ptr<GSTexture> GetTexture(string pathToImageResrouce);
private:
    void MainLoop();
    void UpdateAllObjects(double dT);
    void SetRunningStatus(bool val);
    void RemoveDrawablesFromList();
    bool isRunning;
    mutex isRunning_mutex;
    shared_ptr<thread> threadMainLoop;
    vector<shared_ptr<GameObject>> ListOfGameObjects;
    mutex ListOfGameObjects_mutex;
    queue<shared_ptr<GameObject>> ListOfGameObjectsToRemove;
    mutex ListOfGameObjectsToRemove_mutex;
    shared_ptr<GraphicsDriver> gd;
    shared_ptr<PhysicsEngine> pe;

};

#endif // GAMEENGINE_H
