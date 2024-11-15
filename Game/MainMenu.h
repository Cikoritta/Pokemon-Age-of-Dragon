#pragma once
#include <Pengine.h>

class MainMenu : public Pscene
{
    PanimatedSprite         background = PanimatedSprite(window, event, "Data/Textures/MainMenu/background.png", new sf::IntRect(0, 0, 1920, 1080));

    PanimatedSprite         logo = PanimatedSprite(window, event, "Data/Textures/MainMenu/logo.png", new sf::IntRect(0, 0, 828, 366));


    Ptext                   newGame = Ptext(window, event, "Data/Fonts/Upheaval Pro/UpheavalPro.ttf", L"Новая игра", sf::Color::White);

public:

    MainMenu() = default;

    MainMenu(Pwindow* window, sf::Event* event, const sf::String name) : Pscene(window, event, name) {}


    void                    Start() override;


    void                    Update() override;


    void                    Events() override;


    void                    Draw() const override;
};