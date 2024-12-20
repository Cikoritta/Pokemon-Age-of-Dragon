#include "pch.h"
#include "Pcolader.h"
#include <EazyConfig.h>

sf::Uint8 Pcolader::Colision()
{
	if (GetBounds().intersects(colisionColader->GetBounds()))
	{
		if ((GetRectangleBounds().topLeft.y == colisionColader->GetRectangleBounds().bottomLeft.y) || GetRectangleBounds().bottomLeft.y == colisionColader->GetRectangleBounds().topLeft.y)
		{
			colision = 1U;

			return 1;
		}

		if ((GetRectangleBounds().topRight.x == colisionColader->GetRectangleBounds().topLeft.x) || GetRectangleBounds().topLeft.x == colisionColader->GetRectangleBounds().topRight.x)
		{
			colision = 1U;

			return 1;
		}

		if (colisionColader->IsSolid())
		{
			float top = abs(GetRectangleBounds().topLeft.y - colisionColader->GetRectangleBounds().bottomLeft.y);

			float bottom = abs(colisionColader->GetRectangleBounds().topLeft.y - GetRectangleBounds().bottomLeft.y);

			float left = abs(GetRectangleBounds().topRight.x - colisionColader->GetRectangleBounds().topLeft.x);

			float right = abs(colisionColader->GetRectangleBounds().topRight.x - GetRectangleBounds().topLeft.x);


			float min = fmin(top, fmin(bottom, fmin(left, right)));

			if (min == top)
			{
				SetPixelPosition(sf::Vector2f(GetPixelPosition().x, GetPixelPosition().y + top));
			}
			else if (min == bottom)
			{
				SetPixelPosition(sf::Vector2f(GetPixelPosition().x, GetPixelPosition().y - bottom));
			}
			else if (min == left)
			{
				SetPixelPosition(sf::Vector2f(GetPixelPosition().x - left, GetPixelPosition().y));
			}
			else if (min == right)
			{
				SetPixelPosition(sf::Vector2f(GetPixelPosition().x + right, GetPixelPosition().y));
			}

			colision = 1U;

			return 1;
		}

		colision = 2U;

		return 2;
	}

	colision = 0U;

	return 0;
}


Pcolader::Pcolader()
{
	bounds.setFillColor(sf::Color::Transparent);
	bounds.setOutlineColor(sf::Color::Green);
	bounds.setOutlineThickness(1.0f);

	font.loadFromFile("Data/Fonts/Classic Console Neue/clacon2.ttf");
	font.setSmooth(false);

	textName.setFont(font);
	textName.setString(coladerName);
	textName.setCharacterSize(12);
	textName.setFillColor(sf::Color::White);
	textName.setOutlineThickness(1.0f);
	textName.setOutlineColor(sf::Color::Black);
}

Pcolader::Pcolader(sf::RenderWindow* window, sf::Event* event, sf::Vector2f position, sf::Vector2f size, const sf::String coladerName)
{
	this->window = window;
	this->event = event;

	this->position = position;

	this->coladerName = coladerName;

    windowScale = { stof(Config::Read(L"Config.ini", L"windowScaleWidth")), stof(Config::Read(L"Config.ini", L"windowScaleHeight")) };

	bounds.setSize({ size.x * windowScale.x, size.y * windowScale.y });
	bounds.setPosition(window->getSize().x * position.x, window->getSize().y * position.y);
	bounds.setFillColor(sf::Color::Transparent);
	bounds.setOutlineColor(sf::Color::Green);
	bounds.setOutlineThickness(1.0f);

	font.loadFromFile("Data/Fonts/Classic Console Neue/clacon2.ttf");
	font.setSmooth(false);

	textName.setFont(font);
	textName.setString(coladerName);
    textName.setCharacterSize(static_cast<unsigned int>(12 * ((windowScale.x + windowScale.y) / 2.0f)));
	textName.setFillColor(sf::Color::White);
	textName.setOutlineThickness(1.0f);
	textName.setOutlineColor(sf::Color::Black);
	textName.setPosition(bounds.getPosition().x + 3.0f, bounds.getPosition().y);
}


