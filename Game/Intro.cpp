#include "Intro.h"

void Intro::Start()
{
    background.SetScale({ 1.0f, 1.0f });

    screenBrightening.Start();
}

void Intro::Update()
{
    if (!screenBrightening.IsEffectEnd())
    {
        screenBrightening.Update(0.1f, 3U);
    }
}

void Intro::Events()
{
}

void Intro::Draw() const
{
    background.Draw();

    if (!screenBrightening.IsEffectEnd())
    {
        screenBrightening.Draw();
    }
}
