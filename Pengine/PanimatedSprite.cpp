#include "pch.h"
#include "PanimatedSprite.h"

void PanimatedSprite::Animate(sf::Uint16 sizeFrame, sf::Uint16 startFrame)
{
    if (!clockStart)
    {
        clock.restart();

        maxFrame = (sprite.getTexture()->getSize().x / sizeFrame) - 1U;


        this->sizeFrame = sizeFrame;


        currentFrame = startFrame;

        textureRect.left = currentFrame * sizeFrame;

        sprite.setTextureRect(textureRect);

        clockStart = true;
    }

    if (!pause && !animationEnd)
    {
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            if (currentFrame != maxFrame)
            {
                currentFrame++;

                textureRect.left += sizeFrame;
            }
            else if (loop)
            {
                currentFrame = 0U;

                textureRect.left = 0;
            }
            else
            {
                animationEnd = true;
            }

            sprite.setTextureRect(textureRect);

            clock.restart();
        }
    }
}


void PanimatedSprite::SetPause(bool pause)
{
    this->pause = pause;
}

bool PanimatedSprite::GetPause() const
{
    return pause;
}


void PanimatedSprite::SetLoop(bool loop)
{
    this->loop = loop;
}

bool PanimatedSprite::GetLoop() const
{
    return loop;
}


void PanimatedSprite::SetFrameTime(float frameTime)
{
    this->frameTime = frameTime;

}

float PanimatedSprite::GetFrameTime() const
{
    return frameTime;
}


void PanimatedSprite::SetCurrentFrame(sf::Uint16 currentFrame)
{
    this->currentFrame = currentFrame;

    textureRect.left = currentFrame * sizeFrame;

    sprite.setTextureRect(textureRect);
}

sf::Uint16 PanimatedSprite::GetCurrentFrame() const
{
    return currentFrame + 1U;
}


sf::Uint16 PanimatedSprite::GetMaxFrame() const
{
    return maxFrame;
}


bool PanimatedSprite::IfAnimationEnd() const
{
    return animationEnd;
}
