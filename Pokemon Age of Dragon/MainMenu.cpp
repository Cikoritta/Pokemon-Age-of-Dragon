#include "MainMenu.h"
#include "Window.h"

void MainMenu::texture()
{
	background.setTexture("Data/Textures/MainMenu/background.png", sf::IntRect(0, 0, 1920, 1080));

	logo.setTexture("Data/Textures/MainMenu/logo.png");
}

void MainMenu::sprite()
{
	
}

void MainMenu::start()
{

}

void MainMenu::update()
{
	background.animate(Animation(0.001f, 1, true));

	
}

void MainMenu::events()
{
	
}

void MainMenu::render()
{
	background.draw();
}
