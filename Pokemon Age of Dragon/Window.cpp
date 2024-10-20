#include "Window.h"

sf::RenderWindow	Window::window;
sf::Event			Window::event;
SceneManager		Window::scene_manager;
Icon*				Window::window_icon = nullptr;
std::wstring		Window::window_language = L"Data/Languages/RU.pelang";
sf::Vector2f        Window::window_scale = sf::Vector2f(1.0f, 1.0f);
sf::Vector2u 		Window::window_original_size = sf::Vector2u(1U, 1U);


void Window::create(sf::Uint16 size_x, sf::Uint16 size_y, std::wstring title, sf::Uint8 style)
{
	window.create(sf::VideoMode(size_x, size_y), title, style);

	if (window_icon != nullptr)
	{
		window.setIcon(window_icon->getSize().x, window_icon->getSize().y, window_icon->getPixels());
	}

	if (window_original_size.x != 1U || window_original_size.y != 1U)
	{
		window_scale = sf::Vector2f((float)size_x / (float)window_original_size.x, (float)size_y / (float)window_original_size.y);
	}

	if (File::Read::int_read("Data/Configs/window.peconf","framerate_limit") != 0)
	{
		window.setFramerateLimit(File::Read::int_read("Data/Configs/window.peconf", "framerate_limit"));
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


void Window::setLanguage(std::wstring language)
{
	window_language = L"Data/Languages/" + language + L".pelang";

	File::Write::wstring_write(L"Data/Configs/window.peconf", L"language", language);

	window.create(sf::VideoMode(window.getSize().x, window.getSize().y), File::Read::wstring_read(Window::getLanguage(), L"window_title"), File::Read::int_read("Data/Configs/window.peconf", "style"));

	if (window_icon != nullptr)
	{
		window.setIcon(window_icon->getSize().x, window_icon->getSize().y, window_icon->getPixels());
	}

	scene_manager.returnStart();
}

std::wstring Window::getLanguage()
{
	return window_language;
}

void Window::setScale(sf::Uint16 original_size_x, sf::Uint16 original_size_y)
{
	window_original_size = sf::Vector2u(original_size_x, original_size_y);
}

sf::Vector2f Window::getScale()
{
	return window_scale;
}


sf::RenderWindow* Window::getWindow()
{
	return &window;
}

sf::Event* Window::getEvent()
{
	return &event;
}
