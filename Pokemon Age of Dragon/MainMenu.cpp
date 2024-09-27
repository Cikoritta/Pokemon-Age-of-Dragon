#include "MainMenu.h"
#include "Window.h"

void MainMenu::texture()
{
	sprite1.setTexture("Data/Textures/MainMenu/image.png", sf::IntRect(0,0,200,200));
}

void MainMenu::sprite()
{
	sprite1.setPosition(0.5f, 0.5f);
	sprite1.setOrigin(0.5f, 0.5f);
}


void MainMenu::start()
{

}

void MainMenu::update()
{
	sprite1.longAnimate(LongAnimation(0.1f, 200, 200, false));

	if (bol)
	{
		sprite1.longAnimate(LongAnimation(0.2f, 200, 200, false));
	}
}

void MainMenu::events()
{
	if (event->type == event->KeyReleased && event->key.code == sf::Keyboard::F1)
	{
		bol = true;
	}
	if (event->type == event->KeyReleased && event->key.code == sf::Keyboard::F2)
	{
		sprite1.repeatAnimation();
	}
	if (event->type == event->KeyReleased && event->key.code == sf::Keyboard::F3)
	{
		printf( "%d %d %f %d\n", sprite1.getCurrentAnimation().pixel_interval_x, sprite1.getCurrentAnimation().pixel_interval_y, sprite1.getCurrentAnimation().time_interval, sprite1.getCurrentAnimation().repeat);
	}
	if (event->type == event->KeyReleased && event->key.code == sf::Keyboard::F4)
	{
		sprite1.setState(!sprite1.getState());
	}
}

void MainMenu::render()
{
	sprite1.draw();
}
