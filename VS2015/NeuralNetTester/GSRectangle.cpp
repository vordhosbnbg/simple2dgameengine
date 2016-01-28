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
    return raw_rect->x;
}

int GSRectangle::GetRectPosY()
{
    return raw_rect->y;
}

int GSRectangle::GetRectWidth()
{
    return raw_rect->w;
}

int GSRectangle::GetRectHeight()
{
    return raw_rect->h;
}

void GSRectangle::SetRectPosX(int val)
{
    raw_rect->x = val;
}

void GSRectangle::SetRectPosY(int val)
{
    raw_rect->y = val;
}

void GSRectangle::SetRectWidth(int val)
{
    raw_rect->w = val;
}

void GSRectangle::SetRectHeight(int val)
{
    raw_rect->h = val;
}

void GSRectangle::SetRectPositionAndSize(int x, int y, int w, int h)
{
    raw_rect->x = x;
    raw_rect->y = y;
    raw_rect->w = w;
    raw_rect->h = h;
}

void GSRectangle::SetRectPosition(int x, int y)
{
    raw_rect->x = x;
    raw_rect->y = y;
}

void GSRectangle::SetRectSize(int w, int h)
{
    raw_rect->w = w;
    raw_rect->h = h;
}

SDL_Rect * GSRectangle::GetRawRect()
{
    return raw_rect.get();
}

