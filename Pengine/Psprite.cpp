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
        }
        else
        {
            this->textureRect = sf::IntRect(0, 0, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y);
        }
    }


    windowScale.x = std::stof(Config::Read(L"windowScaleWidth"));

    windowScale.y = std::stof(Config::Read(L"windowScaleHeight"));

    SetScale({1.0f, 1.0f});
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

sf::Sprite* Psprite::GetSprite()
{
    return &sprite;
}


sf::Vector2f Psprite::GetPosition() const
{
    return position;
}

sf::Vector2f Psprite::GetPixelPosition() const
{
    return sprite.getPosition();
}

sf::Vector2f Psprite::GetRealPosition() const
{
    return { sprite.getPosition().x - sprite.getOrigin().x, sprite.getPosition().y - sprite.getOrigin().y };
}

void Psprite::SetPosition(sf::Vector2f position, Psprite* RelativeSprite)
{
    this->position = position;

    if (RelativeSprite != nullptr)
    {
        sprite.setPosition((RelativeSprite->GetPixelPosition().x + (RelativeSprite->GetSize().x * position.x)) - RelativeSprite->GetPixelOrigin().x, (RelativeSprite->GetPixelPosition().y + (RelativeSprite->GetSize().y * position.y)) - RelativeSprite->GetPixelOrigin().y);
    }
    else
    {
        sprite.setPosition(window->getSize().x * position.x, window->getSize().y * position.y);
    }

    SetScale(scale);
}

void Psprite::SetPixelPosition(sf::Vector2f position)
{
    sprite.setPosition(position);

    this->position = { position.x / window->getSize().x, position.y / window->getSize().y };

    SetScale(scale);
}


sf::Vector2f Psprite::GetScale() const
{
    return scale;
}

void Psprite::SetScale(sf::Vector2f scale)
{
    this->scale = scale;

    windowScale.x = std::stof(Config::Read(L"windowScaleWidth"));

    windowScale.y = std::stof(Config::Read(L"windowScaleHeight"));

    sprite.setScale(windowScale.x * scale.x, windowScale.y * scale.y);
}


sf::Vector2f Psprite::GetOrigin() const
{
    return origin;
}

sf::Vector2f Psprite::GetPixelOrigin() const
{
    return sprite.getOrigin();
}

void Psprite::SetOrigin(sf::Vector2f origin, bool local)
{
    this->origin = origin;

    sprite.setOrigin(GetSize(local).x * origin.x, GetSize(local).y * origin.y);
}


sf::Vector2f Psprite::GetSize(bool local) const
{
    if (local)
    {
        return sprite.getLocalBounds().getSize();
    }

    return sprite.getGlobalBounds().getSize();
}

sf::FloatRect Psprite::GetBounds(bool local) const
{
    if (local)
    {
        return sprite.getLocalBounds();
    }

    return sprite.getGlobalBounds();
}


void Psprite::Draw() const
{
    window->draw(sprite);
}
