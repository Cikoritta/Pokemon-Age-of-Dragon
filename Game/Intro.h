#pragma once
#include <Pengine.h>

class Intro : public Pscene
{
    PanimatedSprite         background = PanimatedSprite(window, event, "Data/Textures/MainMenu/background.png", new sf::IntRect(0, 0, 1920, 1080));

    Peffect                 screenBrightening = Peffect(window, event, Effect::screenBrightening);

public:

    Intro() = default;

    Intro(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName) : Pscene(window, event, sceneName) {}


    void Start() override;

    void Update() override;

    void Events() override;

    void Draw() const override;
};
