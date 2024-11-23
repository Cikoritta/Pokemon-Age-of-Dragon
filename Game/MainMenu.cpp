#include "MainMenu.h"

void MainMenu::BaseStart()
{
	background.SetFrameTime(0.01f);
	background.SetScale({ 1.0f, 1.0f });
	background.SetLoop(true);

	logo.SetFrameTime(0.01f);
	logo.SetOrigin({ 0.5f, 0.5f }, true);
	logo.SetPosition({ 0.495f, 0.25f });
	logo.SetLoop(true);
    logo.ScaleAnimateReset();

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

    warning.SetTamplate(newGame.GetTamplate());
    warning.SetOrigin({ 0.5f, 0.5f }, true);
    warning.SetPosition({ 0.5f, 0.38f });
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
	settingResolution.SetOrigin({ 0.0f, 0.5f }, true);
	settingResolution.SetPosition({ 0.5f, 0.3f });

    settingTitleStyle.SetTamplate(newGame.GetTamplate());
    settingTitleStyle.SetOrigin({ 0.0f, 0.5f }, true);
    settingTitleStyle.SetPosition({ 0.2f, 0.35f });

    settingStyle.SetTamplate(newGame.GetTamplate());
    settingStyle.SetOrigin({ 0.0f, 0.5f }, true);
    settingStyle.SetPosition({ 0.5f, 0.341f });
    if (Config::Read(L"Config.ini", L"createMode") == L"4")
    {
        settingStyle.SetText(Plang::GetString(L"setting_style_window", L"MainMenu"));
    }

    settingTitleMusic.SetTamplate(newGame.GetTamplate());
    settingTitleMusic.SetOrigin({ 0.0f, 0.5f }, true);
    settingTitleMusic.SetPosition({ 0.2f, 0.4f });

    settingTitleEffect.SetTamplate(newGame.GetTamplate());
    settingTitleEffect.SetOrigin({ 0.0f, 0.5f }, true);
    settingTitleEffect.SetPosition({ 0.2f, 0.45f });

    settingMusic.SetTamplate(newGame.GetTamplate());
    settingMusic.SetOrigin({ 0.0f, 0.5f }, true);
    settingMusic.SetPosition({ 0.5f, 0.4f });

    settingEffect.SetTamplate(newGame.GetTamplate());
    settingEffect.SetOrigin({ 0.0f, 0.5f }, true);
    settingEffect.SetPosition({ 0.5f, 0.45f });
}


