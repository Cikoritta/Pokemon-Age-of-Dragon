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

Pscene* PsceneManager::GetCurrentScene() const
{
	return currentScene;
}


ULONGLONG ft2ull(const FILETIME& ft) {
    return (((ULONGLONG)ft.dwHighDateTime) << 32) + ft.dwLowDateTime;
}

int GetCpuUsage(bool bool1, bool bool2) {

    FILETIME idle, prev_idle;
    FILETIME kernel, prev_kernel;
    FILETIME user, prev_user;

    GetSystemTimes(&prev_idle, &prev_kernel, &prev_user);

    GetSystemTimes(&idle, &kernel, &user);

    ULONGLONG sys = (ft2ull(user) - ft2ull(prev_user)) + (ft2ull(kernel) - ft2ull(prev_kernel));

    int cpu = int((sys - ft2ull(idle) + ft2ull(prev_idle)) * 100.0 / sys);
    prev_idle = idle;
    prev_kernel = kernel;
    prev_user = user;

    return cpu;
}


void PsceneManager::RenderScene()
{
	currentScene->SetWindow(window);

	currentScene->SetEvent(event);

	currentScene->Start();

	if (debugMode)
	{
        sf::Clock clockFPS;
        sf::Clock clockTime;

        clockFPS.restart();
        clockTime.restart();

        sf::Font font;
        font.loadFromFile("Data/Fonts/Classic Console Neue/clacon2.ttf");

        sf::Text fps("", font);
        fps.setOutlineThickness(1.0f);
        fps.setOutlineColor(sf::Color::Black);

        sf::Text time("", font);
        time.setOutlineThickness(1.0f);
        time.setOutlineColor(sf::Color::Black);
        time.setPosition(fps.getPosition().x, fps.getPosition().y + 30.0f);

        sf::Text scene("", font);
        scene.setOutlineThickness(1.0f);
        scene.setOutlineColor(sf::Color::Black);
        scene.setPosition(time.getPosition().x, time.getPosition().y + 30.0f);

        sf::Text CPU("", font);
        CPU.setOutlineThickness(1.0f);
        CPU.setOutlineColor(sf::Color::Black);
        CPU.setPosition(scene.getPosition().x, scene.getPosition().y + 30.0f);

        sf::Text MEM("", font);
        MEM.setOutlineThickness(1.0f);
        MEM.setOutlineColor(sf::Color::Black);
        MEM.setPosition(CPU.getPosition().x, CPU.getPosition().y + 30.0f);

        bool startSysTime = false;

        sf::Clock cpuClock;

        FILETIME idle, prev_idle;
        FILETIME kernel, prev_kernel;
        FILETIME user, prev_user;
        MEMORYSTATUSEX statex;
        int cpu = 0;

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

            if (!startSysTime)
            {
                GetSystemTimes(&prev_idle, &prev_kernel, &prev_user);

                startSysTime = true;

                cpuClock.restart();
            }

            if (cpuClock.getElapsedTime().asSeconds() >= 1.0f)
            {
                GetSystemTimes(&idle, &kernel, &user);

                ULONGLONG sys = (ft2ull(user) - ft2ull(prev_user)) + (ft2ull(kernel) - ft2ull(prev_kernel));

                cpu = int((sys - ft2ull(idle) + ft2ull(prev_idle)) * 100.0 / sys);
                prev_idle = idle;
                prev_kernel = kernel;
                prev_user = user;

                startSysTime = false;
            }

            statex.dwLength = sizeof(statex);
            GlobalMemoryStatusEx(&statex);

            fps.setString("Fps: " + std::to_string(1.0f / (clockFPS.restart().asSeconds())));
            time.setString("Time: " + std::to_string(clockTime.getElapsedTime().asSeconds()));
            scene.setString("Current scene: " + currentScene->GetSceneName());
            CPU.setString("CPU: " + std::to_string(cpu) + " %");
            MEM.setString("MEM: " + std::to_string(statex.dwMemoryLoad) + " %");

			window->clear(sf::Color::White);

			currentScene->Draw();

            window->draw(fps);
            window->draw(time);
            window->draw(scene);
            window->draw(CPU);
            window->draw(MEM);

			window->display();
		}

		return;
	}

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
