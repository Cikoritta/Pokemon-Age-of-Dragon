#pragma once
#include "Pscene.h"
#include "Windows.h"
#include "Plang.h"

class PsceneManager
{
	sf::RenderWindow*		window = nullptr;

	sf::Event*				event = nullptr;


	Pscene*					currentScene = nullptr;

    Plang                   lang = Plang(Config::Read(L"Config.ini", L"lang"));


    bool                    debugMode = false;
    bool                    debugModeVisible = true;


    FILETIME                idle{}, prev_idle{},
                            kernel{}, prev_kernel{},
                            user{}, prev_user{};

    MEMORYSTATUSEX          statex{};


    sf::Clock               cpuClock;
    bool                    cpuClockStarted = false;
    sf::Uint16              cpuUsage = 0U;


    sf::Clock               fpsClock;
    bool                    fpsClockStarted = false;


    sf::Clock               timeClock;
    bool                    timeClockStarted = false;


    sf::Font                debugFont;
    sf::Text                debugText;

    sf::Vector2f            windowScale = { 1.0f, 1.0f };

public:

	PsceneManager() = default;

	PsceneManager(sf::RenderWindow* window, sf::Event* event, Pscene* currentScene = nullptr);


	void					SetWindow(sf::RenderWindow* window);

	sf::RenderWindow*		GetWindow() const;


	void					SetEvent(sf::Event* event);

	sf::Event*				GetEvent() const;


    void                    SetDebugMode(bool debugMode);


	void					SetCurrentScene(Pscene* scene);

	Pscene*					GetCurrentScene() const;


    sf::Uint16              GetCpuUsage();

    sf::Uint16              GetMemoryUsage();  

    sf::Uint16              GetFrameRate();

    sf::Uint32              GetTimeElapsed();


    void                    DebugText(sf::String string, sf::Uint16 position = 0U);


	void					RenderScene();
};