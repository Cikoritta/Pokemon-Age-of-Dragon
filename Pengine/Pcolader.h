#pragma once
#include <SFML/Graphics.hpp>

class RectangleBounds
{
public:

	sf::Vector2f topLeft;

	sf::Vector2f topRight;


	sf::Vector2f bottomLeft;

	sf::Vector2f bottomRight;


	RectangleBounds() = default;

	RectangleBounds(sf::Vector2f topLeft, sf::Vector2f topRight, sf::Vector2f bottomLeft, sf::Vector2f bottomRight)
	{
		this->topLeft = topLeft;
		this->topRight = topRight;

		this->bottomLeft = bottomLeft;
		this->bottomRight = bottomRight;
	}
};


class Pcolader
{
	sf::RenderWindow*		window = nullptr;

	sf::Event*				event = nullptr;


	sf::RectangleShape		bounds;


	sf::Font				font;

	sf::Text				textName;


	sf::String				coladerName = "none";


	sf::Vector2f			position = { 0, 0 };

	sf::Vector2f			origin = { 0, 0 };

public:

	Pcolader() = default;

	Pcolader(sf::RenderWindow* window, sf::Event* event, sf::Vector2f position, sf::Vector2f size, const sf::String coladerName);


	void 				    SetWindow(sf::RenderWindow* window);

	void					SetEvent(sf::Event* event);


	void					SetColaderName(const sf::String coladerName);

	sf::String				GetColaderName() const;


	void					Draw() const;

	bool					IsColision(Pcolader* colader);


	void					SetPosition(sf::Vector2f position);

	void					SetPixelPosition(sf::Vector2f position);

	sf::Vector2f			GetPosition() const;

	sf::Vector2f			GetPixelPosition() const;

	sf::Vector2f			GetRealPosition() const;


	void					SetSize(sf::Vector2f size);

	sf::Vector2f			GetSize() const;


	sf::FloatRect			GetBounds(bool local = false) const;

	RectangleBounds			GetRectangleBounds() const;


	void					SetOrigin(sf::Vector2f origin);

	sf::Vector2f			GetOrigin() const;

	sf::Vector2f			GetPixelOrigin() const;
};
