#include "pch.h"
#include "Pcolader.h"

Pcolader::Pcolader(sf::RenderWindow* window, sf::Event* event, sf::Vector2f position, sf::Vector2f size, const sf::String coladerName)
{
	this->window = window;
	this->event = event;

	this->position = position;

	this->coladerName = coladerName;

	bounds.setSize(size);
	bounds.setPosition(window->getSize().x * position.x, window->getSize().y * position.y);
	bounds.setFillColor(sf::Color::Transparent);
	bounds.setOutlineColor(sf::Color::Green);
	bounds.setOutlineThickness(1.0f);

	font.loadFromFile("Data/Fonts/System.ttf");
	font.setSmooth(false);

	textName.setFont(font);
	textName.setString(coladerName);
	textName.setCharacterSize(13);
	textName.setFillColor(sf::Color::White);
	textName.setOutlineThickness(1.0f);
	textName.setOutlineColor(sf::Color::Black);
	textName.setPosition(static_cast<int>(window->getSize().x * position.x), static_cast<int>(window->getSize().y * position.y));
}


void Pcolader::SetWindow(sf::RenderWindow* window)
{
	this->window = window;
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

bool Pcolader::IsColision(Pcolader* colader)
{
	if (GetBounds().intersects(colader->GetBounds()))
	{
		bounds.setOutlineColor(sf::Color::Red);

		return true;
	}

	bounds.setOutlineColor(sf::Color::Green);

	return false;
}


void Pcolader::SetPosition(sf::Vector2f position)
{
	this->position = position;

	bounds.setPosition(window->getSize().x * position.x, window->getSize().y * position.y);
	textName.setPosition(window->getSize().x * position.x, window->getSize().y * position.y);
}

void Pcolader::SetPixelPosition(sf::Vector2f position)
{
	bounds.setPosition(position);
	textName.setPosition(position);

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


void Pcolader::SetSize(sf::Vector2f size)
{
	bounds.setSize(size);
}

sf::Vector2f Pcolader::GetSize() const
{
	return bounds.getSize();
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


void Pcolader::SetOrigin(sf::Vector2f origin)
{
	this->origin = origin;

	bounds.setOrigin(GetSize().x * origin.x, GetSize().y * origin.y);
	textName.setOrigin(GetSize().x * origin.x, GetSize().y * origin.y);
}

sf::Vector2f Pcolader::GetOrigin() const
{
	return origin;
}

sf::Vector2f Pcolader::GetPixelOrigin() const
{
	return bounds.getOrigin();
}
