#ifndef GSTEXTURE_H
#define GSTEXTURE_H
#include <memory>
#include "SDL.h"
#include "GSRenderer.h"
#include "GSSurface.h"
#include "SdlDeleter.h"

using namespace std;
class GSRenderer;
class GSTexture
{
public:
    GSTexture(shared_ptr<GSRenderer> renderer, shared_ptr<GSSurface> surface);
    ~GSTexture();

    SDL_Texture * GetRawHandle();
    int GetWidth();
    int GetHeight();

private:
    unique_ptr<SDL_Texture, sdl_deleter> texture_handle;

};

#endif // GSTEXTURE_H
