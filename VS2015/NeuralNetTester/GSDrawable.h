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
class GSDrawable : public virtual GUIDHolder, public GSRectangle
{
public:
    GSDrawable();
    GSDrawable(int x, int y, int w, int h, shared_ptr<GSTexture> tex);
    GSDrawable(shared_ptr<GSTexture> tex);
    ~GSDrawable();

    virtual void UpdateDrawable(double dT);
    double GetDrawableRotation();
    void SetDrawableRotation(double val);

    shared_ptr<GSTexture> GetTexture();
    void SetTexture(shared_ptr<GSTexture> tex);

    shared_ptr<GSRectangle> GetSrcRect();

protected:
    shared_ptr<GSRectangle> srcRect;
    virtual void UpdateSizeFromTexture();
    shared_ptr<GSTexture> texture;
    string texturePath;
    double angleOfRotation;
    mutex angleOfRotation_mutex;
};

#endif // GSDRAWABLE_H
