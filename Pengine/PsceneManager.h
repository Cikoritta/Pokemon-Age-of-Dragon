#pragma once
#include "Pscene.h"

class PsceneManager
{
	sf::RenderWindow*		window = nullptr;

	sf::Event*				event = nullptr;


	Pscene*					currentScene = nullptr;

public:

	PsceneManager() = default;

	PsceneManager(sf::RenderWindow* window, sf::Event* event, Pscene* currentScene = nullptr);


	void					SetWindow(sf::RenderWindow* window);

	sf::RenderWindow*		GetWindow() const;


	void					SetEvent(sf::Event* event);

	sf::Event*				GetEvent() const;


	void					SetCurrentScene(Pscene* scene);

	Pscene*					GetCurrentScene() const;


	void					RenderScene();
};