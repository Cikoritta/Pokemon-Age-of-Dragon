#include "Intro.h"
#include "PlayerHome.h"
#include "SceneList.h"

void Intro::Start()
{
    background.SetScale({ 1.0f, 1.0f });

    window->setMouseCursorVisible(false);

    nameEnterBackground.SetScale({ 1.0f, 1.0f });

    dialog.SetOrigin({ 0.5f, 1.0f });
    dialog.SetScale({ 1.5f, 1.5f });
    dialog.SetPosition({ 0.5f, 1.0f });
    dialog.SetStringFile("Data/Lang/Intro/Birch", 9U);

    dialog2.SetOrigin({ 0.5f, 1.0f });
    dialog2.SetScale({ 1.5f, 1.5f });
    dialog2.SetPosition({ 0.5f, 1.0f });

    nameEnterDialog.SetOrigin({ 0.5f, 1.0f });
    nameEnterDialog.SetScale({ 1.5f, 1.5f });
    nameEnterDialog.SetPosition({ 0.5f, 1.0f });
    nameEnterDialog.StaticString("Data/Lang/Intro/Birch", 10U);

    birch.SetScale({ 5.0f, 5.0f });
    birch.SetPosition({ 0.35f, 0.3f }); 
    birch.SetFrameTime(0.05f);

    screenBrightening.Start();

    screenDimmingName.Start();
    screenBrighteningName.Start();

    nameEnterBox.SetOrigin({ 0.5f, 0.5f });
    nameEnterBox.SetPosition({ 0.5f, 0.4f });
    nameEnterBox.SetSmartScale({ 18.0f, 10.0f });
    nameEnterBox.SetBorderScale({ 6.0f, 6.0f });

    nameEnterTitle.GetTamplate()->setCharacterSize(45U);
    nameEnterTitle.GetTamplate()->setOutlineThickness(5.0f);
    nameEnterTitle.GetTamplate()->setOutlineColor(sf::Color::Black);
    nameEnterTitle.SetOrigin({ 0.5f, 0.5f }, true);
    nameEnterTitle.SetPosition({ 0.5f, 0.1f }, &nameEnterBox);

    nameEnterLine.SetScale({ 1.5f, 1.5f });
    nameEnterLine.SetOrigin({ 0.575f, 0.5f }, true);
    nameEnterLine.SetPosition({ 0.5f, 0.6f }, &nameEnterBox);
    nameEnterLine.SetFrameTime(0.3f);
    nameEnterLine.SetLoop(true);

    nameText.GetTamplate()->setCharacterSize(25U);
    nameText.SetOrigin({ 0.5f, 0.5f }, true);
    nameText.SetPosition({ 0.5f, 0.55f }, &nameEnterBox);
    nameText.SetScale({ 1.5f, 1.5f });

    screenDimmingBirch.Start();
    screenBrighteningBirch.Start();

    endScene.Start();

    music.PlayMusic(true);
}

void Intro::Update()
{
    if (!screenBrightening.IsEffectEnd())
    {
        screenBrightening.Update(0.1f, 3U);
    }
    else
    {
        if (dialog.IsDialogEnd())
        {
            nameEntered = true;
        }

        if (nameEntered && !screenDimmingName.IsEffectEnd())
        {
            screenDimmingName.Update(0.1f, 3U);
        }
        else if (nameEntered && !screenBrighteningName.IsEffectEnd())
        {
            nameEnteredTrue = true;

            screenBrighteningName.Update(0.1f, 3U);
        }

        if (!nameEntered)
        {
            dialog.Update(0.05f);
        }

        if (birchAnimation || dialog.GetCurrentDialog() == 4)
        {
            birchAnimation = true;

            birch.Animate(90, 90);
        }

        if (nameEnteredTrue)
        {
            nameEnterLine.Animate(279, 279);
        }
    }

    if (birchDialogTwo)
    {
        if (!screenDimmingBirch.IsEffectEnd())
        {
            screenDimmingBirch.Update(0.1f, 3U);
        }

        if (screenDimmingBirch.IsEffectEnd() && !screenBrighteningBirch.IsEffectEnd())
        {
            screenBrighteningBirch.Update(0.1f, 3U);
        }

        if (screenDimmingBirch.IsEffectEnd() && screenBrighteningBirch.IsEffectEnd())
        {
            dialog2.Update(0.05f);
        }

        if (dialog2.IsDialogEnd())
        {
            endScene.Update(0.1f, 3U);
        }

        if (endScene.IsEffectEnd())
        {
            music.GetMusic()->stop();

            PsceneManager::SetCurrentScene(SceneList::GetScene("PlayerHome"));
        }
    }
}

void Intro::Events()
{
    dialog.Events();

    if (nameEnteredTrue)
    {
        Pinput::IsKeyEntered(&name, 7U);
        nameText.SetText(name);
        nameText.SetOrigin({ 0.5f, 0.5f }, true);

        if (Pinput::IsKeyPressed(sf::Keyboard::Enter))
        {
            if (name.length() > 0)
            {
                birchDialogTwo = true;

                Config::Create(L"Saves/Save.psave", L"playerName", name);

                dialog2.SetStringFile("Data/Lang/Intro/Birch2", 3U);
            }
        }

        if (screenDimmingBirch.IsEffectEnd() && screenBrighteningBirch.IsEffectEnd())
        {
            dialog2.Events();
        }
    }
}

void Intro::Draw() const
{
    if (nameEnteredTrue)
    {
        if (!screenDimmingBirch.IsEffectEnd())
        {
            nameEnterBackground.Draw();
            nameEnterDialog.Draw();
            nameEnterBox.Draw();
            nameEnterTitle.Draw();
            nameEnterLine.Draw();
            nameText.Draw();
        }
        else
        {
            background.Draw();
            dialog2.Draw();
            birch.Draw();

            if (dialog2.IsDialogEnd())
            {
                endScene.Draw();
            }
        }

        if (birchDialogTwo && !screenDimmingBirch.IsEffectEnd())
        {
            screenDimmingBirch.Draw();
        }

        if (screenDimmingBirch.IsEffectEnd() && !screenBrighteningBirch.IsEffectEnd())
        {
            screenBrighteningBirch.Draw();
        }
    }
    else
    {
        background.Draw();
        dialog.Draw();
        birch.Draw();
    }

    if (!screenBrightening.IsEffectEnd())
    {
        screenBrightening.Draw();
    }

    if (nameEntered && !screenDimmingName.IsEffectEnd())
    {
        screenDimmingName.Draw();
    }
    else if (nameEntered && !screenBrighteningName.IsEffectEnd())
    {
        screenBrighteningName.Draw();
    }
}
