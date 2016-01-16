#include "GSSurface.h"



GSSurface::GSSurface()
{
}


GSSurface::~GSSurface()
{
}

SDL_Surface * GSSurface::GetRawHandle()
{
    return surface_handle.get();
}
