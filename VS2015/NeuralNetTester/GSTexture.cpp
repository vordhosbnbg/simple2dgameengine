#include "GSTexture.h"



GSTexture::GSTexture(shared_ptr<GSRenderer> renderer, shared_ptr<GSSurface> surface) : texture_handle(SDL_CreateTextureFromSurface(renderer->GetRawHandle(), surface->GetRawHandle()), sdl_deleter())
{
}


GSTexture::~GSTexture()
{
}

SDL_Texture * GSTexture::GetRawHandle()
{
    return texture_handle.get();
}
