#ifndef GSWINDOW_H
#define GSWINDOW_H
#include <memory>
#include "SDL.h"
#include "SdlDeleter.h"

using namespace std;
class GSWindow
{
public:
    GSWindow(const char * title, int posX, int posY, int width, int height);
    SDL_Window * GetRawHandle();
    ~GSWindow();
private:
    unique_ptr<SDL_Window, sdl_deleter> windowHandle;
};

#endif // GSWINDOW_H

