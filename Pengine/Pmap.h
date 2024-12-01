#pragma once
#include "Pengine.h"

class Pmap
{
    sf::RenderWindow* window = nullptr;

    sf::Event* event = nullptr;

    sf::Vector2f windowScale = { std::stof(Config::Read(L"Config.ini", L"windowScaleWidth")), std::stof(Config::Read(L"Config.ini", L"windowScaleHeight")) };


    std::wstring pathMap;
    std::string texturePath;


    sf::Vector2f sizeTile = { 0.0f, 0.0f };

    sf::Vector2f originalSizeTile = { 0.0f, 0.0f };

    sf::Uint16 countTile = 0U;


    std::vector<Psprite*> tiles;

    std::vector<Pcolader*> coladers;

    std::vector<Pcolader*> solidColaders;


    sf::Uint8 debug = std::stoi(Config::Read(L"Config.ini", L"debugMode"));


    sf::Uint8 editor = std::stoi(Config::Read(L"Config.ini", L"editorMode"));

    Ptext* editorRect = nullptr;

    std::wstring editorRectString;

    Ptext* editorMode = nullptr;

    sf::Uint8 editorModeText = 0U;

    Ptext* editorSolid = nullptr;

    std::wstring editorSolidText;

public:

    Pmap() = default;

    Pmap(sf::RenderWindow* window, sf::Event* event);


    void LoadMap(std::wstring pathMap, std::string texturePath);


    void SetScale(sf::Vector2f scale);


    std::vector<Pcolader*> GetColaders() const;

    std::vector<Pcolader*> GetSolidColaders() const;


    void Update();

    void Events();

    void Draw() const;
};
