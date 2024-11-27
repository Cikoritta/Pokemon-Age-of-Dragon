#include "pch.h"
#include "Pdialog.h"
#include <EazyConfig.h>

Pdialog::Pdialog(sf::RenderWindow* window, sf::Event* event, sf::String texturePath, sf::String fontPath, sf::Color color, sf::Uint16 size)
{
    this->window = window;

    this->event = event;


    dialogTexture.loadFromFile(texturePath.toAnsiString());

    dialogSprite.setTexture(dialogTexture);


    dialogFont.loadFromFile(fontPath.toAnsiString());

    dialogText.setFont(dialogFont);

    dialogText.setFillColor(color);

    dialogText.setCharacterSize(size);


    dialogEndTexture.loadFromFile("Data/Textures/Other/Dialog/end.png");

    dialogEnd.setTexture(dialogEndTexture);

    dialogEnd.setTextureRect(sf::IntRect(0, 0, 16, 16));


    windowScale = { stof(Config::Read(L"Config.ini", L"windowScaleWidth")), stof(Config::Read(L"Config.ini", L"windowScaleHeight")) };

    dialogSprite.setScale(windowScale);
    dialogText.setScale(windowScale);
    dialogEnd.setScale(1.2f *  windowScale);


    dialogText.setPosition(dialogSprite.getPosition().x + (dialogSprite.getGlobalBounds().getSize().x / 20.0f), dialogSprite.getPosition().y + (dialogSprite.getGlobalBounds().getSize().y / 9.0f));
}


void Pdialog::Update(float timeInterval)
{
    if (!isDialogEnd)
    {
        if (!isClockStarted)
        {
            clock.restart();

            isClockStarted = true;
        }

        if (currentLetter < dialogStrings[currentDialog].length())
        {
            if (clock.getElapsedTime().asSeconds() >= timeInterval)
            {
                currentLetter++;

                dialogText.setString(dialogStrings[currentDialog].substr(0, currentLetter));

                clock.restart();
            }
        }
        else
        {
            isDialogEnd = true;
        }
    }
    else
    {
        if (!endPosition)
        {
            float width = dialogText.getPosition().x + (dialogText.getGlobalBounds().width * 1.01f) - dialogSprite.getOrigin().x;

            float height = dialogText.getPosition().y + (window->getSize().y / 100.f) - dialogSprite.getOrigin().y;
            
            countEnter = std::count(dialogStrings[currentDialog].begin(), dialogStrings[currentDialog].end(), '\n');

            if (countEnter == 1)
            {
                height += dialogText.getGlobalBounds().height - dialogEnd.getGlobalBounds().height;


                sf::Text text(dialogText);

                text.setString(dialogStrings[currentDialog].substr(dialogStrings[currentDialog].find_last_of(L"\n")));

                width = dialogText.getPosition().x + (text.getGlobalBounds().width * 1.01f) - dialogSprite.getOrigin().x;
            }
            else if(countEnter == 2)
            {
                height += dialogText.getGlobalBounds().height - dialogEnd.getGlobalBounds().height;


                sf::Text text(dialogText);

                text.setString(dialogStrings[currentDialog].substr(dialogStrings[currentDialog].find_last_of(L"\n")));

                width = dialogText.getPosition().x + (text.getGlobalBounds().width * 1.01f) - dialogSprite.getOrigin().x;
            }

            dialogEnd.setPosition(width, height);

            endPosition = true;

            countEnter = 0U;
        }

        if (clock.getElapsedTime().asSeconds() >= 0.5f)
        {
            if (dialogEnd.getTextureRect() == sf::IntRect(0, 0, 14, 16))
            {
                dialogEnd.setTextureRect(sf::IntRect(14, 0, 14, 16));
            }
            else
            {
                dialogEnd.setTextureRect(sf::IntRect(0, 0, 14, 16));
            }

            clock.restart();
        }
    }
}

void Pdialog::Events()
{
    if (currentDialog < countDialog - 1U)
    {
        if (event->type == event->KeyPressed)
        {
            if ((event->key.code == sf::Keyboard::Space) || (event->key.code == sf::Keyboard::Enter))
            {
                if (currentLetter < dialogStrings[currentDialog].length())
                {
                    currentLetter = dialogStrings[currentDialog].length();

                    dialogText.setString(dialogStrings[currentDialog].substr(0, currentLetter));
                }
                else
                {
                    currentDialog++;

                    currentLetter = 0U;

                    isDialogEnd = false;

                    isClockStarted = false;

                    endPosition = false;
                }
            }
        }
        else if (event->type == event->MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left)
        {
            if (currentLetter < dialogStrings[currentDialog].length())
            {
                currentLetter = dialogStrings[currentDialog].length();

                dialogText.setString(dialogStrings[currentDialog].substr(0, currentLetter));
            }
            else
            {
                currentDialog++;

                currentLetter = 0U;

                isDialogEnd = false;

                isClockStarted = false;

                endPosition = false;
            }
        }
    }
    else
    {
        if (event->type == event->KeyPressed)
        {
            if ((event->key.code == sf::Keyboard::Space) || (event->key.code == sf::Keyboard::Enter))
            {
                if (currentLetter < dialogStrings[currentDialog].length())
                {
                    currentLetter = dialogStrings[currentDialog].length();

                    dialogText.setString(dialogStrings[currentDialog].substr(0, currentLetter));
                }
                else
                {
                    isAllDialogEnd = true;
                }
            }
        }
        else if (event->type == event->MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left)
        {
            if (currentLetter < dialogStrings[currentDialog].length())
            {
                currentLetter = dialogStrings[currentDialog].length();

                dialogText.setString(dialogStrings[currentDialog].substr(0, currentLetter));
            }
            else
            {
                isAllDialogEnd = true;
            }
        }
    }
}


void Pdialog::SetPosition(sf::Vector2f position)
{
    dialogSprite.setPosition(window->getSize().x * position.x, window->getSize().y * position.y);

    dialogText.setPosition(dialogSprite.getPosition().x + (dialogSprite.getGlobalBounds().getSize().x / 20.0f), dialogSprite.getPosition().y + (dialogSprite.getGlobalBounds().getSize().y / 9.0f));
}

void Pdialog::SetOrigin(sf::Vector2f origin)
{
    dialogSprite.setOrigin(dialogSprite.getLocalBounds().width * origin.x, dialogSprite.getLocalBounds().height * origin.y);
    dialogText.setOrigin(dialogSprite.getOrigin().x, dialogSprite.getOrigin().y);
}

void Pdialog::SetScale(sf::Vector2f scale)
{
    dialogSprite.setScale(scale.x * windowScale.x, scale.y * windowScale.y);
    dialogText.setScale(scale.x * windowScale.x, scale.y * windowScale.y);
    dialogEnd.setScale(1.2f * (scale.x * windowScale.x), 1.2f * (scale.y * windowScale.y));
}


void Pdialog::SetStringFile(const sf::String path, sf::Uint16 countDialog)
{
    this->countDialog = countDialog;

    for (sf::Uint16 numberDialog = 0; numberDialog < countDialog; numberDialog++)
    {
        currentString = Config::Read(path.toWideString() + L"/" + Plang::GetLang().toWideString() + L".plang", std::to_wstring(numberDialog));

        while (currentString.find(L"&") != currentString.npos)
        {
            currentString.replace(currentString.find(L"&"), 1, L"\n");
        }

        dialogStrings.push_back(currentString);
    }
}


void Pdialog::Draw() const
{
    window->draw(dialogSprite);

    window->draw(dialogText);

    if (isDialogEnd)
    {
        window->draw(dialogEnd);
    }
}
