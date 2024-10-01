#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Window.h"

class Input
{
public:

	static sf::Event* event;

	static bool isKeyPressed(sf::Keyboard::Key key);
	static bool isKeyPressed();

	static bool isKeyReleased(sf::Keyboard::Key key);
	static bool isKeyReleased();

	static bool isMousePressed(sf::Mouse::Button button);
	static bool isMousePressed();

	static bool isMouseReleased(sf::Mouse::Button button);
	static bool isMouseReleased();

	static bool isMouseWheelMoved(bool down = false);

	static bool isMouseMoved();

	static sf::Vector2i getMousePosition();
};