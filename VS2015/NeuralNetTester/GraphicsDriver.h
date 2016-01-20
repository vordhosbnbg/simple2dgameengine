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
    GraphicsDriver(int width, int height);
    ~GraphicsDriver();

    bool AddDrawable(shared_ptr<GSDrawable> object);
    void RenderSingleFrame();
    bool RemoveDrawable(shared_ptr<GSDrawable> object);
    shared_ptr<GSTexture> CreateTexture(string filename);
private:
    void PrepareDraw();
    void DrawAll();
    void RemoveDrawablesFromList();
    vector<shared_ptr<GSDrawable>> ListOfDrawables;
    queue<shared_ptr<GSDrawable>> ListOfDrawablesToRemove;
    mutex ListOfDrawablesToRemove_mutex;
    shared_ptr<GSWindow> window;
    shared_ptr<GSRenderer> renderer;
};

#endif // GRAPHICSDRIVER_H
