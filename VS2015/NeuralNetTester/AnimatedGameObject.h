#ifndef ANIMATEDGAMEOBJECT_H
#define ANIMATEDGAMEOBJECT_H
#include "GameObject.h"
#include "GSAnimation.h"

class AnimatedGameObject : public GameObject, public GSAnimation
{
public:
    AnimatedGameObject(
        Vector2D &position, 
        Vector2D &direction, 
        Vector2D &velocity, 
        double mass, 
        double friction, 
        double colliderRadius, 
        string pathToTexture, 
        bool isSleeping, 
        int numberOfFrames, 
        double animDuration, 
        AnimType animType, 
        bool isLooped);
    ~AnimatedGameObject();
};

#endif // ANIMATEDGAMEOBJECT_H
