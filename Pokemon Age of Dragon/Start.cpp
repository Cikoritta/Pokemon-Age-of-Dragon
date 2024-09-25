#include "Window.h"

int main()
{
	Window::setIcon(new Icon("Data/Textures/Icon/icon.png"));

	Window::create(1280U, 720U, L"Окно", sf::Style::Close);
}
