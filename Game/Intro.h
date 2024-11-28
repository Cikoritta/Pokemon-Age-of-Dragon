#pragma once
#include <Pengine.h>

class Intro : public Pscene
{
    Peffect         screenBrightening = Peffect(window, event, Effect::screenBrightening);

    Pmusic          music = Pmusic("Data/Music/Professor Birch's Laboratory.flac");

    Psprite         background = Psprite(window, event, "Data/Textures/Intro/background.png", new sf::IntRect(0, 0, 1920, 1080));

    Pdialog         dialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);

    PanimatedSprite birch = PanimatedSprite(window, event, "Data/Textures/Intro/birch.png", new sf::IntRect(0, 0, 90, 69));

    bool    birchAnimation = false;


    bool    nameEntered = false;

    bool    nameEnteredTrue = false;

    Peffect         screenDimmingName = Peffect(window, event, Effect::screenDimming);

    Peffect         screenBrighteningName = Peffect(window, event, Effect::screenBrightening);


    Psprite         nameEnterBackground = Psprite(window, event, "Data/Textures/Intro/name_enter_background.png", new sf::IntRect(0, 0, 1920, 1080));

    Pdialog         nameEnterDialog = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);

    sf::IntRect     nameEnterBoxRect[9] = { sf::IntRect(0, 0, 6, 6),
                                                      sf::IntRect(6, 0, 32, 6),
                                                      sf::IntRect(38, 0, 6, 6),
                                                      sf::IntRect(0, 6, 6, 32),
                                                      sf::IntRect(6, 6, 32, 32),
                                                      sf::IntRect(38, 6, 6, 32),
                                                      sf::IntRect(0, 38, 6, 6),
                                                      sf::IntRect(6, 38, 32, 6),
                                                      sf::IntRect(38, 38, 6, 6) };

    PsplitSprite    nameEnterBox = PsplitSprite(window, event, "Data/Textures/Intro/name_box.png", nameEnterBoxRect);

    Ptext           nameEnterTitle = Ptext(window, event, "Data/Fonts/Upheaval Pro/UpheavalPro.ttf", Plang::GetString(L"name_title", L"Intro"), sf::Color::White);

    PanimatedSprite nameEnterLine = PanimatedSprite(window, event, "Data/Textures/Intro/name_box_line.png", new sf::IntRect(0, 0, 279, 28));

    std::wstring    name;

    Ptext           nameText = Ptext(window, event, "Data/Fonts/Retron2000/Retron2000.ttf", L"", sf::Color(96U, 96U, 96U));


    bool birchDialogTwo = false;

    Peffect         screenDimmingBirch = Peffect(window, event, Effect::screenDimming);

    Peffect         screenBrighteningBirch = Peffect(window, event, Effect::screenBrightening);

    Pdialog         dialog2 = Pdialog(window, event, "Data/Textures/Other/Dialog/text_box.png", "Data/Fonts/Retron2000/Retron2000.ttf", sf::Color(96U, 96U, 96U), 25U);

    Peffect         endScene = Peffect(window, event, Effect::screenDimming);

public:

    Intro() = default;

    Intro(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName) : Pscene(window, event, sceneName) {}


    void Start() override;

    void Update() override;

    void Events() override;

    void Draw() const override;
};
