#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Event.hpp>

class Scene
{
protected:

	sf::RenderWindow*		window = nullptr;

	sf::Event*				event = nullptr;

	virtual void			texture() = 0;

	virtual void			sprite() = 0;

public:

	void setWindow(sf::RenderWindow* window, sf::Event* event)
	{
		this->window = window;

		this->event = event;
	}

	void preStart()
	{
		texture();

		sprite();
	}

	virtual void			start() = 0;

	virtual void			update() = 0;

	virtual void			events() = 0;

	virtual void			render() = 0;
};

class DefautScene : public Scene
{
	void			texture() override
	{

	};
	void			sprite() override
	{

	};
	void			start() override
	{

	};
	void			update() override
	{

	};
	void			events() override
	{

	};
	void			render() override
	{

	};
};