void MainMenu::SetTempSetting()
{
	sf::Vector2u newResolution;

	sf::Uint16 currentResolution = std::stoi(Config::Read(L"ResolutionList.ini", L"current_resolution"));


    newResolution.x = std::stoi(Config::Read(L"ResolutionList.ini", std::to_wstring(currentResolution)).substr(0, 4));

    newResolution.y = std::stoi(Config::Read(L"ResolutionList.ini", std::to_wstring(currentResolution)).substr(6));


    window->create(sf::VideoMode(newResolution.x, newResolution.y), "Pokemon Age of Dragon", stoi(Config::Read(L"$SettingTemp", L"createMode")));

    window->setFramerateLimit(stoi(Config::Read(L"$SettingTemp", L"frameRate")));

    window->setVerticalSyncEnabled(stoi(Config::Read(L"$SettingTemp", L"vsync")));


    Config::Write(L"Config.ini", L"createWidth", std::to_wstring(newResolution.x));
    Config::Write(L"Config.ini", L"createHeight", std::to_wstring(newResolution.y));
    Config::Write(L"Config.ini", L"createMode", Config::Read(L"$SettingTemp", L"createMode"));
    Config::Write(L"Config.ini", L"frameRate", Config::Read(L"$SettingTemp", L"frameRate"));
    Config::Write(L"Config.ini", L"vsync", Config::Read(L"$SettingTemp", L"vsync"));


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

    music.PlayMusic(true);
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

                magikarpSound.PlayEffect();
			}
		}

		if (Pinput::IsMouseCollision(&newGame))
		{
			newGame.SetScale({ 1.1f, 1.1f });

			if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
			{
				newGame.SetScale({ 1.0f, 1.0f });
			}


            if (Pinput::IsMouseButtonReleased(sf::Mouse::Left))
            {
                buttonSound.PlayEffect();
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

            if (Pinput::IsMouseButtonReleased(sf::Mouse::Left))
            {
                buttonSound.PlayEffect();

                warningReset = true;
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
                buttonSound.PlayEffect();

				settingEvent = true;

                Config::CreateConfig(L"$SettingTemp", false);

                Config::CopyConfig(L"$SettingTemp", L"Config.ini");

                if (Config::Read(L"Config.ini", L"createMode") == L"4")
                {
                    settingStyle.SetText(Plang::GetString(L"setting_style_window", L"MainMenu"));
                }
                else
                {
                    settingStyle.SetText(Plang::GetString(L"setting_style_fullscreen", L"MainMenu"));
                }
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
                buttonSound.PlayEffect();

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
                buttonSound.PlayEffect();

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
                buttonSound.PlayEffect();

                while (buttonSound.GetSound()->getStatus() != 0)
                {

                }

                Config::DeleteConfig("$SettingTemp");

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
                buttonSound.PlayEffect();

				settingEvent = false;

                Config::DeleteConfig("$SettingTemp");
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
                buttonSound.PlayEffect();

                SetTempSetting();

                Config::DeleteConfig("$SettingTemp");

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

                if (std::stoi(Config::Read(L"ResolutionList.ini", L"current_resolution")) + 1U != std::stoi(Config::Read(L"ResolutionList.ini", L"max_resolution")) + 1U)
                {
                    Config::Write(L"ResolutionList.ini", L"current_resolution", std::to_wstring((stoi(Config::Read(L"ResolutionList.ini", L"current_resolution")) + 1)));
                }
                else
                {
                    Config::Write(L"ResolutionList.ini", L"current_resolution", std::to_wstring(1));
                }
                 
                std::wstring width = std::to_wstring(std::stoi((Config::Read(L"ResolutionList.ini", Config::Read(L"ResolutionList.ini", L"current_resolution")).substr(0, 4))));
                std::wstring height =  std::to_wstring(std::stoi((Config::Read(L"ResolutionList.ini", Config::Read(L"ResolutionList.ini", L"current_resolution")).substr(6))));

                settingResolution.SetText(width + L"x" + height);
			}

            if (Pinput::IsMouseButtonPressed(sf::Mouse::Right))
            {
                settingResolution.SetScale({ 1.0f, 1.0f });

                if (std::stoi(Config::Read(L"ResolutionList.ini", L"current_resolution")) - 1U != 0U)
                {
                    Config::Write(L"ResolutionList.ini", L"current_resolution", std::to_wstring((stoi(Config::Read(L"ResolutionList.ini", L"current_resolution")) - 1)));
                }
                else
                {
                    Config::Write(L"ResolutionList.ini", L"current_resolution", Config::Read(L"ResolutionList.ini", L"max_resolution"));
                }

                std::wstring width = std::to_wstring(std::stoi((Config::Read(L"ResolutionList.ini", Config::Read(L"ResolutionList.ini", L"current_resolution")).substr(0, 4))));
                std::wstring height = std::to_wstring(std::stoi((Config::Read(L"ResolutionList.ini", Config::Read(L"ResolutionList.ini", L"current_resolution")).substr(6))));

                settingResolution.SetText(width + L"x" + height);
            }
		}
		else if (settingResolution.GetScale().x == 1.1f)
		{
			settingResolution.SetScale({ 1.0f, 1.0f });
		}

        if (Pinput::IsMouseCollision(&settingStyle))
        {
            settingStyle.SetScale({ 1.1f, 1.1f });

            if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
            {
                settingStyle.SetScale({ 1.0f, 1.0f });

                if (std::stoi(Config::Read(L"$SettingTemp", L"createMode")) == 4U)
                {
                    Config::Write(L"$SettingTemp", L"createMode", std::to_wstring(8U));

                    settingStyle.SetText(Plang::GetString(L"setting_style_fullscreen", L"MainMenu"));
                }
                else
                {
                    Config::Write(L"$SettingTemp", L"createMode", std::to_wstring(4U));

                    settingStyle.SetText(Plang::GetString(L"setting_style_window", L"MainMenu"));
                }
            }

            if (Pinput::IsMouseButtonPressed(sf::Mouse::Right))
            {
                settingStyle.SetScale({ 1.0f, 1.0f });

                if (std::stoi(Config::Read(L"$SettingTemp", L"createMode")) == 4U)
                {
                    Config::Write(L"$SettingTemp", L"createMode", std::to_wstring(8U));

                    settingStyle.SetText(Plang::GetString(L"setting_style_fullscreen", L"MainMenu"));
                }
                else
                {
                    Config::Write(L"$SettingTemp", L"createMode", std::to_wstring(4U));

                    settingStyle.SetText(Plang::GetString(L"setting_style_window", L"MainMenu"));
                }
            }
        }
        else if (settingStyle.GetScale().x == 1.1f)
        {
            settingStyle.SetScale({ 1.0f, 1.0f });
        }

        if (Pinput::IsMouseCollision(&settingMusic))
        {
            settingMusic.SetScale({ 1.1f, 1.1f });

            if (Pinput::IsMouseScrolled())
            {
                if (std::stoi(Config::Read(L"Sound.ini", L"Music")) < 100)
                {
                    Config::Write(L"Sound.ini", L"Music", std::to_wstring(std::stoi(Config::Read(L"Sound.ini", L"Music")) + 1U));
                }

                settingMusic.SetText(Config::Read(L"Sound.ini", L"Music"));
            }

            if (Pinput::IsMouseScrolled(true))
            {
                if (std::stoi(Config::Read(L"Sound.ini", L"Music")) > 0)
                {
                    Config::Write(L"Sound.ini", L"Music", std::to_wstring(std::stoi(Config::Read(L"Sound.ini", L"Music")) - 1U));
                }

                settingMusic.SetText(Config::Read(L"Sound.ini", L"Music"));
            }
        }
        else if (settingMusic.GetScale().x == 1.1f)
        {
            settingMusic.SetScale({ 1.0f, 1.0f });
        }

        if (Pinput::IsMouseCollision(&settingEffect))
        {
            settingEffect.SetScale({ 1.1f, 1.1f });

            if (Pinput::IsMouseScrolled())
            {
                if (std::stoi(Config::Read(L"Sound.ini", L"Effect")) < 100)
                {
                    Config::Write(L"Sound.ini", L"Effect", std::to_wstring(std::stoi(Config::Read(L"Sound.ini", L"Effect")) + 1U));
                }

                settingEffect.SetText(Config::Read(L"Sound.ini", L"Effect"));
            }

            if (Pinput::IsMouseScrolled(true))
            {
                if (std::stoi(Config::Read(L"Sound.ini", L"Effect")) > 0)
                {
                    Config::Write(L"Sound.ini", L"Effect", std::to_wstring(std::stoi(Config::Read(L"Sound.ini", L"Effect")) - 1U));
                }

                settingEffect.SetText(Config::Read(L"Sound.ini", L"Effect"));
            }
        }
        else if (settingEffect.GetScale().x == 1.1f)
        {
            settingEffect.SetScale({ 1.0f, 1.0f });
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

        settingTitleStyle.Draw();
        settingStyle.Draw();

        settingTitleMusic.Draw();
        settingTitleEffect.Draw();

        settingMusic.Draw();
        settingEffect.Draw();
	}

	if (exitEvent)
	{
		exitBackground.Draw();

		exitTitle.Draw();

		exitExit.Draw();
		exitStay.Draw();

		magikarp.Draw();
	}

    if (warningReset)
    {
        exitBackground.Draw();
        warning.Draw();
    }
}
