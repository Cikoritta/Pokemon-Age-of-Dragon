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


    Pcolader* colader;

    std::vector<Pcolader*> solidColader;

    sf::Uint8 debug = std::stoi(Config::Read(L"Config.ini", L"debugMode"));

    bool isWalking = false;

    bool isWalkingY = false;

public:

    Player() = default;

    Player(sf::RenderWindow* window, sf::Event* event);


    Pcolader* GetColader() const;

    PanimatedSprite* GetSprite();

    sf::Vector2f* GetPlayerOrigin();


    void Wallking(bool state = false);


    void Collision(std::vector<Pcolader*> solidColader, bool checkVisible = false, sf::View camera = sf::View());

    void Update();

    void Events();

    void Draw() const;
};
