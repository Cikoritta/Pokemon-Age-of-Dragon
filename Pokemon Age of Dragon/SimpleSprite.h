#pragma once
#include "Drawable.h"
#include "Moving.h"

class SimpleSprite : public Drawable, public Moving
{
protected:

	sf::Sprite		sprite;

	sf::Texture		texture;

public:

	sf::Sprite*		getSprite();


	void			setTexture(std::string locate_texture, sf::IntRect rect = sf::IntRect(0, 0, 0, 0));


	void			setPosition(float x, float y) override;

	void		    setPosition(sf::Sprite* start_position, float x, float y) override;

	void			setOrigin(float x, float y) override;

	void			setScale(float x, float y) override;

	sf::Vector2f	getSize() override;


	void			move(Move move) override;


	void			draw() override;
};