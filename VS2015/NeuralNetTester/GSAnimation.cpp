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
    dstRect->SetRectHeight(texture->GetHeight() * zoomLevel);
    dstRect->SetRectWidth((texture->GetWidth() * zoomLevel)/ NumberOfAnimFrames);

    UpdateSrcRectBasedOnAnimationState();
}

shared_ptr<GSTexture> GSAnimation::GetTexture()
{
    return texture;
}


void GSAnimation::UpdateSizeFromTexture()
{
    dstRect->SetRectWidth((texture->GetWidth() * zoomLevel) / NumberOfAnimFrames);
    dstRect->SetRectHeight((texture->GetHeight() * zoomLevel));
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
