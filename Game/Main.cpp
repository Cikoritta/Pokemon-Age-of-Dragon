#include <Pengine.h>
#include "MainMenu.h"
#include "PlayerHome.h"

int main()
{ 
    Pwindow window("Pokemon Age of Dragon", "Config.ini");

	window.GetSceneManager()->SetCurrentScene(new PlayerHome(&window, window.GetEvent(), L"PlayerHome"));

    window.GetSceneManager()->RenderScene();
}