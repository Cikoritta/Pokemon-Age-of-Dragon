#include "MainMenu.h"

void MainMenu::BaseStart()
{
	background.SetFrameTime(0.01f);
	background.SetLoop(true);

	logo.SetFrameTime(0.01f);
	logo.SetOrigin({ 0.5f, 0.5f }, true);
	logo.SetPosition({ 0.495f, 0.25f });
	logo.SetLoop(true);

	newGame.SetPosition({ 0.5f, 0.5f });
	newGame.SetOrigin({ 0.5f, 0.5f }, true);
	newGame.GetTamplate()->setCharacterSize(45U);
	newGame.GetTamplate()->setOutlineThickness(5.0f);
	newGame.GetTamplate()->setOutlineColor(sf::Color::Black);

	loadGame.SetTamplate(newGame.GetTamplate());
	loadGame.SetOrigin({ 0.5f, 0.5f }, true);
	loadGame.SetPosition({ 0.5f, 0.562f });

	settingGame.SetTamplate(newGame.GetTamplate());
	settingGame.SetOrigin({ 0.5f, 0.5f }, true);
	settingGame.SetPosition({ 0.5f, 0.62f });

	exitGame.SetTamplate(newGame.GetTamplate());
	exitGame.SetOrigin({ 0.5f, 0.5f }, true);
	exitGame.SetPosition({ 0.5f, 0.695f });
}

void MainMenu::ExitStart()
{
	exitBackground.SetOrigin({ 0.5f, 0.5f });
	exitBackground.SetPosition({ 0.5f, 0.5f });
	exitBackground.SetSmartScale({ 18.0f, 10.0f });
	exitBackground.SetBorderScale({ 6.0f, 6.0f });

	exitTitle.SetTamplate(newGame.GetTamplate());
	exitTitle.SetOrigin({ 0.5f, 0.5f }, true);
	exitTitle.SetPosition({ 0.5f, 0.38f });

	exitExit.SetTamplate(newGame.GetTamplate());
	exitExit.SetOrigin({ 0.5f, 0.5f }, true);
	exitExit.SetPosition({ 0.58f, 0.61f });

	exitStay.SetTamplate(newGame.GetTamplate());
	exitStay.SetOrigin({ 0.5f, 0.5f }, true);
	exitStay.SetPosition({ 0.43f, 0.62f });

	magikarp.SetPosition({ 0.5f, 0.5f });
	magikarp.SetOrigin({ 0.5f, 0.5f }, true);
	magikarp.SetScale({ 0.5f, 0.5f });
}

void MainMenu::SettingStart()
{
	settingTitle.SetTamplate(newGame.GetTamplate());
	settingTitle.SetOrigin({ 0.5f, 0.5f }, true);
	settingTitle.SetPosition({ 0.5f, 0.15f });

	settingExit.SetTamplate(newGame.GetTamplate());
	settingExit.SetOrigin({ 0.5f, 0.5f }, true);
	settingExit.SetPosition({ 0.58f, 0.8f });

	settingApply.SetTamplate(newGame.GetTamplate());
	settingApply.SetOrigin({ 0.5f, 0.5f }, true);
	settingApply.SetPosition({ 0.42f, 0.7993f });

	settingTitleResolution.SetTamplate(newGame.GetTamplate());
	settingTitleResolution.SetOrigin({ 0.0f, 0.5f }, true);
	settingTitleResolution.SetPosition({ 0.2f, 0.3f });

	settingResolution.SetTamplate(newGame.GetTamplate());
	settingResolution.SetOrigin({ 0.5f, 0.5f }, true);
	settingResolution.SetPosition({ 0.55f, 0.3f });
	
}


void MainMenu::SetResolution(bool vector)
{
	sf::Vector2u newResolution;

	sf::Uint16 currentResolution = std::stoi(Config::Read(L"ResolutionList.ini", L"current_resolution"));

	sf::Uint16 maxResolution = std::stoi(Config::Read(L"ResolutionList.ini", L"max_resolution"));

	if (currentResolution != 0U)
	{
		currentResolution;
	}

	if (vector)
	{
		if ((currentResolution + 1U) == maxResolution + 1U)
		{
            currentResolution = 1U;
		}
        else
        {
            currentResolution++;
        }

		newResolution.x = std::stoi(Config::Read(L"ResolutionList.ini", std::to_wstring(currentResolution)).substr(0, 4));

		newResolution.y = std::stoi(Config::Read(L"ResolutionList.ini", std::to_wstring(currentResolution)).substr(6));
	}
	else
	{
        if ((currentResolution - 1U) == 0U)
        {
            currentResolution = maxResolution;
        }
        else
        {
            currentResolution--;
        }

		newResolution.x = std::stoi(Config::Read(L"ResolutionList.ini", std::to_wstring(currentResolution)).substr(0, 4));

		newResolution.y = std::stoi(Config::Read(L"ResolutionList.ini", std::to_wstring(currentResolution)).substr(6));
	}

    Config::Write(L"ResolutionList.ini", L"current_resolution", std::to_wstring(currentResolution));

    window->setSize(newResolution);

    Config::Write(L"Config.ini", L"windowScaleWidth", std::to_wstring(newResolution.x / std::stof(Config::Read(L"orientedWidth"))));

    Config::Write(L"Config.ini", L"windowScaleHeight", std::to_wstring(newResolution.y / std::stof(Config::Read(L"orientedHeight"))));

    Start();
}


void MainMenu::Start()
{
	Pinput::SetWindow(window, event);

	BaseStart();

	ExitStart();

	SettingStart();
}

