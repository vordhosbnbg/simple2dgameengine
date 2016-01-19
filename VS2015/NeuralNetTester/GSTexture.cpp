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

int GSTexture::GetWidth()
{
    int retVal;
    SDL_QueryTexture(texture_handle.get(), NULL, NULL, &retVal, NULL);
    return retVal;
}

int GSTexture::GetHeight()
{
    int retVal;
    SDL_QueryTexture(texture_handle.get(), NULL, NULL, NULL, &retVal);
    return retVal;
}
