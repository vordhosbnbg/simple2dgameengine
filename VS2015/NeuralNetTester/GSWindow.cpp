#include "GSWindow.h"

GSWindow::GSWindow(const char * title, int posX, int posY, int width, int height) : windowHandle(SDL_CreateWindow(title, posX, posY, width, height, SDL_WINDOW_SHOWN), sdl_deleter())
{
}

SDL_Window * GSWindow::GetRawHandle()
{
    return windowHandle.get();
}


GSWindow::~GSWindow()
{
}
