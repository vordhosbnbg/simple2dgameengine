#ifndef GSRENDERER_H
#define GSRENDERER_H
#include <memory>
#include "SDL.h"
#include "GSWindow.h"
#include "SdlDeleter.h"

using namespace std;
class GSRenderer
{
public:
    GSRenderer(shared_ptr<GSWindow> window);
    ~GSRenderer();
private:
    unique_ptr<SDL_Renderer, sdl_deleter> renderer_handle;
};

#endif // GSRENDERER_H
