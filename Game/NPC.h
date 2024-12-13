#pragma once
#include <Pengine.h>
#include "Player.h"

class NPC
{
    static sf::Uint16 id;

    sf::RenderWindow* window;

    sf::Event* event;

    sf::Uint8 debug = std::stoi(Config::Read(L"Config.ini", L"debugMode"));


    PanimatedSprite* sprite;

    sf::String texturePath;

    sf::IntRect rect;


    sf::Vector2f speed;


    Player* player;


    Pcolader* colader;


    sf::Clock walkClock;

    sf::Vector2f position1;

    sf::Vector2f position2;

    bool endWalk = false;

    bool walkreturn = false;

    bool clockStart = false;

    bool isWalking = false;

    bool walkVector = false;

    bool isWalkingY = false;


    sf::IntRect previosRect;

public:

    NPC() = default;

    NPC(sf::RenderWindow* window, sf::Event* event, sf::String texturePath, sf::IntRect rect, Player* player);

    bool isDialog = false;


    void SetPosition(sf::Vector2f position);


    Pcolader* GetColader() const;

    PanimatedSprite* GetSprite();


    void ResetRect();


    void Walk(sf::Vector2f position1, sf::Vector2f position2, bool loop = false);

    void Dialog(bool* eventDialog, Pdialog* dialog);


    void Draw(bool draw = false) const;
};