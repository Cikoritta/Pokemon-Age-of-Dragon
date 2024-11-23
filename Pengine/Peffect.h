#pragma once
#include <SFML/Graphics.hpp>

enum Effect
{
    screenDimming = 1,
    screenBrightening = 2
};

class Peffect
{
    Effect                 effect;

    sf::RenderWindow*       window = nullptr;

    sf::Event*              event = nullptr;


    sf::Clock               clock;

    bool                    isClockStart = false;


    bool                    effectEnd = false;


    sf::RectangleShape      screenDim;

public:

    Peffect() = default;

    Peffect(sf::RenderWindow* window, sf::Event* event, Effect effect);


    void                    Start();

    void                    Update(float timeInteval = 0.0f, sf::Uint16 interval = 0U);

    void                    Draw() const;


    bool                    IsEffectEnd() const;
};
