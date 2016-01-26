#include "GSDrawable.h"



GSDrawable::GSDrawable() : texture(NULL), angleOfRotation(0), srcRect(make_shared<GSRectangle>(0,0,0,0)), dstRect(make_shared<GSRectangle>(0, 0, 0, 0)), zoomLevel(1)
{

}


GSDrawable::GSDrawable(int x, int y, int w, int h, shared_ptr<GSTexture> tex) : texture(tex), angleOfRotation(0), srcRect(make_shared<GSRectangle>(x,y,w,h)), dstRect(make_shared<GSRectangle>(0, 0, 0, 0)), zoomLevel(1)
{
}

GSDrawable::GSDrawable(shared_ptr<GSTexture> tex) : texture(tex), angleOfRotation(0), srcRect(make_shared<GSRectangle>(0, 0, 0, 0)), dstRect(make_shared<GSRectangle>(0, 0, 0, 0)), zoomLevel(1)
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

void GSDrawable::SetZoom(double zoom)
{
    zoomLevel = zoom;
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

shared_ptr<GSRectangle> GSDrawable::GetDstRect()
{
    return dstRect;
}



void GSDrawable::UpdateSizeFromTexture()
{
    dstRect->SetRectWidth(texture->GetWidth() * zoomLevel);
    dstRect->SetRectHeight(texture->GetHeight() * zoomLevel);
    srcRect->SetRectWidth(texture->GetWidth());
    srcRect->SetRectHeight(texture->GetHeight());
}
