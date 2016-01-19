#ifndef GSSURFACE_H
#define GSSURFACE_H
#include <memory>
#include <string>
#include "SDL.h"
#include "SdlDeleter.h"

using namespace std;
class GSSurface
{
public:
    GSSurface();
    GSSurface(string filename);
    ~GSSurface();

    SDL_Surface * GetRawHandle();
private:
    unique_ptr<SDL_Surface, sdl_deleter> surface_handle;
};

#endif // GSSURFACE_H
