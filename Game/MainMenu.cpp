#include "MainMenu.h"

void MainMenu::Start()
{
    Pinput::SetWindow(window, event);

    background.SetFrameTime(0.01f);
    background.SetLoop(true);

    logo.SetFrameTime(0.01f);
    logo.SetLoop(true);

    newGame.SetPosition({ 0.5f, 0.5f });
}

void MainMenu::Update()
{
    background.Animate(1920, 1U);

    logo.SetOrigin({ 0.5f, 0.5f }, true);
    logo.SetPosition({ 0.5f, 0.3f });
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
}
