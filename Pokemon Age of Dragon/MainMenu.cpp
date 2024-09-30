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
	sprite1.animate(Animation(0.1f, 200U, true));

	if (move)
	{
		sprite1.move(Move(Window::getWindow()->getSize().x, Window::getWindow()->getSize().y, 0.001f, 3));
	}

	if (move2)
	{
		sprite1.move(Move(Window::getWindow()->getSize().x / 2.0f, Window::getWindow()->getSize().y / 2.0f, 0.001f, 3));
	}

	printf( "%d\n", sprite1.isMoveEnd());
}

void MainMenu::events()
{
	if (event->type == event->KeyReleased && event->key.code == sf::Keyboard::F1)
	{
		move = true;

		move2 = false;
	}

	if (event->type == event->KeyReleased && event->key.code == sf::Keyboard::F2)
	{
		move2 = true;

		move = false;
	}
}

void MainMenu::render()
{
	sprite1.draw();
}
