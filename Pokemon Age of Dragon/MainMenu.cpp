#include "MainMenu.h"
#include "Window.h"

void MainMenu::texture()
{
	sprite1.setTexture("Data/Textures/MainMenu/exit_background.png");
	sprite2.setTexture("Data/Textures/MainMenu/exit_background.png");
}

void MainMenu::sprite()
{
	sprite1.setPosition(0.5f, 0.5f);
	sprite1.setOrigin(0.5f, 0.5f);
	sprite1.setScale(5.0f, 5.0f);

	sprite2.setPosition(sprite1.getSprite(), 0.5f, 0.5f);
	sprite2.setOrigin(0.5f, 0.5f);
	sprite2.setScale(2.0f, 2.0f);
}


void MainMenu::start()
{

}

void MainMenu::update()
{
	
}

void MainMenu::events()
{
	
}

void MainMenu::render()
{
	sprite1.draw();

	sprite2.draw();
}
