#include "GameEngine.h"



GameEngine::GameEngine() : isRunning(false)
{
    gd = make_shared<GraphicsDriver>(1024, 768);
    pe = make_shared<PhysicsEngine>();
}


GameEngine::~GameEngine()
{
    StopEngine();
    threadMainLoop->join();
}

bool GameEngine::IsRunning()
{
    lock_guard<mutex> lock(isRunning_mutex);
    return isRunning;
}

void GameEngine::StartEngine()
{
    SetRunningStatus(true);

    shared_ptr<GSTexture> tex = gd->CreateTexture(".\\res\\pictures\\nanbot64.png");
    shared_ptr<GSDrawable> drwbl1 = make_shared<GSDrawable>(tex);
    shared_ptr<GSDrawable> drwbl2 = make_shared<GSDrawable>(tex);
    gd->AddDrawable(drwbl1);
    gd->AddDrawable(drwbl2);
    drwbl1->SetPosition(150, 200);
    drwbl2->SetPosition(200, 150);
    drwbl2->SetRotation(120.0);

    threadMainLoop = make_shared<thread>(&GameEngine::MainLoop, this);
}

void GameEngine::StopEngine()
{
    SetRunningStatus(false);
}

void GameEngine::MainLoop()
{
    while (IsRunning())
    {
        gd->RenderSingleFrame();
    }
}

void GameEngine::SetRunningStatus(bool val)
{
    lock_guard<mutex> lock(isRunning_mutex);

    isRunning = val;
}

