#pragma once
#include <Pengine.h>
#include "Plang.h"

class MainMenu : public Pscene
{
    PanimatedSprite         background = PanimatedSprite(window, event, "Data/Textures/MainMenu/background.png", new sf::IntRect(0, 0, 1920, 1080));

    PanimatedSprite         logo = PanimatedSprite(window, event, "Data/Textures/MainMenu/logo.png", new sf::IntRect(0, 0, 828, 366));


    Ptext                   newGame = Ptext(window, event, "Data/Fonts/Upheaval Pro/UpheavalPro.ttf", Plang::GetString(L"new_game", L"MainMenu"), sf::Color::White);
    Ptext                   loadGame = Ptext(&newGame, Plang::GetString(L"load_game", L"MainMenu"));
    Ptext                   settingGame = Ptext(&newGame, Plang::GetString(L"setting_game", L"MainMenu"));
    Ptext                   exitGame = Ptext(&newGame, Plang::GetString(L"exit_game", L"MainMenu"));

public:

    MainMenu() = default;

    MainMenu(Pwindow* window, sf::Event* event, const sf::String name) : Pscene(window, event, name) {}


    void                    Start() override;


    void                    Update() override;


    void                    Events() override;


    void                    Draw() const override;
};