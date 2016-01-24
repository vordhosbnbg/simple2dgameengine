#ifndef GSANIMATION_H
#define GSANIMATION_H
#include "GSDrawable.h"

class GSAnimation : virtual public GSDrawable
{
public:
    enum AnimType
    {
        StartToEnd,
        EndToStart,
    };

    GSAnimation(int numberOfFrames, double animDuration, AnimType type, bool looped);
    ~GSAnimation();


    void Reset();
    void UpdateDrawable(double dT) override;
    shared_ptr<GSTexture> GetTexture();


private:
    void UpdateSizeFromTexture() override;
    void UpdateSrcRectBasedOnAnimationState();
    int NumberOfAnimFrames;
    double AnimDuration;
    double InternalDurationCounter;
    AnimType Type;
    bool IsLooped;

};

#endif // GSANIMATION_H
