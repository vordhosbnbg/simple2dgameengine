#include "GraphicsDriver.h"
#include "SDL_image.h"


GraphicsDriver::GraphicsDriver() : isRendering(false)
{
}


GraphicsDriver::~GraphicsDriver()
{
    SDL_Quit();
}

bool GraphicsDriver::Init(int width, int height)
{
    bool retVal = false;

    if (SDL_Init(SDL_INIT_VIDEO) == 0) 
    {
        window =  make_shared<GSWindow>("WindowTitle", 0, 0, width, height);
        renderer = make_shared<GSRenderer>(window);
        if (window && renderer) 
        {
            int flags = IMG_INIT_JPG | IMG_INIT_PNG;
            int initted = IMG_Init(flags);
            if ((initted&flags) == flags) 
            {
                retVal = true;
            }
        }
    }

    return retVal;
}

bool GraphicsDriver::AddDrawable(shared_ptr<GSDrawable> object)
{
    bool retVal = false;
    if (renderer) 
    {
        ListOfDrawables.push_back(object);
        retVal = true;
    };
    return retVal;
}

bool GraphicsDriver::IsRendering()
{
    lock_guard<mutex> lock(isRendering_mutex);
    return isRendering;
}

void GraphicsDriver::RenderLoop()
{
    while (IsRendering())
    {
        renderer->Clear();
        for (auto iterDrawable = ListOfDrawables.begin(); iterDrawable != ListOfDrawables.end(); ++iterDrawable) 
        {
            renderer->Copy(*iterDrawable);
        }
        renderer->RenderPresent();
    }
    threadRenderer->detach();
}

bool GraphicsDriver::RemoveDrawable(shared_ptr<GSDrawable> object)
{
    return false;
}

void GraphicsDriver::StartRender()
{
    SetRenderingStatus(true);
    threadRenderer = make_shared<thread>(&GraphicsDriver::RenderLoop, this);
}

void GraphicsDriver::StopRender()
{
    SetRenderingStatus(false);
}

shared_ptr<GSTexture> GraphicsDriver::CreateTexture(string filename)
{
    shared_ptr<GSTexture> tex = make_shared<GSTexture>(renderer, make_shared<GSSurface>(filename));
    return tex;
}

void GraphicsDriver::SetRenderingStatus(bool val)
{
    lock_guard<mutex> lock(isRendering_mutex);

    isRendering = val;
}

