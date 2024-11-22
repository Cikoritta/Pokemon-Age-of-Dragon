#pragma once
#include "Psprite.h"

class PanimatedSprite : public Psprite
{
    sf::Clock       clock;


    sf::Uint16      maxFrame = 0U;

    sf::Uint16      currentFrame = 0U;

    sf::Uint16      sizeFrame = 0U;

    float           frameTime = 0.0f;

    float           maxLeft = 0.0f;


    bool            pause = false;

    bool            animationEnd = false;

    bool            loop = false;


    bool            clockStart = false;


    float           animationScale = 1.0f;
    bool            animationScaleVector = true;
    sf::Vector2f    baseScale = { 1.0f, 1.0f };

public:

    PanimatedSprite() = default;

    PanimatedSprite(sf::RenderWindow* window, sf::Event* event, sf::String texturePath = "none", sf::IntRect* textureRect = nullptr) : Psprite(window, event, texturePath, textureRect)
    {
        baseScale = sprite.getScale();
    }


    void            Animate(sf::Uint16 sizeFrame, sf::Uint16 interval, sf::Uint16 startFrame = 0U);

    void            ScaleAnimate(float minScale, float maxScale, float interval = 0.01f);


    void            SetPause(bool pause);

    bool            GetPause() const;


    void            ScaleAnimateReset();


    void            SetLoop(bool loop);

    bool            GetLoop() const;


    void            SetFrameTime(float frameTime);

    float           GetFrameTime() const;


    void            SetCurrentFrame(sf::Uint16 currentFrame);

    sf::Uint16      GetCurrentFrame() const;


    sf::Uint16      GetMaxFrame() const;


    bool            IfAnimationEnd() const;
};
