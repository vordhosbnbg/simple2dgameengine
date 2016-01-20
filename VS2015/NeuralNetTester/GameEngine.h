#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "GraphicsDriver.h"
#include "PhysicsEngine.h"

class GameEngine
{
public:
    GameEngine();
    ~GameEngine();

    bool IsRunning();
    void StartEngine();
    void StopEngine();

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
