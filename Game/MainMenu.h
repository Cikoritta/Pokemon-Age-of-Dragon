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

    Ptext                   settingTitleResolution = Ptext(&newGame, Plang::GetString(L"setting_resolution", L"MainMenu"));

    Ptext                   settingResolution = Ptext(&newGame, std::to_wstring(window->getSize().x) + L"x"  + std::to_wstring(window->getSize().y));

    Ptext                   settingTitleStyle = Ptext(&newGame, Plang::GetString(L"setting_style_title", L"MainMenu"));

    Ptext                   settingStyle = Ptext(&newGame, Plang::GetString(L"setting_style_fullscreen", L"MainMenu"));

    Ptext                   settingTitleMusic = Ptext(&newGame, Plang::GetString(L"setting_music_title", L"MainMenu"));

    Ptext                   settingTitleEffect = Ptext(&newGame, Plang::GetString(L"setting_effect_title", L"MainMenu"));

    Ptext                   settingMusic = Ptext(&newGame, Config::Read(L"Sound.ini", L"Music"));

    Ptext                   settingEffect = Ptext(&newGame, Config::Read(L"Sound.ini", L"Effect"));


    Pmusic                  music = Pmusic("Data/Music/Route 101.flac");

    Psound                  buttonSound = Psound("Data/Effect/Select.flac");

    Psound                  magikarpSound = Psound("Data/Effect/Magikarp.flac");


    bool                    warningResetEvent = false;

    Ptext                   warning = Ptext(&newGame, Plang::GetString(L"warning", L"MainMenu"));

    Ptext                   warningOk = Ptext(&newGame, Plang::GetString(L"warning_ok", L"MainMenu"));

    Ptext                   warningCancel = Ptext(&newGame, Plang::GetString(L"warning_cancel", L"MainMenu"));

    Ptext                   warningAccept = Ptext(&newGame, Plang::GetString(L"warning_accept", L"MainMenu"));

    Ptext                   warningReset = Ptext(window, event, "Data/Fonts/Retron2000/Retron2000.ttf", Plang::GetString(L"warning_reset", L"MainMenu"), sf::Color(96, 96, 96));


    Ptext                   language = Ptext(&newGame, Config::Read(L"Config.ini", L"lang"));

public:

    MainMenu() = default;

    MainMenu(Pwindow* window, sf::Event* event, const sf::String name) : Pscene(window, event, name) {}


    void                    BaseStart();

    void                    ExitStart();

    void                    SettingStart();

    void                    WarningResetStart();


    void                    SetTempSetting();


    void                    Start() override;


    void                    Update() override;


    void                    Events() override;


    void                    Draw() const override;
};