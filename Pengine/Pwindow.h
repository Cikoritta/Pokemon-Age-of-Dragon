#pragma once
#include "PsceneManager.h"

class Pwindow : public sf::RenderWindow
{
	sf::Event			 event{};

	PsceneManager		 sceneManager;


    std::string			 configPath = "none";


    sf::String           title = "none";


    sf::Image            icon;

    sf::Image            cursorImage;

    sf::Cursor           cursor;


public:

	Pwindow() = default;

	Pwindow(sf::String title , std::string configPath = "none", Pscene* startScene = nullptr)
	{
		this->configPath = configPath;

        this->title = title;


		sceneManager.SetWindow(this);

		sceneManager.SetEvent(&event);


		if (startScene != nullptr)
		{
			sceneManager.SetCurrentScene(startScene);
		}


		if (configPath != "none")
		{
			ApplyConfig();
		}
	}


	PsceneManager*	  	 GetSceneManager();

	sf::Event*			 GetEvent();


	void 				 SetConfigPath(const sf::String configPath);

	sf::String			 GetConfigPath() const;


	void				 ApplyConfig();
};
