#pragma once
#include <Pengine.h>
#include "Player.h"
#include "SceneList.h"


class World : public Pscene
{
    Player player = Player(window, event);

    Pmap map = Pmap(window, event);


    bool appearanceEvent = false;

    Peffect appearanceEffect = Peffect(window, event, Effect::screenBrightening);

    bool leaveEvent = false;

    Peffect leaveEffect = Peffect(window, event, Effect::screenDimming);


    bool toPlayerHouse = false;

public:

    World() = default;

    World(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName) : Pscene(window, event, sceneName) {}


    void PlayerPositionFromArgs();


    void Start() override;

    void Update() override;

    void Events() override;

    void Draw() const override;
};
