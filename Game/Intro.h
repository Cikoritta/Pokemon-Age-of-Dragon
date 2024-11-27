#pragma once
#include <Pengine.h>

#include "Pdialog.h"


class Intro : public Pscene
{
    Peffect         screenBrightening = Peffect(window, event, Effect::screenBrightening);

    Psprite         background = Psprite(window, event, "Data/Textures/Intro/background.png", new sf::IntRect(0, 0, 1920, 1080));

    Pdialog         dialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);

    PanimatedSprite birch

public:

    Intro() = default;

    Intro(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName) : Pscene(window, event, sceneName) {}


    void Start() override;

    void Update() override;

    void Events() override;

    void Draw() const override;
};
