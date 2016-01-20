#include "GSRectangle.h"



GSRectangle::GSRectangle(int x, int y, int w, int h)  : raw_rect(make_shared<SDL_Rect>())
{
    raw_rect->x = x;
    raw_rect->y = y;
    raw_rect->w = w;
    raw_rect->h = h;
}

GSRectangle::~GSRectangle()
{
}

int GSRectangle::GetRectPosX()
{
    lock_guard<mutex> lock(posX_mutex);
    return raw_rect->x;
}

int GSRectangle::GetRectPosY()
{
    lock_guard<mutex> lock(posY_mutex);
    return raw_rect->y;
}

int GSRectangle::GetRectWidth()
{
    lock_guard<mutex> lock(width_mutex);
    return raw_rect->w;
}

int GSRectangle::GetRectHeight()
{
    lock_guard<mutex> lock(height_mutex);
    return raw_rect->h;
}

void GSRectangle::SetRectPosX(int val)
{
    lock_guard<mutex> lock(posX_mutex);
    raw_rect->x = val;
}

void GSRectangle::SetRectPosY(int val)
{
    lock_guard<mutex> lock(posY_mutex);
    raw_rect->y = val;
}

void GSRectangle::SetRectWidth(int val)
{
    lock_guard<mutex> lock(width_mutex);
    raw_rect->w = val;
}

void GSRectangle::SetRectHeight(int val)
{
    lock_guard<mutex> lock(height_mutex);
    raw_rect->h = val;
}

void GSRectangle::SetRectPositionAndSize(int x, int y, int w, int h)
{
    lock_guard<mutex> lockX(posX_mutex);
    lock_guard<mutex> lockY(posY_mutex);
    lock_guard<mutex> lockW(width_mutex);
    lock_guard<mutex> lockH(height_mutex);
    raw_rect->x = x;
    raw_rect->y = y;
    raw_rect->w = w;
    raw_rect->h = h;
}

void GSRectangle::SetRectPosition(int x, int y)
{
    lock_guard<mutex> lockX(posX_mutex);
    lock_guard<mutex> lockY(posY_mutex);
    raw_rect->x = x;
    raw_rect->y = y;
}

void GSRectangle::SetRectSize(int w, int h)
{
    lock_guard<mutex> lockW(width_mutex);
    lock_guard<mutex> lockH(height_mutex);
    raw_rect->w = w;
    raw_rect->h = h;
}

SDL_Rect * GSRectangle::GetRawRect()
{
    return raw_rect.get();
}

