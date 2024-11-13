#pragma once
#include <SFML/Graphics.hpp>

class Psprite
{
protected:

    sf::RenderWindow*       window = nullptr;

    sf::Event*              event = nullptr;


    sf::Sprite              sprite;

    sf::Texture             texture;

    sf::IntRect             textureRect = sf::IntRect(0, 0, 0, 0);


    sf::Vector2f            position = sf::Vector2f(0.0f, 0.0f);

    sf::Vector2f            scale = sf::Vector2f(1.0f, 1.0f);

    sf::Vector2f            origin = sf::Vector2f(0.0f, 0.0f);


    sf::Vector2f            windowScale = sf::Vector2f(1.0f, 1.0f);

public:

    Psprite() = default;

    Psprite(sf::RenderWindow* window, sf::Event* event, sf::String texturePath = "none", sf::IntRect* textureRect = nullptr);


    virtual void            setTexture(sf::String texturePath, sf::IntRect* textureRect = nullptr);


    sf::Vector2f            GetPosition() const;

    virtual sf::Vector2u    GetPixelPosition() const;

    virtual sf::Vector2u    GetRealPosition() const;

    virtual void            SetPosition(float x, float y, Psprite* RelativeSprite = nullptr);

    virtual void            SetPixelPosition(sf::Uint16 x, sf::Uint16 y);


    sf::Vector2f            GetScale() const;

    virtual void            SetScale(float x, float y);


    sf::Vector2f            GetOrigin() const;

    virtual  sf::Vector2u   GetPixelOrigin() const;

    virtual void            SetOrigin(float x, float y, bool local = false);


    virtual sf::Vector2u    GetSize(bool local = false) const;

    virtual sf::IntRect     GetBounds(bool local = false) const;


    virtual void            Draw() const;
};