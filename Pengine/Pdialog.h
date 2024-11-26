#pragma once
#include "Psprite.h"
#include "Pmusic.h"
#include "Ptext.h"
#include "Plang.h"

class Pdialog
{
    sf::RenderWindow*        window;

    sf::Event*               event;


    sf::Clock                clock;

    bool                     isClockStarted = false;


    bool                     isDialogEnd = false;

    bool                     isAllDialogEnd = false;


    sf::Uint16               countDialog = 0U;

    sf::Uint16               countEnter = 0U;


    std::wstring             currentString;

    sf::Uint16               currentLetter = 0U;

    sf::Uint16               currentDialog = 0U;


    sf::Sprite               dialogSprite;

    sf::Texture              dialogTexture;


    sf::Text                 dialogText;

    sf::Font                 dialogFont;


    sf::Sprite               dialogEnd;

    sf::Texture              dialogEndTexture;


    bool                     endPosition = false;


    sf::Vector2f            windowScale;


    std::vector<std::wstring> dialogStrings;

public:

    Pdialog() = default;

    Pdialog(sf::RenderWindow* window, sf::Event* event, sf::String texturePath, sf::String fontPath, sf::Color color, sf::Uint16 size);


    void Update(float timeInterval);

    void Events();


    void SetStringFile(const sf::String path, sf::Uint16 countDialog);

    void Draw() const;
};
