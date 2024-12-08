#pragma once
#include <Pengine.h>
#include "Player.h"

class PlayerHouse2 : public Pscene
{
    Player player = Player(window, event);

    Pmap map = Pmap(window, event);

public:

    PlayerHouse2() = default;

    PlayerHouse2(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName) : Pscene(window, event, sceneName) {}


    void Start() override;

    void Update() override;

    void Events() override;

    void Draw() const override;
};
