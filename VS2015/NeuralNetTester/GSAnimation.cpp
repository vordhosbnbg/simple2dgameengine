#include "GSAnimation.h"




GSAnimation::GSAnimation(int numberOfFrames, double animDuration, AnimType type, bool looped) : GSDrawable(), NumberOfAnimFrames(numberOfFrames), AnimDuration(animDuration), Type(type), IsLooped(looped), InternalDurationCounter(0)
{
}

GSAnimation::~GSAnimation()
{
}

void GSAnimation::Reset()
{
    InternalDurationCounter = 0;
}

void GSAnimation::UpdateDrawable(double dT)
{
    InternalDurationCounter += dT;
    SetRectHeight(texture->GetHeight());
    SetRectWidth(texture->GetWidth() / NumberOfAnimFrames);

    UpdateSrcRectBasedOnAnimationState();
}

shared_ptr<GSTexture> GSAnimation::GetTexture()
{
    return texture;
}


void GSAnimation::UpdateSizeFromTexture()
{
    SetRectWidth(texture->GetWidth());
    SetRectHeight(texture->GetHeight());
    srcRect->SetRectWidth(texture->GetWidth() / NumberOfAnimFrames);
    srcRect->SetRectHeight(texture->GetHeight());

}

void GSAnimation::UpdateSrcRectBasedOnAnimationState()
{
    int index;
    switch (Type)
    {
    case GSAnimation::StartToEnd:
        index = ((int)(((InternalDurationCounter * NumberOfAnimFrames) / AnimDuration))) % NumberOfAnimFrames;
        break;
    case GSAnimation::EndToStart:
        index = NumberOfAnimFrames - 1 - ((int)(((InternalDurationCounter * NumberOfAnimFrames) / AnimDuration))) % NumberOfAnimFrames;
        break;
    default:
        break;
    }
    srcRect->SetRectPosX(index * srcRect->GetRectWidth());
}
