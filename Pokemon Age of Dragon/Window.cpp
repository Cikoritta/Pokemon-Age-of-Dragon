#include "Window.h"

sf::RenderWindow	Window::window;
sf::Event			Window::event;
SceneManager		Window::scene_manager;
Icon*				Window::window_icon = nullptr;


void Window::create(sf::Uint16 size_x, sf::Uint16 size_y, std::wstring title, sf::Style::Style style)
{
	window.create(sf::VideoMode(size_x, size_y), title, style);

	if (window_icon != nullptr)
	{
		window.setIcon(window_icon->getSize().x, window_icon->getSize().y, window_icon->getPixels());
	}

	scene_manager.render(&window, &event);
}


void Window::setStartScene(Scene* scene)
{
	scene_manager.setScene(scene);
}

void Window::setIcon(Icon* icon)
{
	window_icon = icon;
}


sf::RenderWindow* Window::getWindow()
{
	return &window;
}

sf::Event* Window::getEvent()
{
	return &event;
}
