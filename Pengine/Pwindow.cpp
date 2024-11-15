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

    this->create(sf::VideoMode(stoi(Config::Read(L"createWidth")), stoi(Config::Read(L"createHeight"))), title, stoi(Config::Read(L"Config.ini", L"createMode")));

	setFramerateLimit(stoi(Config::Read(L"frameRate")));

	setVerticalSyncEnabled(stoi(Config::Read(L"vsync")));


    Config::Write(L"windowScaleWidth", std::to_wstring(getSize().x / std::stof(Config::Read(L"orientedWidth"))));

    Config::Write(L"windowScaleHeight", std::to_wstring(getSize().y / std::stof(Config::Read(L"orientedHeight"))));


    sceneManager.SetDebugMode(stoi(Config::Read(L"debugMode")));
}
