#ifndef GRAPHICSDRIVER_H
#define GRAPHICSDRIVER_H
#include <memory>
#include <vector>
#include <mutex>
#include <queue>
#include "SDL.h"
#include "GSRenderer.h"
#include "GSDrawable.h"

class GraphicsDriver
{
public:
    GraphicsDriver();
    ~GraphicsDriver();

    bool Init(int width, int height);
    bool AddDrawable(shared_ptr<GSDrawable> object);
    bool IsRendering();
    void MainLoop();
    bool RemoveDrawable(shared_ptr<GSDrawable> object);
    void StartRender();
    void StopRender();
    shared_ptr<GSTexture> CreateTexture(string filename);
private:
    void PrepareDraw();
    void DrawAll();
    void SetRenderingStatus(bool val);
    void RemoveDrawablesFromList();
    bool isRendering;
    mutex isRendering_mutex;
    vector<shared_ptr<GSDrawable>> ListOfDrawables;
    queue<shared_ptr<GSDrawable>> ListOfDrawablesToRemove;
    mutex ListOfDrawablesToRemove_mutex;
    shared_ptr<GSWindow> window;
    shared_ptr<GSRenderer> renderer;
    shared_ptr<thread> threadRenderer;
};

#endif // GRAPHICSDRIVER_H
