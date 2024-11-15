#include <Pengine.h>
#include "MainMenu.h"

int main()
{ 
    Pwindow window("Pengine", "Config.ini");

	window.GetSceneManager()->SetCurrentScene(new MainMenu(&window, window.GetEvent(), "MainMenu"));

    window.GetSceneManager()->RenderScene();
}