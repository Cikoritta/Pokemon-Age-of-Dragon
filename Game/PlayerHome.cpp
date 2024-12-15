#include "PlayerHome.h"
#include "SceneList.h"

void PlayerHome::Start()
{
    if (!map.load)
    {
        Pinput::SetWindow(window, event);

        windowScale.x = std::stof(Config::Read(L"Config.ini", L"windowScaleWidth"));
        windowScale.y = std::stof(Config::Read(L"Config.ini", L"windowScaleHeight"));

        printf("SCALE\n");

        map.LoadMap(L"Data/Maps/player_house.pmap", "Data/Textures/Maps/player_house.png");
        map.SetScale({ 4.6f, 4.6f });

        printf("MAP\n");

        map.GetColaders()[64]->SetSize({ map.GetColaders()[64]->GetSize().x * windowScale.x, map.GetColaders()[64]->GetSize().y * 0.9f }, false);
        map.GetColaders()[65]->SetSize({ map.GetColaders()[65]->GetSize().x * 0.7f, map.GetColaders()[65]->GetSize().y * 0.9f }, false);

        map.GetColaders()[68]->SetSize({ map.GetColaders()[68]->GetSize().x, map.GetColaders()[68]->GetSize().y * 0.5f }, false);
        map.GetColaders()[68]->SetOrigin({ 0.0f, -1.0f });
        map.GetColaders()[69]->SetSize({ map.GetColaders()[69]->GetSize().x * 0.7f, map.GetColaders()[69]->GetSize().y * 0.5f }, false);
        map.GetColaders()[69]->SetOrigin({ 0.0f, -1.0f });

        map.GetColaders()[70]->SetSize({ map.GetColaders()[70]->GetSize().x, map.GetColaders()[70]->GetSize().y * 0.3f }, false);
        map.GetColaders()[71]->SetSize({ map.GetColaders()[71]->GetSize().x * 0.7f, map.GetColaders()[71]->GetSize().y * 0.3f }, false);

        map.GetColaders()[94]->SetSize({ map.GetColaders()[94]->GetSize().x * 0.8f, map.GetColaders()[94]->GetSize().y }, false);
        map.GetColaders()[94]->SetOrigin({ -0.2f, 0.0f });

        map.GetColaders()[95]->SetSize({ map.GetColaders()[95]->GetSize().x * 0.9f, map.GetColaders()[95]->GetSize().y }, false);


        printf("COLADER\n");



        tvDialog.SetOrigin({ 0.5f, 1.0f });
        tvDialog.SetScale({ 1.5f, 1.5f });
        tvDialog.SetStringFile("Data/Lang/PlayerHouse/TV", 3U);

        clockDialog.SetOrigin({ 0.5f, 1.0f });
        clockDialog.SetScale({ 1.5f, 1.5f });

        magikarpDialog.SetOrigin({ 0.5f, 1.0f });
        magikarpDialog.SetScale({ 1.5f, 1.5f });
        magikarpDialog.SetStringFile("Data/Lang/PlayerHouse/Magikarp", 2U);

        computerDialog.SetOrigin({ 0.5f, 1.0f });
        computerDialog.SetScale({ 1.5f, 1.5f });
        computerDialog.SetStringFile("Data/Lang/PlayerHouse/Computer", 2U);

        printf("STRINGS\n");


        sf::View camera = window->getView();

        EffetctBrightening.Start(&camera);
        toHouseEffetct.Start(&camera);

        camera.setCenter(player.GetSprite()->GetPixelPosition() + *player.GetPlayerOrigin());

        window->setView(camera);

        map.load = true;
    }
    else
    {
        toHouse = false;

        toHouseEffetct.Reset();
        EffetctBrightening.Reset();
    }

    printf("MAP LOAD\n");

    visited = std::stoi(Config::Read(L"Saves/Save.psave", L"playerHouse"));

    if (!visited)
    {
        player.GetColader()->SetPixelPosition({ map.GetColaders()[65]->GetPixelPosition().x - map.GetColaders()[95]->GetSize().x / 2.0f, map.GetColaders()[65]->GetPixelPosition().y + map.GetColaders()[95]->GetSize().y / 3.0f });
        player.GetSprite()->SetPixelPosition({ map.GetColaders()[65]->GetPixelPosition().x - map.GetColaders()[95]->GetSize().x / 2.0f, map.GetColaders()[65]->GetPixelPosition().y + map.GetColaders()[95]->GetSize().y / 3.0f });

        visited = true;

        startBrightening = true;

        sf::View camera = window->getView();

        camera.setCenter(player.GetSprite()->GetPixelPosition() + *player.GetPlayerOrigin());

        window->setView(camera);

        Config::Write(L"Saves/Save.psave", L"playerHouse", std::to_wstring(1));
    }
    else
    {
        player.GetColader()->SetPixelPosition({ map.GetColaders()[220]->GetPixelPosition().x - map.GetColaders()[219]->GetSize().x / 2.0f, map.GetColaders()[219]->GetPixelPosition().y - map.GetColaders()[219]->GetSize().y / 2.0f });
        player.GetSprite()->SetPixelPosition({ map.GetColaders()[220]->GetPixelPosition().x - map.GetColaders()[219]->GetSize().x / 2.0f, map.GetColaders()[219]->GetPixelPosition().y - map.GetColaders()[219]->GetSize().y / 2.0f });

        player.GetSprite()->GetSprite()->setTextureRect(sf::IntRect(0, 23, 16, 23));

        sf::View camera = window->getView();

        camera.setCenter(player.GetSprite()->GetPixelPosition() + *player.GetPlayerOrigin());

        window->setView(camera);

        EffetctBrightening.Start(&camera);
        toHouseEffetct.Start(&camera);

        Brightening = true;
    }

    printf("VISITED\n");

    player.Wallking(false);

    music.PlayMusic(true);
}

