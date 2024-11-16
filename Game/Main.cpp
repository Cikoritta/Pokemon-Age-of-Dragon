#include <Pengine.h>
#include "MainMenu.h"

int main()
{ 
    Pwindow window("Pokemon Age of Dragon", "Config.ini");

	window.GetSceneManager()->SetCurrentScene(new MainMenu(&window, window.GetEvent(), L"MainMenu"));

    window.GetSceneManager()->RenderScene();
}