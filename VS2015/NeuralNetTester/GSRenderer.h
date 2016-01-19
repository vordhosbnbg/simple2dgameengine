#ifndef GSRENDERER_H
#define GSRENDERER_H
#include <memory>
#include "SDL.h"
#include "GSWindow.h"
#include "GSTexture.h"
#include "SdlDeleter.h"
#include "GSRectangle.h"
#include "GSDrawable.h"


using namespace std;
class GSTexture;
class GSDrawable;
class GSRenderer
{
public:
    GSRenderer(shared_ptr<GSWindow> window);
    ~GSRenderer();

    void Clear();
    void Draw(shared_ptr<GSDrawable> drawable);
    void RenderPresent();

    SDL_Renderer * GetRawHandle();
private:
    unique_ptr<SDL_Renderer, sdl_deleter> renderer_handle;
};

#endif // GSRENDERER_H
