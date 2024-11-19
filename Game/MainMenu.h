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


    bool                    exitEvent = false;

    sf::IntRect             exitBackgroundRect[9] = { sf::IntRect(0, 0, 6, 6),
                                                      sf::IntRect(6, 0, 32, 6),
                                                      sf::IntRect(38, 0, 6, 6),
                                                      sf::IntRect(0, 6, 6, 32), 
                                                      sf::IntRect(6, 6, 32, 32), 
                                                      sf::IntRect(38, 6, 6, 32), 
                                                      sf::IntRect(0, 38, 6, 6), 
                                                      sf::IntRect(6, 38, 32, 6), 
                                                      sf::IntRect(38, 38, 6, 6) };

    PsplitSprite            exitBackground = PsplitSprite(window, event, "Data/Textures/MainMenu/exit_background.png", exitBackgroundRect);

    Ptext                   exitTitle = Ptext(&newGame, Plang::GetString(L"exit_title", L"MainMenu"));

    Ptext                   exitStay = Ptext(&newGame, Plang::GetString(L"exit_stay", L"MainMenu"));

    Ptext                   exitExit = Ptext(&newGame, Plang::GetString(L"exit_exit", L"MainMenu"));

    Psprite                 magikarp = Psprite(window, event, "Data/Textures/MainMenu/magikarp.png", new sf::IntRect(640, 0, 640, 640));


    bool                    settingEvent = false;

    Ptext                   settingTitle = Ptext(&newGame, Plang::GetString(L"setting_title", L"MainMenu"));

    Ptext                   settingExit = Ptext(&newGame, Plang::GetString(L"setting_exit", L"MainMenu"));

    Ptext                   settingApply = Ptext(&newGame, Plang::GetString(L"setting_apply", L"MainMenu"));

public:

    MainMenu() = default;

    MainMenu(Pwindow* window, sf::Event* event, const sf::String name) : Pscene(window, event, name) {}


    void                    BaseStart();

    void                    ExitStart();

    void                    SettingStart();


    void                    Start() override;


    void                    Update() override;


    void                    Events() override;


    void                    Draw() const override;
};