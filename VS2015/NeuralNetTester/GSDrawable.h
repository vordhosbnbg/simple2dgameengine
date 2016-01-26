#ifndef GSDRAWABLE_H
#define GSDRAWABLE_H
#include <mutex>
#include <memory>
#include <string>
#include <vector>
#include "GSTexture.h"
#include "GUIDHolder.h"
#include "GSRectangle.h"

using namespace std;
class GSTexture;
class GSDrawable : public virtual GUIDHolder
{
public:
    GSDrawable();
    GSDrawable(int x, int y, int w, int h, shared_ptr<GSTexture> tex);
    GSDrawable(shared_ptr<GSTexture> tex);
    ~GSDrawable();

    virtual void UpdateDrawable(double dT);
    double GetDrawableRotation();
    void SetDrawableRotation(double val);
    void SetZoom(double zoom);

    shared_ptr<GSTexture> GetTexture();
    void SetTexture(shared_ptr<GSTexture> tex);

    shared_ptr<GSRectangle> GetSrcRect();
    shared_ptr<GSRectangle> GetDstRect();

protected:
    double zoomLevel;
    shared_ptr<GSRectangle> srcRect;
    shared_ptr<GSRectangle> dstRect;
    virtual void UpdateSizeFromTexture();
    shared_ptr<GSTexture> texture;
    string texturePath;
    double angleOfRotation;
    mutex angleOfRotation_mutex;
};

#endif // GSDRAWABLE_H
