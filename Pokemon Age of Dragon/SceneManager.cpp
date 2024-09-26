#include "SceneManager.h"

Scene*		SceneManager::current_scene;
bool		SceneManager::start_completed = false;


SceneManager::SceneManager()
{
	current_scene = new DefautScene();
}

SceneManager::SceneManager(Scene* first_scene)
{
	current_scene = first_scene;
}


void SceneManager::returnStart()
{
	start_completed = false;
}


void SceneManager::setScene(Scene* scene)
{
	current_scene = scene;

	start_completed = false;
}

Scene* SceneManager::getScene()
{
	return current_scene;
}


void SceneManager::render(sf::RenderWindow* window, sf::Event* event)
{
	while (window->isOpen())
	{
		if (!start_completed)
		{
			current_scene->setWindow(window, event);

			current_scene->preStart();

			current_scene->start();

			start_completed = true;
		}

		current_scene->update();

		window->clear(sf::Color::White);

		current_scene->render();

		window->display();

		while (window->pollEvent(*event))
		{
			current_scene->events();

			if (event->type == sf::Event::Closed)
			{
				window->close();
			}
		}
	}
}
