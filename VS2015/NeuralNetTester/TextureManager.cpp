#include "TextureManager.h"



TextureManager::TextureManager(shared_ptr<GSRenderer> renderer)
{
    rend = renderer;
}


TextureManager::~TextureManager()
{
}

shared_ptr<GSTexture> TextureManager::GetTexture(string imageResourcePath)
{
    shared_ptr<GSTexture> retVal = nullptr;
    auto iterTexture = MapOfLoadedTextures.find(imageResourcePath);
    if (iterTexture != MapOfLoadedTextures.end()) 
    {
        retVal = (*iterTexture).second;
    }
    else 
    {
        retVal = make_shared<GSTexture>(rend, make_shared<GSSurface>(imageResourcePath));
        MapOfLoadedTextures.insert(pair<string, shared_ptr<GSTexture>>(imageResourcePath, retVal));
    }
    return retVal;
}
