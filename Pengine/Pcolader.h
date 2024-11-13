#pragma once
#include <SFML/Graphics.hpp>
#include "Psprite.h"

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


	sf::Vector2f			position = { 0.0f, 0.0f };

	sf::Vector2f			origin = { 0.0f, 0.0f };


	Pcolader*				colisionColader = nullptr;

	sf::Uint8				colision = 0U;

	bool					solid = false;


    Psprite*                sprite = nullptr;


	sf::Uint8               Colision();

public:

	Pcolader();

	Pcolader(sf::RenderWindow* window, sf::Event* event, sf::Vector2f position, sf::Vector2f size, const sf::String coladerName);


	void 				    SetWindow(sf::RenderWindow* window);

	void					SetEvent(sf::Event* event);


	void					SetColaderName(const sf::String coladerName);

	sf::String				GetColaderName() const;


	void					Draw() const;


    void                    SetSprite(Psprite* sprite);


	bool					IsColision(Pcolader* colader);


	void					SetSolid(bool solid);

	bool					IsSolid() const;


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
