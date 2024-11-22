#pragma once
#include <SFML/Graphics.hpp>
#include "Pcolader.h"
#include "Ptext.h"

class Pinput
{
    static sf::RenderWindow*        window;

    static sf::Event*               event;

public:

    Pinput() = default;

    Pinput(sf::Event* event, sf::RenderWindow* window);


    static void                     SetWindow(sf::RenderWindow* window, sf::Event* event);
    

    static bool                     IsMouseCollision(Pcolader* colader);

    static bool                     IsMouseCollision(Psprite* sprite);

    static bool                     IsMouseCollision(Ptext* text);


    static bool                     IsKeyPressed(sf::Keyboard::Key key);

    static bool                     IsKeyReleased(sf::Keyboard::Key key);


    static bool                     IsMouseButtonPressed(sf::Mouse::Button button);

    static bool                     IsMouseUpdatePressed(sf::Mouse::Button button);

    static bool                     IsMouseButtonReleased(sf::Mouse::Button button);

    static bool                     IsMouseScrolled(bool down = false);
};
