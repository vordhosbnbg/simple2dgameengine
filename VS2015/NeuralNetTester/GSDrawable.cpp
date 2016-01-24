#include "GSDrawable.h"



GSDrawable::GSDrawable() : GSRectangle(0,0,0,0), texture(NULL), angleOfRotation(0), srcRect(make_shared<GSRectangle>(0,0,0,0))
{

}


GSDrawable::GSDrawable(int x, int y, int w, int h, shared_ptr<GSTexture> tex) : GSRectangle(x,y,w,h), texture(tex), angleOfRotation(0), srcRect(make_shared<GSRectangle>(x,y,w,h))
{
}

GSDrawable::GSDrawable(shared_ptr<GSTexture> tex) : GSRectangle(0, 0, 0, 0), texture(tex), angleOfRotation(0), srcRect(make_shared<GSRectangle>(0, 0, 0, 0))
{
    UpdateSizeFromTexture();
}


GSDrawable::~GSDrawable()
{
}

void GSDrawable::UpdateDrawable(double dT)
{
}

double GSDrawable::GetDrawableRotation()
{
    lock_guard<mutex> lock(angleOfRotation_mutex);
    return angleOfRotation;
}

void GSDrawable::SetDrawableRotation(double val)
{
    lock_guard<mutex> lock(angleOfRotation_mutex);
    angleOfRotation = val + 90;
}

shared_ptr<GSTexture> GSDrawable::GetTexture()
{
    return texture;
}

void GSDrawable::SetTexture(shared_ptr<GSTexture> tex)
{
    texture = tex;
    UpdateSizeFromTexture();
}


shared_ptr<GSRectangle> GSDrawable::GetSrcRect()
{
    return srcRect;
}



void GSDrawable::UpdateSizeFromTexture()
{
    SetRectWidth(texture->GetWidth());
    SetRectHeight(texture->GetHeight());
    srcRect->SetRectWidth(texture->GetWidth());
    srcRect->SetRectHeight(texture->GetHeight());
}
