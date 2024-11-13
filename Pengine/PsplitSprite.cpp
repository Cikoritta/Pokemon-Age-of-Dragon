#include "pch.h"
#include "PsplitSprite.h"

void PsplitSprite::SetTexture(const sf::String texturePath, sf::IntRect* textureRect[9])
{
    texture.loadFromFile(texturePath);

    topLeft.setTexture(texture);
    top.setTexture(texture);
    topRight.setTexture(texture);

    left.setTexture(texture);
    right.setTexture(texture);

    bottomLeft.setTexture(texture);
    bottom.setTexture(texture);
    bottomRight.setTexture(texture);


    topLeft.setTextureRect(*textureRect[0]);
    top.setTextureRect(*textureRect[1]);
    topRight.setTextureRect(*textureRect[2]);

    left.setTextureRect(*textureRect[3]);
    right.setTextureRect(*textureRect[5]);

    bottomLeft.setTextureRect(*textureRect[6]);
    bottom.setTextureRect(*textureRect[7]);
    bottomRight.setTextureRect(*textureRect[8]);
}


sf::Vector2u PsplitSprite::GetPixelPosition() const
{
    return (sf::Vector2u)topLeft.getPosition();
}

void PsplitSprite::SetPosition(float x, float y, Psprite* RelativeSprite)
{
    position.x = x;

    position.y = y;


    this->relativeSprite = RelativeSprite;


    if (RelativeSprite != nullptr)
    {
        topLeft.setPosition(((RelativeSprite->GetPixelPosition().x + (RelativeSprite->GetSize().x * x)) - RelativeSprite->GetPixelOrigin().x) - pixelOrigin.x, ((RelativeSprite->GetPixelPosition().y + (RelativeSprite->GetSize().y * y)) - RelativeSprite->GetPixelOrigin().y) - pixelOrigin.y);
    }
    else
    {
        topLeft.setPosition((window->getSize().x * x) - pixelOrigin.x, (window->getSize().y * y) - pixelOrigin.y);
    }


    top.setPosition(topLeft.getPosition().x + topLeft.getGlobalBounds().width, topLeft.getPosition().y);
    topRight.setPosition(top.getPosition().x + top.getGlobalBounds().width, top.getPosition().y);

    left.setPosition(topLeft.getPosition().x, topLeft.getPosition().y + topLeft.getGlobalBounds().height);
    sprite.setPosition(top.getPosition().x, top.getPosition().y + top.getGlobalBounds().height);
    right.setPosition(topRight.getPosition().x, topRight.getPosition().y + topRight.getGlobalBounds().height);

    bottomLeft.setPosition(left.getPosition().x, left.getPosition().y + left.getGlobalBounds().height);
    bottom.setPosition(sprite.getPosition().x, sprite.getPosition().y + sprite.getGlobalBounds().height);
    bottomRight.setPosition(right.getPosition().x, right.getPosition().y + right.getGlobalBounds().height);
}

void PsplitSprite::SetPixelPosition(sf::Uint16 x, sf::Uint16 y)
{
    topLeft.setPosition((float)(window->getSize().x * x) - pixelOrigin.x, (float)(window->getSize().y * y) - pixelOrigin.y);

    top.setPosition(topLeft.getPosition().x + topLeft.getGlobalBounds().width, topLeft.getPosition().y);
    topRight.setPosition(top.getPosition().x + top.getGlobalBounds().width, top.getPosition().y);

    left.setPosition(topLeft.getPosition().x, topLeft.getPosition().y + topLeft.getGlobalBounds().height);
    sprite.setPosition(top.getPosition().x, top.getPosition().y + top.getGlobalBounds().height);
    right.setPosition(topRight.getPosition().x, topRight.getPosition().y + topRight.getGlobalBounds().height);

    bottomLeft.setPosition(left.getPosition().x, left.getPosition().y + left.getGlobalBounds().height);
    bottom.setPosition(sprite.getPosition().x, sprite.getPosition().y + sprite.getGlobalBounds().height);
    bottomRight.setPosition(right.getPosition().x, right.getPosition().y + right.getGlobalBounds().height);
}


