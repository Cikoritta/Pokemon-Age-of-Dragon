#include "pch.h"
#include "Pinput.h"

sf::RenderWindow* Pinput::window = nullptr;
sf::Event* Pinput::event = nullptr;


Pinput::Pinput(sf::Event* event, sf::RenderWindow* window)
{
    this->window = window;

    this->event = event;
}


void Pinput::SetWindow(sf::RenderWindow* window_, sf::Event* event_)
{
    window = window_;

    event = event_;
}


bool Pinput::IsMouseCollision(Pcolader* colader)
{
    if (colader->GetBounds().contains(sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(*window).x), static_cast<float>(sf::Mouse::getPosition(*window).y))))
    {
        return true;
    }

    return false;
}

bool Pinput::IsMouseCollision(Psprite* sprite)
{
    if (sprite->GetBounds().contains(sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(*window).x), static_cast<float>(sf::Mouse::getPosition(*window).y))))
    {
        return true;
    }

    return false;
}

bool Pinput::IsMouseCollision(Ptext* text)
{
    if (text->GetBounds().contains(sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(*window).x), static_cast<float>(sf::Mouse::getPosition(*window).y))))
    {
        return true;
    }

    return false;
}


bool Pinput::IsKeyPressed(sf::Keyboard::Key key)
{
    if (event->type == event->KeyPressed && event->key.code == key)
    {
        return true;
    }

    return false;
}

bool Pinput::IsKeyReleased(sf::Keyboard::Key key)
{
    if (event->type == event->KeyReleased && event->key.code == key)
    {
        return true;
    }

    return false;
}

void Pinput::IsKeyEntered(std::wstring* string, sf::Uint16 max)
{
    if (event->type == event->TextEntered)
    {
        if (string->length() < max)
        {
            if ((event->text.unicode >= 41 && event->text.unicode <= 90) || (event->text.unicode >= 97 && event->text.unicode <= 122))
            {
                *string += static_cast<wchar_t>(event->text.unicode);
            }

            if ((event->text.unicode >= 1040 && event->text.unicode <= 1103))
            {
                *string += static_cast<wchar_t>(event->text.unicode);
            }
        }

        if (event->text.unicode == 8 && string->length() > 0)
        {
            *string = string->substr(0, string->length() - 1U);
        }
    }
}


bool Pinput::IsMouseButtonPressed(sf::Mouse::Button button)
{
    if (event->type == event->MouseButtonPressed && event->mouseButton.button == button)
    {
        return true;
    }

    return false;
}

bool Pinput::IsMouseUpdatePressed(sf::Mouse::Button button)
{
    return sf::Mouse::isButtonPressed(button);
}

bool Pinput::IsMouseButtonReleased(sf::Mouse::Button button)
{
    if (event->type == event->MouseButtonReleased && event->mouseButton.button == button)
    {
        return true;
    }

    return false;
}

bool Pinput::IsMouseScrolled(bool down)
{
    if (event->type == event->MouseWheelScrolled)
    {
        if (!down)
        {
            if (event->mouseWheelScroll.delta > 0)
            {
                return true;
            }
        }
        else
        {
            if (event->mouseWheelScroll.delta < 0)
            {
                return true;
            }
        }
    }

    return false;
}
