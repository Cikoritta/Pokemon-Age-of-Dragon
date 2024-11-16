#include "MainMenu.h"

void MainMenu::Start()
{
    Pinput::SetWindow(window, event);

    background.SetFrameTime(0.01f);
    background.SetLoop(true);

    logo.SetFrameTime(0.01f);
    logo.SetOrigin({ 0.5f, 0.5f }, true);
    logo.SetPosition({ 0.495f, 0.25f });
    logo.SetLoop(true);

    newGame.SetPosition({ 0.5f, 0.5f });
    newGame.SetOrigin({ 0.5f, 0.5f }, true);
    newGame.GetTamplate()->setCharacterSize(45U);
    newGame.GetTamplate()->setOutlineThickness(5.0f);
    newGame.GetTamplate()->setOutlineColor(sf::Color::Black);

    loadGame.SetTamplate(newGame.GetTamplate());
    loadGame.SetOrigin({ 0.5f, 0.5f }, true);
    loadGame.SetPosition({ 0.5f, 0.562f });

    settingGame.SetTamplate(newGame.GetTamplate());
    settingGame.SetOrigin({ 0.5f, 0.5f }, true);
    settingGame.SetPosition({ 0.5f, 0.62f });

    exitGame.SetTamplate(newGame.GetTamplate());
    exitGame.SetOrigin({ 0.5f, 0.5f }, true);
    exitGame.SetPosition({ 0.5f, 0.695f });
}

void MainMenu::Update()
{
    background.Animate(1920, 1U);

    logo.ScaleAnimate(0.9f, 1.1f, 0.002f);
}

void MainMenu::Events()
{
    if (Pinput::IsMouseCollision(&logo))
    {
        if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
        {
            logo.ScaleAnimateReset();
        }
    }
}

void MainMenu::Draw() const
{
    background.Draw();
    logo.Draw();

    newGame.Draw();
    loadGame.Draw();
    settingGame.Draw();
    exitGame.Draw();
}
