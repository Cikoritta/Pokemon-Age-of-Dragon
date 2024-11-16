#pragma once
#include <SFML/Graphics.hpp>
#include <EazyConfig.h>

class Pscene
{
protected:

	sf::RenderWindow*		window = nullptr;

	sf::Event*				event = nullptr;


	sf::String				sceneName = "none";

public:

	Pscene() = default;

	Pscene(sf::RenderWindow* window, sf::Event* event, const sf::String sceneName = "none");


	void					SetWindow(sf::RenderWindow* window);

	sf::RenderWindow*		GetWindow() const;


	void					SetEvent(sf::Event* event);

	sf::Event*				GetEvent() const;


	void 					SetSceneName(const sf::String sceneName);

	sf::String*				GetSceneName();


	virtual void			Start() = 0;

	virtual void			Update() = 0;

	virtual void			Events() = 0;

	virtual void			Draw() const = 0;
};