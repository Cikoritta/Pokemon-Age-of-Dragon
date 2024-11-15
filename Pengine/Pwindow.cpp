#include "pch.h"
#include "Pwindow.h"

PsceneManager* Pwindow::GetSceneManager()
{
    return &sceneManager;
}

sf::Event* Pwindow::GetEvent()
{
    return &event;
}


void Pwindow::SetConfigPath(const sf::String configPath)
{
	this->configPath = configPath;
}

sf::String Pwindow::GetConfigPath() const
{
    return configPath;
}


void Pwindow::ApplyConfig()
{
	Config::SetLocate(configPath);


	setSize(sf::Vector2u(stoi(Config::Read(L"createWidth")), stoi(Config::Read(L"createHeight"))));


	setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width / 2U) - getSize().x / 2U, (sf::VideoMode::getDesktopMode().height / 2U) - getSize().y / 2U));


	Config::Write(L"windowScaleWidth", std::to_wstring(getSize().x / std::stof(Config::Read(L"orientedWidth"))));

	Config::Write(L"windowScaleHeight", std::to_wstring(getSize().y / std::stof(Config::Read(L"orientedHeight"))));


	setFramerateLimit(stoi(Config::Read(L"frameRate")));

	setVerticalSyncEnabled(stoi(Config::Read(L"vsync")));


    sceneManager.SetDebugMode(stoi(Config::Read(L"debugMode")));
}
