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

private:
    void MainLoop();
    void SetRunningStatus(bool val);
    bool isRunning;
    mutex isRunning_mutex;
    shared_ptr<thread> threadMainLoop;

    shared_ptr<GraphicsDriver> gd;
    shared_ptr<PhysicsEngine> pe;

};

#endif // GAMEENGINE_H
