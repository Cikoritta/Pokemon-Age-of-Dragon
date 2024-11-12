#pragma once
#include "PsceneManager.h"

class Pwindow : public sf::RenderWindow
{
	sf::Event			 event{};

	PsceneManager		 sceneManager;


	sf::String			 configPath = "none";

public:

	Pwindow() = default;

	Pwindow(const sf::VideoMode& mode, const sf::String& title, const sf::Uint32 style = sf::Style::Default, const sf::String configPath = "none", Pscene* startScene = nullptr) : sf::RenderWindow(mode, title, style)
	{
		this->configPath = configPath;


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

		Config::Write(L"Config.ini", L"windowTitle", title.toWideString());
	}


	PsceneManager*	  	 GetSceneManager();

	sf::Event*			 GetEvent();


	void 				 SetConfigPath(const sf::String configPath);

	sf::String			 GetConfigPath() const;


	void				 ApplyConfig();
};
