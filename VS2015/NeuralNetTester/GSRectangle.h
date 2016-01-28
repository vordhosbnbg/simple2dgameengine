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

    int GetRectPosX();
    int GetRectPosY();
    int GetRectWidth();
    int GetRectHeight();
    void SetRectPosX(int val);
    void SetRectPosY(int val);
    void SetRectWidth(int val);
    void SetRectHeight(int val);
    void SetRectPositionAndSize(int x, int y, int w, int h);
    void SetRectPosition(int x, int y);
    void SetRectSize(int w, int h);

    bool Intersect(shared_ptr<GSRectangle> otherRect);
    bool PointIn();

    SDL_Rect * GetRawRect();

private:
    shared_ptr<SDL_Rect> raw_rect;
};

#endif // GSRECTANGLE_H
