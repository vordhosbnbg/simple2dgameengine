#include "Drawable.h"



Drawable::Drawable() : posX(0), posY(0), width(0), height(0), texture(NULL)
{

}

Drawable::Drawable(int x, int y, int w, int h, shared_ptr<GSTexture> tex) : posX(x), posY(y), width(w), height(h), texture(tex)
{
}

Drawable::Drawable(shared_ptr<GSTexture> tex) : posX(0), posY(0), width(0), height(0), texture(tex)
{
}


Drawable::~Drawable()
{
}

shared_ptr<GSTexture> Drawable::GetTexture()
{
    return texture;
}

void Drawable::SetTexture(shared_ptr<GSTexture> tex)
{
    texture = tex;
}

int Drawable::GetPosX()
{
    lock_guard<mutex> lock(posX_mutex);
    return posX;
}

int Drawable::GetPosY()
{
    lock_guard<mutex> lock(posY_mutex);
    return posY;
}

int Drawable::GetWidth()
{
    lock_guard<mutex> lock(width_mutex);
    return width;
}

int Drawable::GetHeight()
{
    lock_guard<mutex> lock(height_mutex);
    return height;
}

void Drawable::SetPosX(int val)
{
    lock_guard<mutex> lock(posX_mutex);
    posX = val;
}

void Drawable::SetPosY(int val)
{
    lock_guard<mutex> lock(posY_mutex);
    posY = val;
}

void Drawable::SetWidth(int val)
{
    lock_guard<mutex> lock(width_mutex);
    width = val;
}

void Drawable::SetHeight(int val)
{
    lock_guard<mutex> lock(height_mutex);
    height = val;
}

void Drawable::SetPosition(int x, int y, int w, int h)
{
    lock_guard<mutex> lockX(posX_mutex);
    lock_guard<mutex> lockY(posY_mutex);
    lock_guard<mutex> lockW(width_mutex);
    lock_guard<mutex> lockH(height_mutex);
}
