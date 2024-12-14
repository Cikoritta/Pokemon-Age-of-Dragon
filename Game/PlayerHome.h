#pragma once
#include <Pengine.h>
#include "Player.h"

class PlayerHome : public Pscene
{
    Player player = Player(window, event);

    Pmap map = Pmap(window, event);

    sf::Vector2f windowScale = sf::Vector2f(0.0f, 0.0f);


    bool TV = false;

    Pdialog tvDialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);

    bool clock = false;

    Pdialog clockDialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);

    bool magikarp = false;

    Pdialog magikarpDialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);

    bool computer = false;

    Pdialog computerDialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);


    Peffect EffetctBrighteningStart = Peffect(window, event, Effect::screenBrightening);

    bool startBrightening = false;


    bool toHouse = false;

    Peffect toHouseEffetct = Peffect(window, event, Effect::screenDimming);


    Peffect EffetctBrightening = Peffect(window, event, Effect::screenBrightening);

    bool Brightening = false;


    Pmusic                  music = Pmusic("Data/Music/Oldale Town.flac");

public:

    PlayerHome() = default;

    PlayerHome(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName) : Pscene(window, event, sceneName) {}


    void Start() override;

    void Update() override;

    void Events() override;

    void Draw() const override;
};

