#ifndef GRAPHICSDRIVER_H
#define GRAPHICSDRIVER_H
#include <memory>
#include <vector>
#include <mutex>
#include "SDL.h"
#include "GSRenderer.h"
#include "Drawable.h"

class GraphicsDriver
{
public:
    GraphicsDriver();
    ~GraphicsDriver();

    bool Init(int width, int height);
    bool AddDrawable(shared_ptr<Drawable> object);
    bool IsRendering();
    void RenderLoop();
    bool RemoveDrawable(shared_ptr<Drawable> object);
    void StartRender();
    void StopRender();
    shared_ptr<GSTexture> CreateTexture(string filename);
private:
    void SetRenderingStatus(bool val);
    bool isRendering;
    mutex isRendering_mutex;
    vector<shared_ptr<Drawable>> ListOfDrawables;
    shared_ptr<GSWindow> window;
    shared_ptr<GSRenderer> renderer;
    shared_ptr<thread> threadRenderer;
};

#endif // GRAPHICSDRIVER_H
