#include "PlayerHouse2.h"
#include "SceneList.h"

void PlayerHouse2::Start()
{
    if (!map.load)
    {
        map.LoadMap(L"Data/Maps/player_house2.pmap", "Data/Textures/Maps/player_house2.png");
        map.SetScale({ 4.6f, 4.6f });

        map.load = true;
    }

    if (args == 0U)
    {
        player.GetColader()->SetPixelPosition({ map.GetColaders()[108]->GetPixelPosition().x, map.GetColaders()[108]->GetPixelPosition().y + map.GetColaders()[108]->GetSize().y / 5.0f });
        player.GetSprite()->SetPixelPosition({ map.GetColaders()[108]->GetPixelPosition().x, map.GetColaders()[108]->GetPixelPosition().y + map.GetColaders()[108]->GetSize().y / 5.0f });
    }
}

void PlayerHouse2::Update()
{
    map.Update();

    player.Update();
    player.Collision(map.GetSolidColaders());

    if (player.GetColader()->IsColision(map.GetConstColaders()[108]) && args == 0U)
    {
        PsceneManager::SetCurrentScene(SceneList::GetScene(L"PlayerHome"));
    }
}

void PlayerHouse2::Events()
{
    map.Events();

    player.Events();
}

void PlayerHouse2::Draw() const
{
    map.Draw();

    player.Draw();
}
