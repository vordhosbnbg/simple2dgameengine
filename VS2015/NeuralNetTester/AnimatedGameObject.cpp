#include "AnimatedGameObject.h"


AnimatedGameObject::AnimatedGameObject(
    Vector2D & position, 
    Vector2D & direction, 
    Vector2D & velocity,
    double mass, 
    double friction, 
    double colliderRadius, 
    string pathToTexture, 
    bool isCollidable, 
    bool hasImpulse,
    int numberOfFrames, 
    double animDuration, 
    AnimType animType,
    bool isLooped) : 
    GameObject(
        position,
        direction, 
        velocity, 
        mass, 
        friction, 
        colliderRadius, 
        pathToTexture, 
        isCollidable,
        hasImpulse),
    GSAnimation(
        numberOfFrames,
        animDuration,
        animType, 
        isLooped)
{
}

AnimatedGameObject::~AnimatedGameObject()
{
}
