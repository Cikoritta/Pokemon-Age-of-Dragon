#include "pch.h"
#include "Ptext.h"
#include <EazyConfig.h>

Ptext::Ptext(sf::RenderWindow* window, sf::Event* event, sf::String fontPath, sf::String text, sf::Color color)
{
    this->window = window;
    this->event = event;

    this->SetFont(fontPath);
    this->SetText(text);
    this->SetColor(color);

    windowScale = { stof(Config::Read(L"Config.ini", L"windowScaleWidth")), stof(Config::Read(L"Config.ini", L"windowScaleHeight")) };

    SetScale({ 1.0f, 1.0f });
}

Ptext::Ptext(Ptext* Ptext, sf::String text)
{
    this->window = Ptext->window;
    this->event = Ptext->event;

    this->font = *Ptext->GetTamplate()->getFont();
    this->text.setFont(font);

    windowScale = { stof(Config::Read(L"Config.ini", L"windowScaleWidth")), stof(Config::Read(L"Config.ini", L"windowScaleHeight")) };

    SetScale({ 1.0f, 1.0f });

    SetText(text);
}


void Ptext::SetFont(std::string fontPath)
{
    font.loadFromFile(fontPath);

    text.setFont(font);

    windowScale = { stof(Config::Read(L"Config.ini", L"windowScaleWidth")), stof(Config::Read(L"Config.ini", L"windowScaleHeight")) };

    SetScale({ 1.0f, 1.0f });
}

void Ptext::SetText(sf::String text)
{
    this->text.setString(text);
}


void Ptext::SetColor(sf::Color color)
{
    text.setFillColor(color);
}


void Ptext::SetPosition(sf::Vector2f position, Psprite* sprite)
{
    this->position = position;

    if (sprite != nullptr)
    {
        text.setPosition({ floor(sprite->GetPixelPosition().x + (sprite->GetSize(true).x * position.x) - sprite->GetPixelOrigin().x), floor(sprite->GetPixelPosition().y + (sprite->GetSize(true).y * position.y) - sprite->GetPixelOrigin().y - text.getLocalBounds().top) });
    
        return;
    }

    text.setPosition({ floor(window->getSize().x * position.x), floor((window->getSize().y * position.y) - text.getLocalBounds().top) });
}

void Ptext::SetPixelPosition(sf::Vector2f position)
{
    text.setPosition(position.x, position.y - text.getLocalBounds().top);

    this->position = { position.x / window->getSize().x, position.y / window->getSize().y };
}

sf::Vector2f Ptext::GetPosition() const
{
    return position;
}

sf::Vector2f Ptext::GetPixelPosition() const
{
    return text.getPosition();
}


void Ptext::SetScale(sf::Vector2f scale)
{
    this->scale = scale;

    text.setScale({ scale.x * windowScale.x, scale.y * windowScale.y });
}

sf::Vector2f Ptext::GetScale() const
{
    return scale;
}


void Ptext::SetOrigin(sf::Vector2f origin, bool local)
{
    this->origin = origin;

    text.setOrigin({ GetSize(local).x * origin.x, GetSize(local).y * origin.y });
}

void Ptext::SetPixelOrigin(sf::Vector2f origin)
{
    text.setOrigin(origin);

    this->origin = { origin.x / GetSize().x, origin.y / GetSize().y };
}

sf::Vector2f Ptext::GetOrigin() const
{
    return origin;
}

sf::Vector2f Ptext::GetPixelOrigin() const
{
    return text.getOrigin();
}


sf::FloatRect Ptext::GetBounds(bool local) const
{
    if (local)
    {
        return text.getLocalBounds();
    }

    return text.getGlobalBounds();
}

sf::Vector2f Ptext::GetSize(bool local) const
{
    if (local)
    {
        return text.getLocalBounds().getSize();
    }

    return text.getGlobalBounds().getSize();
}


sf::Text* Ptext::GetTamplate()
{
    return &text;
}

void Ptext::SetTamplate(sf::Text* textTamplate)
{
    text.setCharacterSize(textTamplate->getCharacterSize());
    text.setFont(*textTamplate->getFont());
    text.setFillColor(textTamplate->getFillColor());
    text.setOutlineColor(textTamplate->getOutlineColor());
    text.setOutlineThickness(textTamplate->getOutlineThickness());
    text.setStyle(textTamplate->getStyle());
}


void Ptext::Draw() const
{
    window->draw(text);
}
