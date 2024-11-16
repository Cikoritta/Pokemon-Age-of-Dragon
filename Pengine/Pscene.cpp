#include "pch.h"
#include "Pscene.h"

Pscene::Pscene(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName)
{
	this->window = window;

	this->event = event;

	this->sceneName = sceneName;
}


void Pscene::SetWindow(sf::RenderWindow* window)
{
	this->window = window;
}

sf::RenderWindow* Pscene::GetWindow() const
{
	return window;
}


void Pscene::SetEvent(sf::Event* event)
{
	this->event = event;
}

sf::Event* Pscene::GetEvent() const
{
	return event;
}


void Pscene::SetSceneName(const sf::String sceneName)
{
	this->sceneName = sceneName;
}

sf::String* Pscene::GetSceneName()
{
	return &sceneName;
}
