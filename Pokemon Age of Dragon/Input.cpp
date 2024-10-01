#include "Input.h"

sf::Event* Input::event = Window::getEvent();

bool Input::isKeyPressed(sf::Keyboard::Key key)
{
	if (event->type == sf::Event::KeyPressed && event->key.code == key)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Input::isKeyPressed()
{
	if (event->type == sf::Event::KeyPressed)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::isKeyReleased(sf::Keyboard::Key key)
{
	if (event->type == sf::Event::KeyReleased && event->key.code == key)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Input::isKeyReleased()
{
	if (event->type == sf::Event::KeyReleased)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::isMousePressed(sf::Mouse::Button button)
{
	if (event->type == sf::Event::MouseButtonPressed && event->mouseButton.button == button)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Input::isMousePressed()
{
	if (event->type == sf::Event::MouseButtonPressed)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::isMouseReleased(sf::Mouse::Button button)
{
	if (event->type == sf::Event::MouseButtonReleased && event->mouseButton.button == button)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Input::isMouseReleased()
{
	if (event->type == sf::Event::MouseButtonReleased)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::isMouseWheelMoved(bool down)
{
	if (down)
	{
		if (event->type == sf::Event::MouseWheelMoved && event->mouseWheel.delta < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (event->type == sf::Event::MouseWheelMoved && event->mouseWheel.delta > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Input::isMouseMoved()
{
	if (event->type == sf::Event::MouseMoved)
	{
		return true;
	}
	else
	{
		return false;
	}
}

sf::Vector2i Input::getMousePosition()
{
	return sf::Mouse::getPosition();
}
