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

    sf::Sprite*             GetSprite();


    sf::Vector2f            GetPosition() const;

    virtual sf::Vector2f    GetPixelPosition() const;

    virtual sf::Vector2f    GetRealPosition() const;

    virtual void            SetPosition(sf::Vector2f position, Psprite* RelativeSprite = nullptr);

    virtual void            SetPixelPosition(sf::Vector2f position);


    sf::Vector2f            GetScale() const;

    virtual void            SetScale(sf::Vector2f scale);


    sf::Vector2f            GetOrigin() const;

    virtual  sf::Vector2f   GetPixelOrigin() const;

    virtual void            SetOrigin(sf::Vector2f origin, bool local = false);


    virtual sf::Vector2f    GetSize(bool local = false) const;

    virtual sf::FloatRect   GetBounds(bool local = false) const;


    virtual void            Draw() const;
};