void MainMenu::Update()
{
	background.Animate(1920, 1U);

	logo.ScaleAnimate(0.9f, 1.1f, 0.002f);
}

void MainMenu::Events()
{
	if (!exitEvent)
	{
		if (Pinput::IsMouseCollision(&logo))
		{
			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				logo.ScaleAnimateReset();
			}
		}

		if (Pinput::IsMouseCollision(&newGame))
		{
			newGame.SetScale({ 1.1f, 1.1f });

			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				newGame.SetScale({ 1.0f, 1.0f });
			}
		}
		else if (newGame.GetScale().x == 1.1f)
		{
			newGame.SetScale({ 1.0f, 1.0f });
		}

		if (Pinput::IsMouseCollision(&loadGame))
		{
			loadGame.SetScale({ 1.1f, 1.1f });

			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				loadGame.SetScale({ 1.0f, 1.0f });
			}
		}
		else if (loadGame.GetScale().x == 1.1f)
		{
			loadGame.SetScale({ 1.0f, 1.0f });
		}

		if (Pinput::IsMouseCollision(&settingGame))
		{
			settingGame.SetScale({ 1.1f, 1.1f });

			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				settingGame.SetScale({ 1.0f, 1.0f });
			}

			if (Pinput::IsMouseButtonReleased(sf::Mouse::Left))
			{
				settingEvent = true;
			}
		}
		else if (settingGame.GetScale().x == 1.1f)
		{
			settingGame.SetScale({ 1.0f, 1.0f });
		}

		if (Pinput::IsMouseCollision(&exitGame))
		{
			exitGame.SetScale({ 1.1f, 1.1f });

			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				exitGame.SetScale({ 1.0f, 1.0f });
			}

			if (Pinput::IsMouseButtonReleased(sf::Mouse::Left))
			{
				exitEvent = true;
			}
		}
		else if (exitGame.GetScale().x == 1.1f)
		{
			exitGame.SetScale({ 1.0f, 1.0f });
		}
	}
	else
	{
		if (Pinput::IsMouseCollision(&exitStay))
		{
			exitStay.SetScale({ 1.1f, 1.1f });

			magikarp.GetSprite()->setTextureRect(sf::IntRect(0, 0, 640 ,640));

			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				exitStay.SetScale({ 1.0f, 1.0f });
			}

			if (Pinput::IsMouseButtonReleased(sf::Mouse::Left))
			{
				exitEvent = false;
			}
		}
		else if (exitStay.GetScale().x == 1.1f)
		{
			exitStay.SetScale({ 1.0f, 1.0f });
		}

		if (Pinput::IsMouseCollision(&exitExit))
		{
			exitExit.SetScale({ 1.1f, 1.1f });

			magikarp.GetSprite()->setTextureRect(sf::IntRect(640, 0, 640, 640));

			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				exitExit.SetScale({ 1.0f, 1.0f });
			}

			if (Pinput::IsMouseButtonReleased(sf::Mouse::Left))
			{
				window->close();
			}
		}
		else if (exitExit.GetScale().x == 1.1f)
		{
			exitExit.SetScale({ 1.0f, 1.0f });
		}
	}

	if (settingEvent)
	{
		if (Pinput::IsMouseCollision(&settingExit))
		{
			settingExit.SetScale({ 1.1f, 1.1f });

			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				settingExit.SetScale({ 1.0f, 1.0f });
			}

			if (Pinput::IsMouseButtonReleased(sf::Mouse::Left))
			{
				settingEvent = false;
			}
		}
		else if (settingExit.GetScale().x == 1.1f)
		{
			settingExit.SetScale({ 1.0f, 1.0f });
		}

		if (Pinput::IsMouseCollision(&settingApply))
		{
			settingApply.SetScale({ 1.1f, 1.1f });

			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				settingApply.SetScale({ 1.0f, 1.0f });
			}

			if (Pinput::IsMouseButtonReleased(sf::Mouse::Left))
			{
				settingEvent = false;
			}
		}
		else if (settingApply.GetScale().x == 1.1f)
		{
			settingApply.SetScale({ 1.0f, 1.0f });
		}

		if (Pinput::IsMouseCollision(&settingResolution))
		{
			settingResolution.SetScale({ 1.1f, 1.1f });

			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				settingResolution.SetScale({ 1.0f, 1.0f });

                SetResolution(true);
			}

            if (Pinput::IsMouseButtonPressed(sf::Mouse::Right))
            {
                settingResolution.SetScale({ 1.0f, 1.0f });

                SetResolution(false);
            }
		}
		else if (settingResolution.GetScale().x == 1.1f)
		{
			settingResolution.SetScale({ 1.0f, 1.0f });
		}
	}

	if (Pinput::IsKeyPressed(sf::Keyboard::Escape))
	{
		if (settingEvent == true)
		{
			settingEvent = false;
		}
		else
		{
			exitEvent = !exitEvent;
		}
	}
}

void MainMenu::Draw() const
{
	background.Draw();

	if (!settingEvent)
	{
		logo.Draw();

		newGame.Draw();
		loadGame.Draw();
		settingGame.Draw();
		exitGame.Draw();
	}
	else
	{
		settingTitle.Draw();
		settingExit.Draw();
		settingApply.Draw();
		settingTitleResolution.Draw();
		settingResolution.Draw();
	}

	if (exitEvent)
	{
		exitBackground.Draw();
		exitTitle.Draw();
		exitExit.Draw();
		exitStay.Draw();
		magikarp.Draw();
	}
}
