#include "PlayerHome.h"

void PlayerHome::Start()
{
    Pinput::SetWindow(window, event);

    background.SetScale({ 3.0f, 3.0f });
    background.SetOrigin({ 0.5f, 0.5f }, true);
    background.SetPosition({ 0.5f, 0.5f });

    map.LoadMap(L"Data/Maps/player_house.pmap");
}

void PlayerHome::Update()
{
    player.Update();
}

void PlayerHome::Events()
{
    player.Events();
}

void PlayerHome::Draw() const
{
    background.Draw();
    map.Draw();
    player.Draw();
}