void Pcolader::SetWindow(sf::RenderWindow* window)
{
	this->window = window;

    windowScale = { stof(Config::Read(L"Config.ini", L"windowScaleWidth")), stof(Config::Read(L"Config.ini", L"windowScaleHeight")) };
}

void Pcolader::SetEvent(sf::Event* event)
{
	this->event = event;
}


void Pcolader::SetColaderName(const sf::String coladerName)
{
	this->coladerName = coladerName;
}

sf::String Pcolader::GetColaderName() const
{
	return coladerName;
}


void Pcolader::Draw() const
{
	window->draw(bounds);
	window->draw(textName);
}


void Pcolader::SetSprite(Psprite* sprite)
{
    this->sprite = sprite;

    sprite->SetPixelPosition(bounds.getPosition());
}


bool Pcolader::IsColision(Pcolader* colader)
{
	colisionColader = colader;

	if (Colision() == 2)
	{
		if (colisionColader->IsSolid())
		{
			bounds.setOutlineColor(sf::Color::Yellow);

			return true;
		}

		bounds.setOutlineColor(sf::Color::Red);

		return true;
	}
	else if (Colision() == 1)
	{
		bounds.setOutlineColor(sf::Color::Yellow);

		return true;
	}

	bounds.setOutlineColor(sf::Color::Green);

	return false;
}


void Pcolader::SetSolid(bool solid)
{
	this->solid = solid;
}

bool Pcolader::IsSolid() const
{
	return solid;
}


void Pcolader::SetPosition(sf::Vector2f position)
{
	this->position = position;

	bounds.setPosition(window->getSize().x * position.x, window->getSize().y * position.y);

    textName.setPosition(bounds.getPosition().x + 3.0f, bounds.getPosition().y);

    if (sprite != nullptr)
    {
        sprite->SetPixelPosition(bounds.getPosition());
    }
}

void Pcolader::SetPixelPosition(sf::Vector2f position)
{
	bounds.setPosition(position);

    textName.setPosition(bounds.getPosition().x + 3.0f, bounds.getPosition().y);

    if (sprite != nullptr)
    {
        sprite->SetPixelPosition({ bounds.getPosition().x, bounds.getPosition().y });
    }

	this->position = { bounds.getSize().x / window->getSize().x, bounds.getSize().y / window->getSize().y };
}

sf::Vector2f Pcolader::GetPosition() const
{
	return position;
}

sf::Vector2f Pcolader::GetPixelPosition() const
{
	return bounds.getPosition();
}

sf::Vector2f Pcolader::GetRealPosition() const
{
	return sf::Vector2f(bounds.getPosition().x - bounds.getOrigin().x, bounds.getPosition().y - bounds.getOrigin().y);
}

sf::Vector2f Pcolader::GetScale() const
{
	return bounds.getScale();
}


void Pcolader::SetSize(sf::Vector2f size, bool scale)
{
    if (!scale)
    {
        bounds.setSize(size);

        return;
    }

    bounds.setSize({ size.x * windowScale.x, size.y * windowScale.y });
}

sf::Vector2f Pcolader::GetSize() const
{
	return bounds.getSize() + sf::Vector2f(1.0f, 1.0f);
}


sf::FloatRect Pcolader::GetBounds(bool local) const
{
	if (local)
	{
		return bounds.getLocalBounds();
	}

	return bounds.getGlobalBounds();
}

RectangleBounds Pcolader::GetRectangleBounds() const
{
	return RectangleBounds(GetRealPosition(), sf::Vector2f(GetRealPosition().x + GetSize().x, GetRealPosition().y), sf::Vector2f(GetRealPosition().x, GetRealPosition().y + GetSize().y), sf::Vector2f(GetRealPosition().x + GetSize().x, GetRealPosition().y + GetSize().y));
}


void Pcolader::SetOrigin(sf::Vector2f origin, bool local)
{
	this->origin = origin;

	bounds.setOrigin(GetBounds(local).width * origin.x, GetBounds(local).height * origin.y);
	textName.setOrigin(GetBounds(local).width * origin.x, GetBounds(local).height * origin.y);
}


sf::Vector2f Pcolader::GetOrigin() const
{
	return origin;
}

sf::Vector2f Pcolader::GetPixelOrigin() const
{
	return bounds.getOrigin();
}
