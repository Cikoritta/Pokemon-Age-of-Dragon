#pragma once
#include <Pengine.h>
#include "Player.h"

class PlayerHome : public Pscene
{
    Player player = Player(window, event);

    Psprite background = Psprite(window, event, "Data/Textures/Entites/Player/temp.jpg");

    Pmap map = Pmap(window, event);

public:

    PlayerHome() = default;

    PlayerHome(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName) : Pscene(window, event, sceneName) {}


    void Start() override;

    void Update() override;

    void Events() override;

    void Draw() const override;
};

