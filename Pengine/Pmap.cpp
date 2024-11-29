#include "pch.h"
#include "Pmap.h"

Pmap::Pmap(sf::RenderWindow* window, sf::Event* event)
{
    this->window = window;

    this->event = event;
}

void Pmap::LoadMap(std::wstring pathMap)
{
    sizeTile = std::stoi(Config::Read(pathMap, L"sizeTile"));

    mapSize = std::stoi(Config::Read(pathMap, L"mapSize"));

    texturePath = Config::Read(pathMap, L"texturePath");

    map = Config::Read(pathMap, L"mapBody");

    texture.loadFromFile(std::string(texturePath.begin(), texturePath.end()));

    sf::Uint16 y = 0U;

    for (sf::Uint16 i = 0; i < mapSize; i + 2)
    {
        if (map.substr(i, 1) != L",")
        {
            sf::IntRect tileRect = sf::IntRect(std::stoi((map.substr(i, 1))) * sizeTile, std::stoi((map.substr(i + 1, 1))) * sizeTile, sizeTile, sizeTile);

            sf::Sprite* tile = new sf::Sprite(texture, tileRect);

            tile->setPosition(0 + sizeTile, y);

            tiles.push_back(tile);
        }
        else
        {
            y++;
        }
    }
}

void Pmap::Update()
{

}

void Pmap::Events()
{

}

void Pmap::Draw() const
{
    for (sf::Uint16 i = 0; i < tiles.size(); i++)
    {
        window->draw(*tiles[i]);
    }
}
