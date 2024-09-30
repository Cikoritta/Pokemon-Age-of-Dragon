#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include "Window.h"

class Move
{
	sf::Vector2f			scale_position;

public:

	Move() = default;

	Move(float position_x, float position_y, float time_interval, sf::Uint16 pixel_interval)
	{
		this->scale_position = sf::Vector2f(position_x, position_y);

		this->time_interval = time_interval;

		this->pixel_interval = pixel_interval;

		this->position = sf::Vector2f(Window::getWindow()->getSize().x * position_x, Window::getWindow()->getSize().y * position_y);
	}


	sf::Vector2f			position;

	float					time_interval;

	sf::Uint16				pixel_interval;


	float					getID()
	{
		return time_interval + (float)pixel_interval + position.x + position.y;
	}
};

class Moving
{
protected:

	float				previous_move;

	Move				current_move;


	sf::Clock			clock;

	float				scale_factor = 1.0f;

	sf::Vector2<bool>	move_direction;

	sf::Vector2f		distance = sf::Vector2f(1.0f, 1.0f);

	sf::Vector2f		end_position = sf::Vector2f(0.0f, 0.0f);


	sf::Vector2<bool>	move_end_direction = sf::Vector2<bool>(false, false);

	bool				x_larger_y = false;

	bool				clock_restart = false;

	bool				move_end = true;

public:

	virtual void		move(Move move) = 0;

	bool				isMoveEnd()
	{
		return move_end;
	}
};
