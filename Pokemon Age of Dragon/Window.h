#pragma once
#include "SceneManager.h"
#include "Icon.h"
#include "File.h"

class Window
{
	static sf::RenderWindow			window;

	static sf::Event				event;

	static SceneManager				scene_manager;


	static Icon*					window_icon;

	static std::wstring				window_language;


	static sf::Vector2f				window_scale;

public:

	static void								create(sf::Uint16 size_x, sf::Uint16 size_y, std::wstring title = L"Window", sf::Uint8 style = sf::Style::Default);


	static void								setStartScene(Scene* scene);

	static void								setIcon(Icon* icon);


	static void								setLanguage(std::wstring language);

	static std::wstring						getLanguage();


	static void								setScale(sf::Uint16 original_size_x, sf::Uint16 original_size_y);

	static sf::Vector2f						getScale();


	static sf::RenderWindow*				getWindow();

	static sf::Event*						getEvent();
};