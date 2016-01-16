#include "GSRenderer.h"



GSRenderer::GSRenderer(shared_ptr<GSWindow> window) : renderer_handle(SDL_CreateRenderer(window->GetRawHandle(), - 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), sdl_deleter())
{
}


GSRenderer::~GSRenderer()
{
}

void GSRenderer::Clear()
{
    SDL_RenderClear(renderer_handle.get());
}

void GSRenderer::Copy(shared_ptr<GSTexture> texture)
{
    SDL_RenderCopy(renderer_handle.get(), texture->GetRawHandle(), NULL, NULL);
}

void GSRenderer::RenderPresent()
{
    SDL_RenderPresent(renderer_handle.get());
}

SDL_Renderer * GSRenderer::GetRawHandle()
{
    return renderer_handle.get();
}
