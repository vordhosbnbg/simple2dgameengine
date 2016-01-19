#include "GSDrawable.h"



GSDrawable::GSDrawable() : GSRectangle(0,0,0,0), texture(NULL), angleOfRotation(0)
{

}

GSDrawable::GSDrawable(int x, int y, int w, int h, shared_ptr<GSTexture> tex) : GSRectangle(x,y,w,h), texture(tex), angleOfRotation(0)
{
}

GSDrawable::GSDrawable(shared_ptr<GSTexture> tex) : GSRectangle(0, 0, 0, 0), texture(tex), angleOfRotation(0)
{
    UpdateSizeFromTexture();
}


GSDrawable::~GSDrawable()
{
}

double GSDrawable::GetRotation()
{
    lock_guard<mutex> lock(angleOfRotation_mutex);
    return angleOfRotation;
}

void GSDrawable::SetRotation(double val)
{
    lock_guard<mutex> lock(angleOfRotation_mutex);
    angleOfRotation = val;
}

shared_ptr<GSTexture> GSDrawable::GetTexture()
{
    return texture;
}

void GSDrawable::SetTexture(shared_ptr<GSTexture> tex)
{
    texture = tex;
}

void GSDrawable::UpdateSizeFromTexture()
{
    SetWidth(texture->GetWidth());
    SetHeight(texture->GetHeight());
}
