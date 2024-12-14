#pragma once
#include <Pengine.h>
#include "Player.h"
#include "NPC.h"

class PlayerHouse2 : public Pscene
{
    Player player = Player(window, event);

    Pmap map = Pmap(window, event);

    Peffect EffetctBrightening = Peffect(window, event, Effect::screenBrightening);

    bool Brightening = false;

    bool toHouse = false;

    Peffect toHouseEffetct = Peffect(window, event, Effect::screenDimming);


    bool windowEvent = false;

    Pdialog windowDialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);

    bool Ice = false;

    Pdialog IceDialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);

    bool Cap = false;

    Pdialog CapDialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);


    NPC Mom = NPC(window, event, "Data/Textures/Entites/Mom/Mom.png", sf::IntRect(0, 0, 16, 23), &player);

    bool momDialog = false;

    bool momFirstDialog = std::stoi(Config::Read(L"Saves/Save.psave", L"momFirstDialog"));

    Pdialog MomDialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);


    Pmusic                  music = Pmusic("Data/Music/Oldale Town.flac");

public:

    PlayerHouse2() = default;

    PlayerHouse2(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName) : Pscene(window, event, sceneName) {}


    void Start() override;

    void Update() override;

    void Events() override;

    void Draw() const override;
};
