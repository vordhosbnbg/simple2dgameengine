#ifndef GSDRAWABLE_H
#define GSDRAWABLE_H
#include <mutex>
#include <memory>
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

    double GetDrawableRotation();
    void SetDrawableRotation(double val);

    shared_ptr<GSTexture> GetTexture();
    void SetTexture(shared_ptr<GSTexture> tex);
private:
    void UpdateSizeFromTexture();
    shared_ptr<GSTexture> texture;
    double angleOfRotation;
    mutex angleOfRotation_mutex;
};

#endif // GSDRAWABLE_H
