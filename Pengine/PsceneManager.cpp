#include "pch.h"
#include "PsceneManager.h"

Pscene* PsceneManager::currentScene = nullptr;
sf::RenderWindow* PsceneManager::window = nullptr;
sf::Event* PsceneManager::event = nullptr;

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


void PsceneManager::SetDebugMode(bool debugMode)
{
	this->debugMode = debugMode;
}


void PsceneManager::SetCurrentScene(Pscene* scene)
{
	currentScene = scene;

	currentScene->SetWindow(window);

	currentScene->SetEvent(event);


	currentScene->Start();
}

Pscene* PsceneManager::GetCurrentScene()
{
	return currentScene;
}


sf::Uint16 PsceneManager::GetCpuUsage()
{
    if (!cpuClockStarted)
    {
        GetSystemTimes(&prev_idle, &prev_kernel, &prev_user);

        cpuClock.restart();

        cpuClockStarted = true;
    }

    if (cpuClock.getElapsedTime().asSeconds() >= 1.0f)
    {
        GetSystemTimes(&idle, &kernel, &user);

        ULONGLONG sys = (((((ULONGLONG)user.dwHighDateTime) << 32) + user.dwLowDateTime) - ((((ULONGLONG)prev_user.dwHighDateTime) << 32) + prev_user.dwLowDateTime))
            + ((((ULONGLONG)kernel.dwHighDateTime) << 32) + kernel.dwLowDateTime) - ((((ULONGLONG)prev_kernel.dwHighDateTime) << 32) + prev_kernel.dwLowDateTime);

        cpuUsage = sf::Uint16((sys - ((((ULONGLONG)idle.dwHighDateTime) << 32) + idle.dwLowDateTime) + ((((ULONGLONG)prev_idle.dwHighDateTime) << 32) + prev_idle.dwLowDateTime)) * 100.0 / sys);
        
        prev_idle = idle;
        prev_kernel = kernel;
        prev_user = user;

        cpuClockStarted = false;
    }

    return static_cast<sf::Uint16>(cpuUsage);
}

sf::Uint16 PsceneManager::GetMemoryUsage()
{
    statex.dwLength = sizeof(statex);

    GlobalMemoryStatusEx(&statex);

    return static_cast<sf::Uint16>(statex.dwMemoryLoad);
}

sf::Uint16 PsceneManager::GetFrameRate()
{
    if (!fpsClockStarted)
    {
        fpsClock.restart();

        fpsClockStarted = true;
    }

    return static_cast<sf::Uint16>((1.0f / (fpsClock.restart().asSeconds())));
}

sf::Uint32 PsceneManager::GetTimeElapsed()
{
    if (!timeClockStarted)
    {
        timeClock.restart();

        timeClockStarted = true;
    }

    return static_cast<sf::Uint32>(timeClock.getElapsedTime().asSeconds());
}


void PsceneManager::DebugText(sf::String string, sf::Uint16 position)
{
    if (debugText.getFont() == nullptr)
    {
        debugFont.loadFromFile("Data/Fonts/Classic Console Neue/clacon2.ttf");

        windowScale = { stof(Config::Read(L"Config.ini", L"windowScaleWidth")), stof(Config::Read(L"Config.ini", L"windowScaleHeight")) };

        debugText.setCharacterSize(20U);
        debugText.setFont(debugFont);
        debugText.setOutlineThickness(1.0f);
        debugText.setOutlineColor(sf::Color::Black);
        debugText.setScale(windowScale);
    }

    debugText.setPosition(0.0f, (20.0f * position) * windowScale.y);
    debugText.setString(string);

    window->draw(debugText);
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

            if (debugMode)
            {
                if (event->type == event->KeyPressed && event->key.code == sf::Keyboard::F2)
                {
                    debugModeVisible = !debugModeVisible;
                }
            }

			currentScene->Events();
		}


		currentScene->Update();


        window->clear(sf::Color::White);

		currentScene->Draw();

        if (debugMode && debugModeVisible)
        {
            DebugText("Fps: " + std::to_string(GetFrameRate()));
            DebugText("Time: " + std::to_string(GetTimeElapsed()) + "s", 1U);

            DebugText("Current scene: " + *currentScene->GetSceneName(), 2U);

            DebugText("CPU: " + std::to_string(GetCpuUsage()) + " %", 3U);
            DebugText("MEM: " + std::to_string(GetMemoryUsage()) + " %", 4U);
        }

		window->display();
	}
}
