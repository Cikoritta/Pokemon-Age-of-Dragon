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

public:

	static void								create(sf::Uint16 size_x, sf::Uint16 size_y, std::wstring title = L"Window", sf::Style::Style style = sf::Style::Default);


	static void								setStartScene(Scene* scene);

	static void								setIcon(Icon* icon);


	static sf::RenderWindow*				getWindow();

	static sf::Event*						getEvent();
};