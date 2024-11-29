#pragma once
#include "Pengine.h"

class Pmap
{
    sf::RenderWindow* window;

    sf::Event* event;


    sf::Uint16 sizeTile = 0U;

    sf::Uint16 mapSize = 0U;

    std::wstring texturePath;

    sf::Texture texture;


    std::wstring map;


    std::vector<sf::Sprite*> tiles;

public:

    Pmap() = default;

    Pmap(sf::RenderWindow* window, sf::Event* event);


    void LoadMap(std::wstring pathMap);

    void Update();

    void Events();

    void Draw() const;
};
