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


    icon.loadFromFile("Data/Textures/Other/Icon/icon.png");

    setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    cursorImage.loadFromFile("Data/Textures/Other/Cursor/cursor.png");

    cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), { 0, 0 });

    setMouseCursor(cursor);


    Config::Write(L"windowScaleWidth", std::to_wstring(getSize().x / std::stof(Config::Read(L"orientedWidth"))));

    Config::Write(L"windowScaleHeight", std::to_wstring(getSize().y / std::stof(Config::Read(L"orientedHeight"))));


    sceneManager.SetDebugMode(stoi(Config::Read(L"debugMode")));

    if ((std::stoi(Config::Read(L"ResolutionList.ini", Config::Read(L"ResolutionList.ini", L"current_resolution")).substr(0, 4)) != stoi(Config::Read(L"createWidth"))) || 
        (std::stoi(Config::Read(L"ResolutionList.ini", Config::Read(L"ResolutionList.ini", L"current_resolution")).substr(6)) != stoi(Config::Read(L"createHeight"))))
    {
        bool searchResolution = false;

        sf::Uint16 numberResolution = 1U;

        while (!searchResolution)
        {
            sf::Vector2f tempResolution;

            tempResolution.x = std::stoi(Config::Read(L"ResolutionList.ini", std::to_wstring(numberResolution)).substr(0, 4));

            tempResolution.y = std::stoi(Config::Read(L"ResolutionList.ini", std::to_wstring(numberResolution)).substr(6));

            if ((tempResolution.x == stoi(Config::Read(L"createWidth"))) && (tempResolution.y == stoi(Config::Read(L"createHeight"))))
            {
                Config::Write(L"ResolutionList.ini", L"current_resolution", std::to_wstring(numberResolution));

                searchResolution = true;
            }

            numberResolution++;
        }
    }
}
