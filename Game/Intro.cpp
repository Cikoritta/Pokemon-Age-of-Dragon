#include "Intro.h"

void Intro::Start()
{
    background.SetScale({ 1.0f, 1.0f });

    dialog.SetOrigin({ 0.5f, 1.0f });
    dialog.SetScale({ 1.5f, 1.5f });
    dialog.SetPosition({ 0.5f, 1.0f });
    dialog.SetStringFile("Data/Lang/Intro/Birch", 5U);

    screenBrightening.Start();
}

void Intro::Update()
{
    if (!screenBrightening.IsEffectEnd())
    {
        screenBrightening.Update(0.1f, 3U);
    }
    else
    {
        dialog.Update(0.05f);
    }
}

void Intro::Events()
{
    dialog.Events();
}

void Intro::Draw() const
{
    background.Draw();
    dialog.Draw();

    if (!screenBrightening.IsEffectEnd())
    {
        screenBrightening.Draw();
    }
}
