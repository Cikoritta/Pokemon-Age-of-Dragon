#include "pch.h"
#include "Peffect.h"

Peffect::Peffect(sf::RenderWindow* window, sf::Event* event, Effect effect)
{
    this->window = window;

    this->event = event;

    this->effect = effect;
}

void Peffect::Start(sf::View* camera)
{
    switch (effect)
    {
    case screenDimming:

        if (camera != nullptr)
        {
            screenDim.setPosition(window->mapPixelToCoords({ 0, 0 }));
        }
        screenDim.setSize(static_cast<sf::Vector2f>(window->getSize()));
        screenDim.setScale(10.0f, 10.0f);
        screenDim.setFillColor(sf::Color(0, 0, 0, 0));
        break;

    case screenBrightening:

        if (camera != nullptr)
        {
            screenDim.setPosition(window->mapPixelToCoords({ 0, 0 }));
        }
        screenDim.setSize(static_cast<sf::Vector2f>(window->getSize()));
        screenDim.setScale(10.0f, 10.0f);
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
    }
}

void Peffect::Reset()
{
    switch (effect)
    {
    case screenDimming:

        screenDim.setFillColor(sf::Color(0U, 0U, 0U, 0U));

        isClockStart = false;
        effectEnd = false;
        break;

    case screenBrightening:

        screenDim.setFillColor(sf::Color(0U, 0U, 0U, 255U));

        isClockStart = false;
        effectEnd = false;
        break;
    }
}

bool Peffect::IsEffectEnd() const
{
    return effectEnd;
}
