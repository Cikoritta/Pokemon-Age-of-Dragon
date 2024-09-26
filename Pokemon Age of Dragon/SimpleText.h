#pragma once
#include "Drawable.h"

class SimpleText : public Drawable
{
	sf::Text		text;

public:

	sf::Text*		getText();

	void			setPosition(float x, float y) override;

	void			setOrigin(float x, float y) override;

	void			setScale(float x, float y) override;

	sf::Vector2f	getSize() override;

	void			draw() override;
};