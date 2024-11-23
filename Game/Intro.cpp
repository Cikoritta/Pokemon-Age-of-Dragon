#include "Intro.h"

void Intro::Start()
{
    background.SetFrameTime(0.01f);
    background.SetScale({ 1.0f, 1.0f });
    background.SetLoop(true);

    screenBrightening.Start();
}

void Intro::Update()
{
    background.Animate(1920, 1U);

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
