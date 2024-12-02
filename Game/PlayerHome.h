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

public:

    PlayerHome() = default;

    PlayerHome(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName) : Pscene(window, event, sceneName) {}


    void Start() override;

    void Update() override;

    void Events() override;

    void Draw() const override;
};

