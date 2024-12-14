#include "PlayerHouse2.h"
#include "SceneList.h"

void PlayerHouse2::Start()
{
    Pinput::SetWindow(window, event);

    if (!map.load)
    {
        map.LoadMap(L"Data/Maps/player_house2.pmap", "Data/Textures/Maps/player_house2.png");
        map.SetScale({ 4.6f, 4.6f });

        map.GetColaders()[144]->SetOrigin({ -0.1f, 0.0f });
        map.GetColaders()[147]->SetOrigin({ -0.1f, 0.0f });
        map.GetColaders()[145]->SetOrigin({ 0.1f, 0.0f });
        map.GetColaders()[146]->SetOrigin({ 0.1f, 0.0f });

        sf::View camera = window->getView();

        EffetctBrightening.Start(&camera);
        toHouseEffetct.Start(&camera);

        map.load = true;
    }
    else
    {
        toHouse = false;

        EffetctBrightening.Reset();
        toHouseEffetct.Reset();

        if (args == 0)
        {
            player.GetSprite()->GetSprite()->setTextureRect(sf::IntRect(0, 0, 16, 23));
        }
    }

    player.Wallking(false);
    Brightening = true;

    sf::View camera = window->getView();

    camera.setCenter(player.GetSprite()->GetPixelPosition() + *player.GetPlayerOrigin());

    window->setView(camera);

    if (args == 0U)
    {
        player.GetColader()->SetPixelPosition({ map.GetColaders()[108]->GetPixelPosition().x, map.GetColaders()[108]->GetPixelPosition().y + map.GetColaders()[108]->GetSize().y / 5.0f });
        player.GetSprite()->SetPixelPosition({ map.GetColaders()[108]->GetPixelPosition().x, map.GetColaders()[108]->GetPixelPosition().y + map.GetColaders()[108]->GetSize().y / 5.0f });
    }


    windowDialog.SetOrigin({ 0.5f, 1.0f });
    windowDialog.SetScale({ 1.5f, 1.5f });
    windowDialog.SetStringFile("Data/Lang/PlayerHouse2/Window", 2U);

    IceDialog.SetOrigin({ 0.5f, 1.0f });
    IceDialog.SetScale({ 1.5f, 1.5f });
    IceDialog.SetStringFile("Data/Lang/PlayerHouse2/Ice", 1U);

    CapDialog.SetOrigin({ 0.5f, 1.0f });
    CapDialog.SetScale({ 1.5f, 1.5f });
    CapDialog.SetStringFile("Data/Lang/PlayerHouse2/Cap", 2U);

    Mom.SetPosition(map.GetConstColaders()[124]->GetPixelPosition());
    map.GetSolidColaders().push_back(Mom.GetColader());

    MomDialog.SetOrigin({ 0.5f, 1.0f });
    MomDialog.SetScale({ 1.5f, 1.5f });
    MomDialog.SetStringFile("Data/Lang/PlayerHouse2/Mom", 2U);

    music.PlayMusic(true);
}

void PlayerHouse2::Update()
{
    map.Update();

    if (!Brightening && !toHouse && !windowEvent && !Ice && !momDialog)
    {
        player.Update();
    }
    player.Collision(map.GetSolidColaders());
    player.GetColader()->IsColision(Mom.GetColader());

    if (!toHouse)
    {
        if (player.GetColader()->IsColision(map.GetConstColaders()[108]) && args == 0U)
        {
            toHouse = true;
        }
    }
    else
    {
        toHouseEffetct.Update(0.1f, 3U);

        if (!toHouseEffetct.IsEffectEnd())
        {
            toHouseEffetct.Update(0.1f, 3U);
        }
        else
        {
            PsceneManager::SetCurrentScene(SceneList::GetScene(L"PlayerHome"));

            music.GetMusic()->stop();
        }
    }

    if (Brightening)
    {
        if (!EffetctBrightening.IsEffectEnd())
        {
            EffetctBrightening.Update(0.1f, 3U);
        }
        else
        {
            Brightening = false;
        }
    }


    if (windowEvent)
    {
        windowDialog.Update(0.05f);

        if (windowDialog.IsDialogEnd())
        {
            windowEvent = false;

            windowDialog.ResetDialog();
        }
    }

    if (Ice)
    {
        IceDialog.Update(0.05f);

        if (IceDialog.IsDialogEnd())
        {
            Ice = false;

            IceDialog.ResetDialog();
        }
    }

    if (Cap)
    {
        CapDialog.Update(0.05f);

        if (CapDialog.IsDialogEnd())
        {
            Cap = false;

            CapDialog.ResetDialog();
        }
    }

    if (momDialog && !momFirstDialog)
    {
        MomDialog.Update(0.05f);

        if (MomDialog.IsDialogEnd())
        {
            momDialog = false;

            Mom.isDialog = false;

            momFirstDialog = true;

            Config::Write(L"Saves/Save.psave", L"momFirstDialog", L"1");

            Mom.ResetRect();

            MomDialog.ResetDialog();
        }
    }


    Mom.Walk(map.GetConstColaders()[124]->GetPixelPosition(), map.GetConstColaders()[131]->GetPixelPosition(), true);
}

void PlayerHouse2::Events()
{
    map.Events();

    if (!Brightening && !toHouse && !windowEvent && !Ice && !momDialog)
    {
        player.Events();
    }
    
    if (!Brightening && !toHouse)
    {
        player.Events();
    }


    if (!windowEvent)
    {
        if (Pinput::IsKeyPressed(sf::Keyboard::Enter))
        {
            if (player.GetColader()->IsColision(map.GetConstColaders()[120]))
            {
                windowEvent = true;

                windowDialog.SetPosition({ 0.5f, 1.0f }, true);
            }
            else if (player.GetColader()->IsColision(map.GetConstColaders()[121]) && !player.GetColader()->IsColision(map.GetConstColaders()[113]))
            {
                windowEvent = true;

                windowDialog.SetPosition({ 0.5f, 1.0f }, true);
            }
        }
    }
    else
    {
        windowDialog.Events();
    }

    if (!Ice)
    {
        if (Pinput::IsKeyPressed(sf::Keyboard::Enter))
        {
            if (player.GetColader()->IsColision(map.GetConstColaders()[113]))
            {
                Ice = true;

                IceDialog.SetPosition({ 0.5f, 1.0f }, true);
            }
        }
    }
    else
    {
        IceDialog.Events();
    }

    if (!Cap)
    {
        if (Pinput::IsKeyPressed(sf::Keyboard::Enter))
        {
            if (player.GetColader()->IsColision(map.GetConstColaders()[145]) && player.GetColader()->IsColision(map.GetConstColaders()[146]))
            {
                Cap = true;

                CapDialog.SetPosition({ 0.5f, 1.0f }, true);
            }
        }
    }
    else
    {
        CapDialog.Events();
    }

    if (!momDialog && !momFirstDialog)
    {
        Mom.Dialog(&momDialog, &MomDialog);
    }
    else
    {
        MomDialog.Events();
    }
}

void PlayerHouse2::Draw() const
{
    map.Draw();


    Mom.Draw();


    player.Draw();


    Mom.Draw(true);


    if (toHouse)
    {
        toHouseEffetct.Draw();
    }

    if (Brightening)
    {
        EffetctBrightening.Draw();
    }


    if (windowEvent)
    {
        windowDialog.Draw();
    }

    if (Ice)
    {
        IceDialog.Draw();
    }

    if (Cap)
    {
        CapDialog.Draw();
    }

    if (momDialog && !momFirstDialog)
    {
        MomDialog.Draw();
    }
}
