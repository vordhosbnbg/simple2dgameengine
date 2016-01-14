#include "GSRenderer.h"



GSRenderer::GSRenderer(shared_ptr<GSWindow> window) : renderer_handle(SDL_CreateRenderer(window->GetRawHandle(), - 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), sdl_deleter())
{
}


GSRenderer::~GSRenderer()
{
}