void PsplitSprite::SetScale(float x, float y)
{
    scale.x = x;

    scale.y = y;


    topLeft.setScale(windowScale.x * x, windowScale.y * y);
    top.setScale(windowScale.x * x, windowScale.y * y);
    topRight.setScale(windowScale.x * x, windowScale.y * y);

    left.setScale(windowScale.x * x, windowScale.y * y);
    sprite.setScale(windowScale.x * x, windowScale.y * y);
    right.setScale(windowScale.x * x, windowScale.y * y);

    bottomLeft.setScale(windowScale.x * x, windowScale.y * y);
    bottom.setScale(windowScale.x * x, windowScale.y * y);
    bottomRight.setScale(windowScale.x * x, windowScale.y * y);


    SetPosition(position.x, position.y, relativeSprite);
}

void PsplitSprite::SetSmartScale(float x, float y)
{
    scale.x = x;

    scale.y = y;


    float scaleFactor = 1.0f;

    
    if (x >= y)
    {
        scaleFactor = y / x;

        topLeft.setScale((windowScale.x * x) * scaleFactor, windowScale.y * y);
        top.setScale(windowScale.x * x, windowScale.y * y);
        topRight.setScale((windowScale.x * x) * scaleFactor, windowScale.y * y);

        left.setScale((windowScale.x * x) * scaleFactor, windowScale.y * y);
        sprite.setScale(windowScale.x * x, windowScale.y * y);
        right.setScale((windowScale.x * x) * scaleFactor, windowScale.y * y);

        bottomLeft.setScale((windowScale.x * x) * scaleFactor, windowScale.y * y);
        bottom.setScale(windowScale.x * x, windowScale.y * y);
        bottomRight.setScale((windowScale.x * x) * scaleFactor, windowScale.y * y);
    }
    else
    {
        scaleFactor = x / y;

        topLeft.setScale(windowScale.x * x, (windowScale.y * y) * scaleFactor);
        top.setScale(windowScale.x * x, (windowScale.y * y) * scaleFactor);
        topRight.setScale(windowScale.x * x, (windowScale.y * y) * scaleFactor);

        left.setScale(windowScale.x * x, windowScale.y * y);
        sprite.setScale(windowScale.x * x, windowScale.y * y);
        right.setScale(windowScale.x * x, windowScale.y * y);

        bottomLeft.setScale(windowScale.x * x, (windowScale.y * y) * scaleFactor);
        bottom.setScale(windowScale.x * x, (windowScale.y * y) * scaleFactor);
        bottomRight.setScale(windowScale.x * x, (windowScale.y * y) * scaleFactor);
    }


    SetPosition(position.x, position.y, relativeSprite);
}

void PsplitSprite::SetBorderScale(float x, float y)
{
    topLeft.setScale(x, y);
    top.setScale(scale.x, y);
    topRight.setScale(x, y);

    left.setScale(x, scale.y);
    right.setScale(x, scale.y);

    bottomLeft.setScale(x, y);
    bottom.setScale(scale.x, y);
    bottomRight.setScale(x, y);

    SetPosition(position.x, position.y, relativeSprite);
}


sf::Vector2u PsplitSprite::GetPixelOrigin() const
{
    return pixelOrigin;
}

void PsplitSprite::SetOrigin(float x, float y, bool local)
{
    origin.x = x;

    origin.y = y;


    pixelOrigin.x = (sf::Uint32)(GetSize(local).x * x);

    pixelOrigin.y = (sf::Uint32)(GetSize(local).y * y);


    SetPosition(position.x, position.y, relativeSprite);
}


sf::Vector2u PsplitSprite::GetSize(bool local) const
{
    sf::Uint16 width;

    sf::Uint16 height;


    if (local)
    {
        width = (sf::Uint16)(left.getLocalBounds().width + sprite.getLocalBounds().width - right.getLocalBounds().width);

        height = (sf::Uint16)(top.getLocalBounds().height + sprite.getLocalBounds().height - bottom.getLocalBounds().height);

        return sf::Vector2u(width, height);
    }


    width = (sf::Uint16)(left.getGlobalBounds().width + sprite.getGlobalBounds().width + right.getGlobalBounds().width);

    height = (sf::Uint16)(top.getGlobalBounds().height + sprite.getGlobalBounds().height + bottom.getGlobalBounds().height);


    return sf::Vector2u(width, height);
}

sf::IntRect PsplitSprite::GetBounds(bool local) const
{
    return sf::IntRect(GetPixelPosition().x - GetPixelOrigin().x, GetPixelPosition().y - GetPixelOrigin().y, GetSize().x, GetSize().y);
}


void PsplitSprite::Draw() const
{
    window->draw(topLeft);
    window->draw(top);
    window->draw(topRight);

    window->draw(left);
    window->draw(right);

    window->draw(bottomLeft);
    window->draw(bottom);
    window->draw(bottomRight);
}
