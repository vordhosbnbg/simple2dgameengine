#include <algorithm>
#include "GSSurface.h"
#include "SDL_image.h"



GSSurface::GSSurface()
{
}

GSSurface::GSSurface(string filename)
{
    surface_handle = unique_ptr<SDL_Surface, sdl_deleter>(IMG_Load(filename.c_str()));
}


GSSurface::~GSSurface()
{
}

SDL_Surface * GSSurface::GetRawHandle()
{
    return surface_handle.get();
}
