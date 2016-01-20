#include "GraphicsDriver.h"
#include "SDL_image.h"


GraphicsDriver::GraphicsDriver(int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        window = make_shared<GSWindow>("WindowTitle", 0, 0, width, height);
        renderer = make_shared<GSRenderer>(window);
        if (window && renderer)
        {
            int flags = IMG_INIT_JPG | IMG_INIT_PNG;
            int initted = IMG_Init(flags);
            if ((initted&flags) == flags)
            {
            }
        }
    }
}


GraphicsDriver::~GraphicsDriver()
{
    SDL_Quit();
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


void GraphicsDriver::RenderSingleFrame()
{
    PrepareDraw();
    DrawAll();
}

bool GraphicsDriver::RemoveDrawable(shared_ptr<GSDrawable> object)
{
    lock_guard<mutex> lock(ListOfDrawablesToRemove_mutex);
    ListOfDrawablesToRemove.push(object);
    return false;
}


shared_ptr<GSTexture> GraphicsDriver::CreateTexture(string filename)
{
    shared_ptr<GSTexture> tex = make_shared<GSTexture>(renderer, make_shared<GSSurface>(filename));
    return tex;
}

void GraphicsDriver::PrepareDraw()
{
    RemoveDrawablesFromList();
}

void GraphicsDriver::DrawAll()
{
    renderer->Clear();
    for (auto iterDrawable = ListOfDrawables.begin(); iterDrawable != ListOfDrawables.end(); ++iterDrawable)
    {
        renderer->Draw(*iterDrawable);
    }
    renderer->RenderPresent();
}

void GraphicsDriver::RemoveDrawablesFromList()
{
    lock_guard<mutex> lock(ListOfDrawablesToRemove_mutex);
    while(!ListOfDrawablesToRemove.empty()) 
    {
        auto DrawableToRemove = ListOfDrawablesToRemove.front();
        ListOfDrawablesToRemove.pop();

        for (auto iterDrawable = ListOfDrawables.begin(); iterDrawable != ListOfDrawables.end(); ++iterDrawable) 
        {
            if ((*iterDrawable)->CompareWithObject((*DrawableToRemove)))
            {
                ListOfDrawables.erase(iterDrawable);
                break;
            }
        }
    }
}

