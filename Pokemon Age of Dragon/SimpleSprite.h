#pragma once
#include "Drawable.h"

class SimpleSprite : public Drawable
{
	sf::Sprite		sprite;

	sf::Texture		texture;

public:

	sf::Sprite*		getSprite();

	void			setTexture(std::string locate_texture, sf::IntRect rect = sf::IntRect(0, 0, 0, 0));

	void			setPosition(float x, float y) override;

	void			setOrigin(float x, float y) override;

	void			setScale(float x, float y) override;

	sf::Vector2f	getSize() override;

	void			draw() override;
};