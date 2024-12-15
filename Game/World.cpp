#include "World.h"

void World::PlayerPositionFromArgs()
{
    switch (args)
    {
    case 1:

        player.GetSprite()->SetPixelPosition(map.GetColaders()[100]->GetPixelPosition());
        break;

    default:

        player.GetSprite()->SetPixelPosition(map.GetColaders()[100]->GetPixelPosition());
        break;
    }
}

void World::Start()
{
    Pinput::SetWindow(window, event);

    if (!map.load)
    {
        map.LoadMap(L"Data/Maps/world.pmap", "Data/Textures/Maps/world.png");
        map.SetScale({ 4.6f, 4.6f });

        map.load = true;
    }

    PlayerPositionFromArgs();
    player.Wallking(false);


    sf::View camera = window->getView();

    camera.setCenter(player.GetSprite()->GetPixelPosition() + *player.GetPlayerOrigin());

    window->setView(camera);

    appearanceEffect.Start(&camera);

    leaveEffect.Start(&camera);

    appearanceEvent = true;
}

void World::Update()
{
    map.Update();

    player.Update();
    player.Collision(map.GetSolidColaders(), true, window->getView());


    if (!toPlayerHouse)
    {
        if (player.GetColader()->IsColision(map.GetConstColaders()[67]))
        {
            toPlayerHouse = true;

            leaveEvent = true;
        }
    }
    else if (!leaveEvent)
    {
        if (!leaveEvent)
        {
            PsceneManager::SetCurrentScene(SceneList::GetScene(L"PlayerHouse2"), 2U);
        }
    }


    if (appearanceEvent)
    {
        if (!appearanceEffect.IsEffectEnd())
        {
            appearanceEffect.Update(0.1f, 3U);
        }
        else
        {
            appearanceEffect.Reset();

            appearanceEvent = false;
        }
    }

    if (leaveEvent)
    {
        if (!leaveEffect.IsEffectEnd())
        {
            leaveEffect.Update(0.1f, 3U);
        }
        else
        {
            leaveEffect.Reset();

            leaveEvent = false;
        }
    }
}

void World::Events()
{
    map.Events();

    player.Events();
}

void World::Draw() const
{
    map.Draw(true, window->getView());

    player.Draw();

    // Player House Roof
    for (sf::Uint8 i = 115; i <= 124; i++)
    {
        map.GetTile()[i]->Draw();
    }


    if (appearanceEvent)
    {
        appearanceEffect.Draw();
    }

    if (leaveEvent)
    {
        leaveEffect.Draw();
    }
}
