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


sf::Vector2f PsplitSprite::GetPixelPosition() const
{
    return topLeft.getPosition();
}

void PsplitSprite::SetPosition(sf::Vector2f position, Psprite* RelativeSprite)
{
    this->position = position;


    this->relativeSprite = RelativeSprite;


    if (RelativeSprite != nullptr)
    {
        topLeft.setPosition(((RelativeSprite->GetPixelPosition().x + (RelativeSprite->GetSize().x * position.x)) - RelativeSprite->GetPixelOrigin().x) - pixelOrigin.x, ((RelativeSprite->GetPixelPosition().y + (RelativeSprite->GetSize().y * position.y)) - RelativeSprite->GetPixelOrigin().y) - pixelOrigin.y);
    }
    else
    {
        topLeft.setPosition((window->getSize().x * position.x) - pixelOrigin.x, (window->getSize().y * position.y) - pixelOrigin.y);
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

void PsplitSprite::SetPixelPosition(sf::Vector2f position)
{
    topLeft.setPosition((float)(window->getSize().x * position.x) - pixelOrigin.x, (float)(window->getSize().y * position.y) - pixelOrigin.y);

    top.setPosition(topLeft.getPosition().x + topLeft.getGlobalBounds().width, topLeft.getPosition().y);
    topRight.setPosition(top.getPosition().x + top.getGlobalBounds().width, top.getPosition().y);

    left.setPosition(topLeft.getPosition().x, topLeft.getPosition().y + topLeft.getGlobalBounds().height);
    sprite.setPosition(top.getPosition().x, top.getPosition().y + top.getGlobalBounds().height);
    right.setPosition(topRight.getPosition().x, topRight.getPosition().y + topRight.getGlobalBounds().height);

    bottomLeft.setPosition(left.getPosition().x, left.getPosition().y + left.getGlobalBounds().height);
    bottom.setPosition(sprite.getPosition().x, sprite.getPosition().y + sprite.getGlobalBounds().height);
    bottomRight.setPosition(right.getPosition().x, right.getPosition().y + right.getGlobalBounds().height);

    this->position = { position.x / window->getSize().x, position.y / window->getSize().y };
}


void PsplitSprite::SetScale(sf::Vector2f scale)
{
    this->scale = scale;


    topLeft.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
    top.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
    topRight.setScale(windowScale.x * scale.x, windowScale.y * scale.y);

    left.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
    sprite.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
    right.setScale(windowScale.x * scale.x, windowScale.y * scale.y);

    bottomLeft.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
    bottom.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
    bottomRight.setScale(windowScale.x * scale.x, windowScale.y * scale.y);


    SetPosition(position, relativeSprite);
}

void PsplitSprite::SetSmartScale(sf::Vector2f scale)
{
    this->scale = scale;


    float scaleFactor = 1.0f;

    
    if (scale.x >= scale.y)
    {
        scaleFactor = scale.y / scale.x;

        topLeft.setScale((windowScale.x * scale.x) * scaleFactor, windowScale.y * scale.y);
        top.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
        topRight.setScale((windowScale.x * scale.x) * scaleFactor, windowScale.y * scale.y);

        left.setScale((windowScale.x * scale.x) * scaleFactor, windowScale.y * scale.y);
        sprite.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
        right.setScale((windowScale.x * scale.x) * scaleFactor, windowScale.y * scale.y);

        bottomLeft.setScale((windowScale.x * scale.x) * scaleFactor, windowScale.y * scale.y);
        bottom.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
        bottomRight.setScale((windowScale.x * scale.x) * scaleFactor, windowScale.y * scale.y);
    }
    else
    {
        scaleFactor = scale.x / scale.y;

        topLeft.setScale(windowScale.x * scale.x, (windowScale.y * scale.y) * scaleFactor);
        top.setScale(windowScale.x * scale.x, (windowScale.y * scale.y) * scaleFactor);
        topRight.setScale(windowScale.x * scale.x, (windowScale.y * scale.y) * scaleFactor);

        left.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
        sprite.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
        right.setScale(windowScale.x * scale.x, windowScale.y * scale.y);

        bottomLeft.setScale(windowScale.x * scale.x, (windowScale.y * scale.y) * scaleFactor);
        bottom.setScale(windowScale.x * scale.x, (windowScale.y * scale.y) * scaleFactor);
        bottomRight.setScale(windowScale.x * scale.x, (windowScale.y * scale.y) * scaleFactor);
    }


    SetPosition(position, relativeSprite);
}

void PsplitSprite::SetBorderScale(sf::Vector2f scale)
{
    topLeft.setScale(scale.x, scale.y);
    top.setScale(this->scale.x, scale.y);
    topRight.setScale(scale.x, scale.y);

    left.setScale(scale.x, this->scale.y);
    right.setScale(scale.x, this->scale.y);

    bottomLeft.setScale(scale.x, scale.y);
    bottom.setScale(this->scale.x, scale.y);
    bottomRight.setScale(scale.x, scale.y);

    SetPosition(position, relativeSprite);
}


sf::Vector2f PsplitSprite::GetPixelOrigin() const
{
    return pixelOrigin;
}

void PsplitSprite::SetOrigin(sf::Vector2f origin, bool local)
{
    this->origin = origin;


    pixelOrigin.x = GetSize(local).x * origin.x;

    pixelOrigin.y = GetSize(local).y * origin.y;


    SetPosition(position, relativeSprite);
}


sf::Vector2f PsplitSprite::GetSize(bool local) const
{
    float width;

    float height;


    if (local)
    {
        width = left.getLocalBounds().width + sprite.getLocalBounds().width - right.getLocalBounds().width;

        height = top.getLocalBounds().height + sprite.getLocalBounds().height - bottom.getLocalBounds().height;

        return { width, height };
    }


    width = left.getGlobalBounds().width + sprite.getGlobalBounds().width + right.getGlobalBounds().width;

    height = top.getGlobalBounds().height + sprite.getGlobalBounds().height + bottom.getGlobalBounds().height;


    return { width, height };
}

sf::FloatRect PsplitSprite::GetBounds(bool local) const
{
    return sf::FloatRect(GetPixelPosition().x - GetPixelOrigin().x, GetPixelPosition().y - GetPixelOrigin().y, GetSize().x, GetSize().y);
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
