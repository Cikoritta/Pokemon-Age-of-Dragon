#include <Pengine.h>

#include "MainMenu.h"
#include "PlayerHome.h"
#include "PlayerHouse2.h"

#include "SceneList.h"

void InitScenes(sf::RenderWindow* window, sf::Event* event)
{
    SceneList::AddScene(new PlayerHome(window, event, L"PlayerHome"));

    SceneList::AddScene(new PlayerHouse2(window, event, L"PlayerHouse2"));
}

int main()
{ 
    Pwindow window("Pokemon Age of Dragon", "Config.ini");

    InitScenes(&window, window.GetEvent());

	window.GetSceneManager()->SetCurrentScene(SceneList::GetScene(L"PlayerHouse2"));

    window.GetSceneManager()->RenderScene();
}