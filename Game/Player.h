#pragma once
#include <Pengine.h>

class Player
{
    sf::RenderWindow* window;

    sf::Event* event;

    PanimatedSprite* playerSprite;


    sf::View camera;

    sf::Vector2f speed;

    sf::Vector2f playerOrigin;


    bool isWalking = false;

    bool isWalkingY = false;

public:

    Player() = default;

    Player(sf::RenderWindow* window, sf::Event* event);


    void Update();

    void Events();

    void Draw() const;
};
