#include <chrono>
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

    threadMainLoop = make_shared<thread>(&GameEngine::MainLoop, this);
}

void GameEngine::StopEngine()
{
    SetRunningStatus(false);
}

void GameEngine::AddGameObject(shared_ptr<GameObject> obj)
{
    lock_guard<mutex> lock(ListOfGameObjects_mutex);
    //obj->SetTexture(gd->GetTexture(obj->GetTexturePath())); // set the proper texture for this object
    pe->AddPhysicalObject(obj);
    gd->AddDrawable(obj);
    obj->RegisterWithEngine(this);
    ListOfGameObjects.push_back(obj);
}

void GameEngine::RemoveGameObject(shared_ptr<GameObject> obj)
{
    lock_guard<mutex> lock(ListOfGameObjectsToRemove_mutex);
    ListOfGameObjectsToRemove.push(obj);
    pe->RemovePhysicalObject(obj);
    gd->RemoveDrawable(obj);
}

shared_ptr<GSTexture> GameEngine::GetTexture(string pathToImageResrouce)
{
    return gd->GetTexture(pathToImageResrouce);
}

void GameEngine::MainLoop()
{
    auto oldTime = std::chrono::steady_clock::now();
    auto newTime = oldTime;

    while (IsRunning())
    {
        newTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> dTimeInSeconds = newTime - oldTime;
        oldTime = newTime;
        pe->Simulate(dTimeInSeconds.count());
        RemoveGameObjectsFromList();
        UpdateAllGameObjects(dTimeInSeconds.count());
        gd->RenderSingleFrame(dTimeInSeconds.count());
    }
}

void GameEngine::UpdateAllGameObjects(double dT)
{
    lock_guard<mutex> lock(ListOfGameObjects_mutex);
    for (auto iterGameObj = ListOfGameObjects.begin(); iterGameObj != ListOfGameObjects.end(); ++iterGameObj) 
    {
        (*iterGameObj)->Update(dT);
    }
}

void GameEngine::SetRunningStatus(bool val)
{
    lock_guard<mutex> lock(isRunning_mutex);

    isRunning = val;
}

void GameEngine::RemoveGameObjectsFromList()
{
    lock_guard<mutex> lock(ListOfGameObjectsToRemove_mutex);
    while (!ListOfGameObjectsToRemove.empty())
    {
        auto GameObjectToRemove = ListOfGameObjectsToRemove.front();
        ListOfGameObjectsToRemove.pop(); // we remove the game object from this list always

        for (auto iterGameObject = ListOfGameObjects.begin(); iterGameObject != ListOfGameObjects.end(); ++iterGameObject)
        {
            // if we find it in the game object list we remove it from there
            if ((*iterGameObject)->CompareWithObject((*GameObjectToRemove)))
            {
                PrintDebug(("Erasing object with GUID: " + to_string(GameObjectToRemove->guid) + "\n").c_str());
                ListOfGameObjects.erase(iterGameObject);
                break;
            }
        }
    }
}

