#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <mutex>
#include <memory>
#include "GSTexture.h"
#include "GUIDHolder.h"

using namespace std;
class Drawable : GUIDHolder
{
public:
    Drawable();
    Drawable(int x, int y, int w, int h, shared_ptr<GSTexture> tex);
    Drawable(shared_ptr<GSTexture> tex);
    ~Drawable();

    shared_ptr<GSTexture> GetTexture();
    void SetTexture(shared_ptr<GSTexture> tex);
    int GetPosX();
    int GetPosY();
    int GetWidth();
    int GetHeight();
    void SetPosX(int val);
    void SetPosY(int val);
    void SetWidth(int val);
    void SetHeight(int val);
    void SetPosition(int x, int y, int w, int h);
private:
    shared_ptr<GSTexture> texture;
    int posX;
    mutex posX_mutex;
    int posY;
    mutex posY_mutex;
    int width;
    mutex width_mutex;
    int height;
    mutex height_mutex;
};

#endif // DRAWABLE_H
