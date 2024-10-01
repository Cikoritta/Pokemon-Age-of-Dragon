#pragma once
#include "Drawable.h"
#include "Moving.h"

class SimpleText : public Drawable, public Moving
{
	sf::Text		text;

	sf::Font		font;

public:

	sf::Text*		getText();


	void			setString(std::wstring string);

	std::wstring	getString();


	void			setFont(std::string locate_font);

	void			setPosition(float x, float y) override;

	void		    setPosition(sf::Sprite* start_position, float x, float y) override;

	void			setPosition(Drawable* start_drawable, float x, float y) override;

	void			setOrigin(float x, float y) override;

	void			setScale(float x, float y) override;

	sf::Vector2f	getSize() override;


	void			setTamplate(sf::Text* text);


	void			move(Move move) override;


	void			draw() override;
};