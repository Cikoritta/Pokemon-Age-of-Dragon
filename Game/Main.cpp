#include <Pengine.h>

#include "MainMenu.h"
#include "Intro.h"
#include "PlayerHome.h"
#include "PlayerHouse2.h"
#include "World.h"

#include "SceneList.h"

static void InitScenes(sf::RenderWindow* window, sf::Event* event)
{
    SceneList::AddScene(new MainMenu(window, event, L"MainMenu"));

    SceneList::AddScene(new Intro(window, event, L"Intro"));

    SceneList::AddScene(new PlayerHome(window, event, L"PlayerHome"));

    SceneList::AddScene(new PlayerHouse2(window, event, L"PlayerHouse2"));

    SceneList::AddScene(new World(window, event, L"World"));
}

int main()
{ 
    Pwindow window("Pokemon Age of Dragon", L"Config.ini");

    InitScenes(&window, window.GetEvent());

	window.GetSceneManager()->SetCurrentScene(SceneList::GetScene(L"PlayerHouse2"));

    window.GetSceneManager()->RenderScene();
}