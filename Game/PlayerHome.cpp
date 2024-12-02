#include "PlayerHome.h"

void PlayerHome::Start()
{
    Pinput::SetWindow(window, event);

    windowScale.x = std::stof(Config::Read(L"Config.ini", L"windowScaleWidth"));
    windowScale.y = std::stof(Config::Read(L"Config.ini", L"windowScaleHeight"));

    map.LoadMap(L"Data/Maps/player_house.pmap", "Data/Textures/Maps/player_house.png");
    map.SetScale({ 4.6f, 4.6f });
    map.GetColaders()[64]->SetSize({ map.GetColaders()[64]->GetSize().x * windowScale.x, map.GetColaders()[64]->GetSize().y * 0.9f }, false);
    map.GetColaders()[65]->SetSize({ map.GetColaders()[65]->GetSize().x * 0.7f, map.GetColaders()[65]->GetSize().y * 0.9f }, false);

    map.GetColaders()[68]->SetSize({ map.GetColaders()[68]->GetSize().x, map.GetColaders()[68]->GetSize().y * 0.5f }, false);
    map.GetColaders()[68]->SetOrigin({ 0.0f, -1.0f });
    map.GetColaders()[69]->SetSize({ map.GetColaders()[69]->GetSize().x * 0.7f, map.GetColaders()[69]->GetSize().y * 0.5f }, false);
    map.GetColaders()[69]->SetOrigin({ 0.0f, -1.0f });

    map.GetColaders()[70]->SetSize({ map.GetColaders()[70]->GetSize().x, map.GetColaders()[70]->GetSize().y * 0.3f }, false);
    map.GetColaders()[71]->SetSize({ map.GetColaders()[71]->GetSize().x * 0.7f, map.GetColaders()[71]->GetSize().y * 0.3f }, false);

    player.GetSprite()->SetPixelPosition(map.GetColaders()[24]->GetPixelPosition());

    tvDialog.SetOrigin({ 0.5f, 1.0f });
    tvDialog.SetScale({ 1.5f, 1.5f });
    tvDialog.SetStringFile("Data/Lang/PlayerHouse", 3U);
}

void PlayerHome::Update()
{
    map.Update();

    if (!TV)
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
}

void PlayerHome::Events()
{
    map.Events();

    if (!TV)
    {
        player.Events();
    }
    else
    {
        tvDialog.Events();
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
}

void PlayerHome::Draw() const
{
    map.Draw();

    player.Draw();


    if (map.GetTile()[69]->GetBounds().intersects(player.GetColader()->GetBounds()) || map.GetTile()[68]->GetBounds().intersects(player.GetColader()->GetBounds()))
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
}