void PlayerHome::Update()
{
    map.Update();

    if (!TV && !clock && !magikarp && !computer && !toHouse && !Brightening && !startBrightening)
    {
        player.Update();
    }

    player.Collision(map.GetSolidColaders());

    if (TV)
    {
        tvDialog.Update(0.05f);

        if (tvDialog.IsDialogEnd())
        {
            TV = false;

            tvDialog.ResetDialog();
        }
    }

    if (clock)
    {
        clockDialog.Update(0.05f);

        if (clockDialog.IsDialogEnd())
        {
            clock = false;

            clockDialog.ResetDialog();
        }
    }

    if (magikarp)
    {
        magikarpDialog.Update(0.05f);

        if (magikarpDialog.IsDialogEnd())
        {
            magikarp = false;

            magikarpDialog.ResetDialog();
        }
    }

    if (computer)
    {
        computerDialog.Update(0.05f);

        if (computerDialog.IsDialogEnd())
        {
            computer = false;

            computerDialog.ResetDialog();
        }
    }


    if (!toHouse)
    {
        if (player.GetColader()->IsColision(map.GetConstColaders()[80]) && player.GetColader()->IsColision(map.GetConstColaders()[79]))
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
            PsceneManager::SetCurrentScene(SceneList::GetScene(L"PlayerHouse2"));

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

    if (startBrightening)
    {
        if (!EffetctBrighteningStart.IsEffectEnd())
        {
            EffetctBrighteningStart.Update(0.1f, 3U);
        }
        else
        {
            startBrightening = false;
        }
    }
}

void PlayerHome::Events()
{
    map.Events();

    if (!TV && !clock && !magikarp  && !computer && !toHouse && !Brightening)
    {
        player.Events();
    }
    
    if (!TV)
    {
        if (Pinput::IsKeyPressed(sf::Keyboard::Enter))
        {
            if (player.GetColader()->IsColision(map.GetConstColaders()[95]) || player.GetColader()->IsColision(map.GetConstColaders()[94]))
            {
                TV = true;

                tvDialog.SetPosition({ 0.5f, 1.0f }, true);
            }
        }
    }
    else
    {
        tvDialog.Events();
    }

    if (!clock)
    {
        if (Pinput::IsKeyPressed(sf::Keyboard::Enter))
        {
            if (player.GetColader()->IsColision(map.GetConstColaders()[100]))
            {
                clock = true;

                SYSTEMTIME currentTime;
                GetLocalTime(&currentTime);

                Config::Write(L"Data/Lang/PlayerHouse/Clock/" + Config::Read(L"Config.ini", L"lang") + L".plang", L"0", std::to_wstring(currentTime.wHour) + L":" + std::to_wstring(currentTime.wMinute) + L" ");

                clockDialog.SetStringFile("Data/Lang/PlayerHouse/Clock", 1U);

                clockDialog.SetPosition({ 0.5f, 1.0f }, true);
            }
        }
    }
    else
    {
        clockDialog.Events();
    }

    if (!magikarp)
    {
        if (Pinput::IsKeyPressed(sf::Keyboard::Enter))
        {
            if (player.GetColader()->IsColision(map.GetConstColaders()[214]))
            {
                magikarp = true;

                magikarpDialog.SetPosition({ 0.5f, 1.0f }, true);
            }
        }
    }
    else
    {
        magikarpDialog.Events();
    }

    if (!computer)
    {
        if (Pinput::IsKeyPressed(sf::Keyboard::Enter))
        {
            if (player.GetColader()->IsColision(map.GetConstColaders()[217]))
            {
                computer = true;

                computerDialog.SetPosition({ 0.5f, 1.0f }, true);
            }
        }
    }
    else
    {
        computerDialog.Events();
    }
}

void PlayerHome::Draw() const
{
    map.Draw();

    player.Draw();


    if (map.GetTile()[60]->GetBounds().intersects(player.GetColader()->GetBounds()) || map.GetTile()[68]->GetBounds().intersects(player.GetColader()->GetBounds()))
    {
        map.GetTile()[66]->Draw();
        map.GetTile()[67]->Draw();
        map.GetTile()[68]->Draw();
        map.GetTile()[69]->Draw();
    }

    if (TV)
    {
        map.GetTile()[96]->Draw();
        map.GetTile()[97]->Draw();

        tvDialog.Draw();
    }

    if (clock)
    {
        clockDialog.Draw();
    }

    if (magikarp)
    {
        magikarpDialog.Draw();
    }

    if (computer)
    {
        computerDialog.Draw();
    }

    if (toHouse)
    {
        toHouseEffetct.Draw();
    }

    if (Brightening)
    {
        EffetctBrightening.Draw();
    }

    if (startBrightening)
    {
        EffetctBrighteningStart.Draw();
    }
}
