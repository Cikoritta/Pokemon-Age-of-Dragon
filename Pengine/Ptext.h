#pragma once
#include <SFML/Graphics.hpp>
#include "Psprite.h"

class Ptext
{
    sf::RenderWindow*       window = nullptr;

    sf::Event*              event = nullptr;


    sf::Font                font;

    sf::Text                text;


    sf::Vector2f            position = { 0.0f, 0.0f };

    sf::Vector2f            scale = { 1.0f, 1.0f };

    sf::Vector2f            origin = { 0.0f, 0.0f };

public:

    Ptext() = default;

    Ptext(sf::RenderWindow* window, sf::Event* event, sf::String fontPath, sf::String text, sf::Color color);


    void                    SetFont(std::string fontPath);

    void                    SetText(std::string text);


    void                    SetColor(sf::Color color);


    void                    SetPosition(sf::Vector2f position, Psprite* sprite = nullptr);

    void                    SetPixelPosition(sf::Vector2f position);

    sf::Vector2f            GetPosition() const;

    sf::Vector2f            GetPixelPosition() const;


    void                    SetScale(sf::Vector2f scale);

    sf::Vector2f            GetScale() const;


    void                    SetOrigin(sf::Vector2f origin);

    void                    SetPixelOrigin(sf::Vector2f origin);

    sf::Vector2f            GetOrigin() const;

    sf::Vector2f            GetPixelOrigin() const;


    sf::FloatRect           GetBounds(bool local = false) const;

    sf::Vector2f            GetSize(bool local = false) const;


    sf::Text*               GetTamplate();

    void                    SetTamplate(sf::Text* textTamplate);


    void                    Draw() const;
};
