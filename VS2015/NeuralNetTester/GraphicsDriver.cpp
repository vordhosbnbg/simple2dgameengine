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
        window = make_shared<GSWindow>("WindowTitle", 0, 0, width, height);
        renderer = make_shared<GSRenderer>(window);
    }
}

bool GraphicsDriver::AddDrawable(shared_ptr<Drawable> object)
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
            renderer->Copy((*iterDrawable)->GetTexture());
        }
        renderer->RenderPresent();
    }
}

bool GraphicsDriver::RemoveDrawable(shared_ptr<Drawable> object)
{
    return false;
}

void GraphicsDriver::StartRender()
{
    SetRenderingStatus(true);
}

void GraphicsDriver::StopRender()
{

}

void GraphicsDriver::SetRenderingStatus(bool val)
{
    lock_guard<mutex> lock(isRendering_mutex);

    isRendering = val;
}

