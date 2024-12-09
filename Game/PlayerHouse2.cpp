#include "PlayerHouse2.h"
#include "SceneList.h"

void PlayerHouse2::Start()
{
    if (!map.load)
    {
        map.LoadMap(L"Data/Maps/player_house2.pmap", "Data/Textures/Maps/player_house2.png");
        map.SetScale({ 4.6f, 4.6f });

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
}

void PlayerHouse2::Update()
{
    map.Update();

    if (!Brightening && !toHouse)
    {
        player.Update();
    }
    player.Collision(map.GetSolidColaders());

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
}

void PlayerHouse2::Events()
{
    map.Events();

    if (!Brightening && !toHouse)
    {
        player.Events();
    }
}

void PlayerHouse2::Draw() const
{
    map.Draw();

    player.Draw();

    if (toHouse)
    {
        toHouseEffetct.Draw();
    }

    if (Brightening)
    {
        EffetctBrightening.Draw();
    }
}
