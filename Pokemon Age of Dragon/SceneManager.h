#pragma once
#include "Scene.h"

class SceneManager
{
	static bool				start_completed;

	static Scene*			current_scene;

public:

	SceneManager();

	SceneManager(Scene* first_scene);


	static void				setScene(Scene* scene);

	static Scene*			getScene();


	void render(sf::RenderWindow* window, sf::Event* event);
};
