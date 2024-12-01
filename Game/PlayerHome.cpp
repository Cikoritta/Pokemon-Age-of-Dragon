#include "PlayerHome.h"

void PlayerHome::Start()
{
    Pinput::SetWindow(window, event);

    map.LoadMap(L"Data/Maps/player_house.pmap", "Data/Textures/Maps/player_house.png");
    map.SetScale({ 4.6f, 4.6f });

    player.GetSprite()->SetPixelPosition(map.GetColaders()[24]->GetPixelPosition());
}

void PlayerHome::Update()
{
    map.Update();

    player.Update();
    player.Collision(map.GetSolidColaders());
}

void PlayerHome::Events()
{
    map.Events();

    player.Events();
}

void PlayerHome::Draw() const
{
    map.Draw();
    player.Draw();
}
