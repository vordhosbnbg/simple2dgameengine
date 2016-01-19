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


void GSRenderer::Draw(shared_ptr<GSDrawable> drawable)
{
    SDL_RenderCopyEx(renderer_handle.get(), drawable->GetTexture()->GetRawHandle(), NULL, drawable->GetRawRect(), drawable->GetRotation(), NULL, SDL_FLIP_NONE);
}

void GSRenderer::RenderPresent()
{
    SDL_RenderPresent(renderer_handle.get());
}

SDL_Renderer * GSRenderer::GetRawHandle()
{
    return renderer_handle.get();
}
