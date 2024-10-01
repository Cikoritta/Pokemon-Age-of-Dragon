#include "MainMenu.h"
#include "Window.h"

void MainMenu::texture()
{
	sf::IntRect rect[9] = {
		sf::IntRect(0,0,6,6),
		sf::IntRect(6,0,32,6),
		sf::IntRect(38,0,6,6),
		sf::IntRect(0,6,6,32),
		sf::IntRect(6,6,32,32),
		sf::IntRect(38,6,6,32),
		sf::IntRect(0,38,6,6),
		sf::IntRect(6,38,32,6),
		sf::IntRect(38,38,6,6)
	};
	sprite1.setTexture("Data/Textures/MainMenu/exit_background.png", rect);

	text1.setFont("Data/Textures/Font/UpheavalPro.ttf");
}

void MainMenu::sprite()
{
	sprite1.setPosition(0.5f, 0.5f);
	sprite1.setSmartScale(6.0f, 6.0f);
	sprite1.setOrigin(0.5f, 0.5f);
	sprite1.setBorderScale(0.5f, 0.5f);

	text1.setString(L"Центр");
	text1.setPosition(&sprite1, 0.0f, 0.0f);
	text1.getText()->setFillColor(sf::Color::Black);
	text1.setOrigin(0.5f, 0.5f);
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

	text1.draw();
}
