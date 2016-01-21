#include "GraphicsDriver.h"
#include "SDL_image.h"


GraphicsDriver::GraphicsDriver(int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        window = make_shared<GSWindow>("WindowTitle", 0, 0, width, height);
        renderer = make_shared<GSRenderer>(window);
        textureManager = make_shared<TextureManager>(renderer);
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
    lock_guard<mutex> lock(ListOfDrawables_mutex);
    if (renderer) 
    {
        ListOfDrawables.push_back(object);
        retVal = true;
    };
    return retVal;
}


void GraphicsDriver::RenderSingleFrame()
{
    lock_guard<mutex> lock(ListOfDrawables_mutex);
    PrepareDraw();
    DrawAll();
}

bool GraphicsDriver::RemoveDrawable(shared_ptr<GSDrawable> object)
{
    lock_guard<mutex> lock(ListOfDrawablesToRemove_mutex);
    ListOfDrawablesToRemove.push(object);
    return false;
}


shared_ptr<GSTexture> GraphicsDriver::GetTexture(string filename)
{
    lock_guard<mutex> lock(reneringActive_mutex);
    return textureManager->GetTexture(filename);
}

void GraphicsDriver::PrepareDraw()
{
    RemoveDrawablesFromList();
}

void GraphicsDriver::DrawAll()
{
    lock_guard<mutex> lock(reneringActive_mutex);
    renderer->Clear();
    for (auto iterDrawable = ListOfDrawables.begin(); iterDrawable != ListOfDrawables.end(); ++iterDrawable)
    {
        renderer->Draw(*iterDrawable);
    }
    renderer->RenderPresent();
}

void GraphicsDriver::RemoveDrawablesFromList()
{
    lock_guard<mutex> lock1(ListOfDrawablesToRemove_mutex);
    while(!ListOfDrawablesToRemove.empty()) 
    {
        auto DrawableToRemove = ListOfDrawablesToRemove.front();
        ListOfDrawablesToRemove.pop(); // we remove the drawable from this list always

        for (auto iterDrawable = ListOfDrawables.begin(); iterDrawable != ListOfDrawables.end(); ++iterDrawable) 
        {
            // if we find it in the drawble list we remove it from there
            if ((*iterDrawable)->CompareWithObject((*DrawableToRemove)))
            {
                ListOfDrawables.erase(iterDrawable);
                break;
            }
        }
    }
}

