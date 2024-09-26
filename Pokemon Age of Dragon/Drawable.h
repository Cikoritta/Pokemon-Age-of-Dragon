#pragma once
#include "Window.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class Drawable
{
protected:

	sf::Vector2f position = sf::Vector2f(0.0f, 0.0f);

	sf::Vector2f real_position = sf::Vector2f(0.0f, 0.0f);


	sf::Vector2f origin = sf::Vector2f(0.0f, 0.0f);


	sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);

	sf::Vector2f real_scale = sf::Vector2f(1.0f, 1.0f);


	sf::Vector2f size = sf::Vector2f(0.0f, 0.0f);


	sf::Sprite* start_position = nullptr;

public:

	virtual void		 setPosition(float x, float y) = 0;

	virtual void		 setPosition(sf::Sprite* start_position, float x, float y) = 0;

	sf::Vector2f		 getPosition()
	{
		return position;
	}

	sf::Vector2f		 getRealPosition()
	{
		return real_position;
	}


	virtual void		 setOrigin(float x, float y) = 0;

	sf::Vector2f		 getOrigin()
	{
		return origin;
	}


	virtual void		 setScale(float x, float y) = 0;

	sf::Vector2f		 getScale()
	{
		return scale;
	}

	sf::Vector2f		 getRealScale()
	{
		return real_scale;
	}


	virtual sf::Vector2f getSize() = 0;


	virtual void		 draw() = 0;
};
