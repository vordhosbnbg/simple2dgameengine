#ifndef GRAPHICSDRIVER_H
#define GRAPHICSDRIVER_H
#include <memory>
#include <vector>
#include <mutex>
#include <queue>
#include "SDL.h"
#include "GSRenderer.h"
#include "GSDrawable.h"
#include "TextureManager.h"

class GraphicsDriver
{
public:
    GraphicsDriver(int width, int height);
    ~GraphicsDriver();

    bool AddDrawable(shared_ptr<GSDrawable> object);
    void RenderSingleFrame(double dT);
    bool RemoveDrawable(shared_ptr<GSDrawable> object);
    shared_ptr<GSTexture> GetTexture(string filename);
private:
    void UpdateAll(double dT);

    void PrepareDraw();
    void DrawAll();
    void RemoveDrawablesFromList();
    vector<shared_ptr<GSDrawable>> ListOfDrawables;
    mutex ListOfDrawables_mutex;
    queue<shared_ptr<GSDrawable>> ListOfDrawablesToRemove;
    mutex ListOfDrawablesToRemove_mutex;
    mutex reneringActive_mutex;
    shared_ptr<GSWindow> window;
    shared_ptr<GSRenderer> renderer;
    shared_ptr<TextureManager> textureManager;
};

#endif // GRAPHICSDRIVER_H
