#include "pch.h"
#include "PsceneManager.h"

PsceneManager::PsceneManager(sf::RenderWindow* window, sf::Event* event, Pscene* currentScene)
{
	this->window = window;

	this->event = event;

	this->currentScene = currentScene;
}


void PsceneManager::SetWindow(sf::RenderWindow* window)
{
	this->window = window;
}

sf::RenderWindow* PsceneManager::GetWindow() const
{
	return window;
}


void PsceneManager::SetEvent(sf::Event* event)
{
	this->event = event;
}

sf::Event* PsceneManager::GetEvent() const
{
	return event;
}


void PsceneManager::SetCurrentScene(Pscene* scene)
{
	currentScene = scene;

	currentScene->SetWindow(window);

	currentScene->SetEvent(event);


	currentScene->Start();
}

Pscene* PsceneManager::GetCurrentScene() const
{
	return currentScene;
}


void PsceneManager::RenderScene()
{
	currentScene->SetWindow(window);

	currentScene->SetEvent(event);


	currentScene->Start();

	while (window->isOpen())
	{
		while (window->pollEvent(*event))
		{
			if (event->type == event->Closed)
			{
				window->close();
			}

			if (event->type == event->Resized)
			{
				window->setView(sf::View(sf::FloatRect(0.0f, 0.0f, static_cast<float>(event->size.width), static_cast<float>(event->size.height))));
			}

			currentScene->Events();
		}

		currentScene->Update();


		window->clear(sf::Color::White);

		currentScene->Draw();

		window->display();
	}
}
