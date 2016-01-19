#ifndef GSRECTANGLE_H
#define GSRECTANGLE_H
#include <memory>
#include <mutex>
#include "SDL_rect.h"

using namespace std;
class GSRectangle
{
public:
    GSRectangle(int x, int y, int w, int h);
    ~GSRectangle();

    int GetPosX();
    int GetPosY();
    int GetWidth();
    int GetHeight();
    void SetPosX(int val);
    void SetPosY(int val);
    void SetWidth(int val);
    void SetHeight(int val);
    void SetPositionAndSize(int x, int y, int w, int h);
    void SetPosition(int x, int y);
    void SetSize(int w, int h);

    bool Intersect(shared_ptr<GSRectangle> otherRect);
    bool PointIn();

    SDL_Rect * GetRawRect();

private:
    shared_ptr<SDL_Rect> raw_rect;
    mutex posX_mutex;
    mutex posY_mutex;
    mutex width_mutex;
    mutex height_mutex;
};

#endif // GSRECTANGLE_H
