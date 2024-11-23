#include "pch.h"
#include "Peffect.h"

Peffect::Peffect(sf::RenderWindow* window, sf::Event* event, Effect effect)
{
    this->window = window;

    this->event = event;

    this->effect = effect;
}

void Peffect::Start()
{
    switch (effect)
    {
    case screenDimming:

        screenDim.setSize(static_cast<sf::Vector2f>(window->getSize()));
        screenDim.setFillColor(sf::Color(0, 0, 0, 0));
        break;

    case screenBrightening:

        screenDim.setSize(static_cast<sf::Vector2f>(window->getSize()));
        screenDim.setFillColor(sf::Color(0, 0, 0, 255));
        break;

    }
}

void Peffect::Update(float timeInteval, sf::Uint16 interval)
{
    if (!effectEnd)
    {
        switch (effect)
        {
        case screenDimming:

            if (!isClockStart)
            {
                clock.restart();

                isClockStart = true;
            }

            if (clock.getElapsedTime().asSeconds() >= timeInteval)
            {
                if (screenDim.getFillColor().a < 255)
                {
                    screenDim.setFillColor(sf::Color(0, 0, 0, screenDim.getFillColor().a + interval));
                }
                else
                {
                    effectEnd = true;
                }
            }
            break;

        case screenBrightening:

            if (!isClockStart)
            {
                clock.restart();

                isClockStart = true;
            }

            if (clock.getElapsedTime().asSeconds() >= timeInteval)
            {
                if (screenDim.getFillColor().a > 0)
                {
                    screenDim.setFillColor(sf::Color(0, 0, 0, screenDim.getFillColor().a - interval));
                }
                else
                {
                    effectEnd = true;
                }
            }
            break;

        }
    }
}

void Peffect::Draw() const
{
    switch (effect)
    {
    case screenDimming:
        window->draw(screenDim);
        break;
    case screenBrightening:
        window->draw(screenDim);
        break;
    default:
        break;
    }
}

bool Peffect::IsEffectEnd() const
{
    return effectEnd;
}
