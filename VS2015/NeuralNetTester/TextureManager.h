#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <memory>
#include <map>
#include "GSTexture.h"
#include "GSRenderer.h"

using namespace std;
class TextureManager
{
public:
    TextureManager(shared_ptr<GSRenderer> renderer);
    ~TextureManager();

    shared_ptr<GSTexture> GetTexture(string imageResourcePath);

private:
    shared_ptr<GSRenderer> rend;
    map<string, shared_ptr<GSTexture>> MapOfLoadedTextures;
};

#endif // TEXTUREMANAGER_H
