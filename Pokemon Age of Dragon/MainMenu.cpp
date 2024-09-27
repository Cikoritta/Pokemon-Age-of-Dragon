#include "MainMenu.h"
#include "Window.h"

void MainMenu::texture()
{
	sprite1.setTexture("Data/Textures/MainMenu/exit_background.png");
	sprite2.setFont("Data/Textures/Font/Retron2000.ttf");
}

void MainMenu::sprite()
{
	sprite1.setPosition(0.5f, 0.5f);
	sprite1.setOrigin(0.5f, 0.5f);
	sprite1.setScale(5.0f, 5.0f);

	sprite2.setString(L"Hello");
	sprite2.getText()->setFillColor(sf::Color::Black);
	sprite2.setPosition(sprite1.getSprite(), 1.0f, 1.0f);
	sprite2.setOrigin(0.5f, 0.5f);
	

	a.setFillColor(sf::Color::Red);
	a.setPosition(100, 100);
	a.setSize(sf::Vector2f(1,1));
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

	Window::getWindow()->draw(a);
}
