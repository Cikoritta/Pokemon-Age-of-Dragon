#include "pch.h"
#include "Psprite.h"
#include "EazyConfig.h"

Psprite::Psprite(sf::RenderWindow* window, sf::Event* event, sf::String texturePath, sf::IntRect* textureRect)
{
    this->window = window;

    this->event = event;
    

    if (texturePath != "none")
    {
        texture.loadFromFile(texturePath);

        sprite.setTexture(texture);

        if (textureRect != nullptr)
        {
            sprite.setTextureRect(*textureRect);

            this->textureRect = *textureRect;

            delete textureRect;
        }
        else
        {
            this->textureRect = sf::IntRect(0, 0, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y);
        }
    }


    windowScale.x = std::stof(Config::Read(L"windowScaleWidth"));

    windowScale.y = std::stof(Config::Read(L"windowScaleHeight"));

    SetScale(scale.x, scale.y);
}


void Psprite::setTexture(sf::String texturePath, sf::IntRect* textureRect)
{
    texture.loadFromFile(texturePath);

    sprite.setTexture(texture);

    if (textureRect != nullptr)
    {
        sprite.setTextureRect(*textureRect);

        this->textureRect = *textureRect;

        delete textureRect;
    }
    else
    {
        this->textureRect = sf::IntRect(0, 0, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y);
    }
}


sf::Vector2f Psprite::GetPosition() const
{
    return position;
}

sf::Vector2u Psprite::GetPixelPosition() const
{
    return (sf::Vector2u)sprite.getPosition();
}

sf::Vector2u Psprite::GetRealPosition() const
{
    return sf::Vector2u((sf::Uint16)(sprite.getPosition().x - sprite.getOrigin().x), (sf::Uint16)(sprite.getPosition().y - sprite.getOrigin().y));
}

void Psprite::SetPosition(float x, float y, Psprite* RelativeSprite)
{
    position.x = x;

    position.y = y;

    if (RelativeSprite != nullptr)
    {
        sprite.setPosition((RelativeSprite->GetPixelPosition().x + (RelativeSprite->GetSize().x * x)) - RelativeSprite->GetPixelOrigin().x, (RelativeSprite->GetPixelPosition().y + (RelativeSprite->GetSize().y * y)) - RelativeSprite->GetPixelOrigin().y);
    }
    else
    {
        sprite.setPosition(window->getSize().x * x, window->getSize().y * y);
    }
}

void Psprite::SetPixelPosition(sf::Uint16 x, sf::Uint16 y)
{
    sprite.setPosition(x, y);
}


sf::Vector2f Psprite::GetScale() const
{
    return scale;
}

void Psprite::SetScale(float x, float y)
{
    scale.x = x;

    scale.y = y;

    sprite.setScale(windowScale.x * x, windowScale.y * y);
}


sf::Vector2f Psprite::GetOrigin() const
{
    return origin;
}

sf::Vector2u Psprite::GetPixelOrigin() const
{
    return (sf::Vector2u)sprite.getOrigin();
}

void Psprite::SetOrigin(float x, float y, bool local)
{
    origin.x = x;

    origin.y = y;

    sprite.setOrigin(GetSize(local).x * x, GetSize(local).y * y);
}


sf::Vector2u Psprite::GetSize(bool local) const
{
    if (local)
    {
        return (sf::Vector2u)sprite.getLocalBounds().getSize();
    }

    return (sf::Vector2u)sprite.getGlobalBounds().getSize();
}

sf::IntRect Psprite::GetBounds(bool local) const
{
    if (local)
    {
        return (sf::IntRect)sprite.getLocalBounds();
    }

    return (sf::IntRect)sprite.getGlobalBounds();
}


void Psprite::Draw() const
{
    window->draw(sprite);
}
