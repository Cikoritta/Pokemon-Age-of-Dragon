#pragma once
#include "Drawable.h"
#include "Moving.h"

class SplitSprite : public Drawable, public Moving
{
	sf::Texture texture;

	float width;

	float height;

	sf::Vector2f border_scale = sf::Vector2f(1.0f, 1.0f);

	sf::Sprite top_left;
	sf::Sprite top;
	sf::Sprite top_right;

	sf::Sprite left;
	sf::Sprite center;
	sf::Sprite right;

	sf::Sprite bottom_left;
	sf::Sprite bottom;
	sf::Sprite bottom_right;

public:

	void			setTexture(std::string locate_texture, sf::IntRect rect[9]);


	void			setPosition(float x, float y) override;

	void		    setPosition(sf::Sprite* start_position, float x, float y) override;

	void			setPosition(sf::Vector2f position, sf::Vector2f size, float x, float y) override;

	void			setOrigin(float x, float y) override;

	void			setScale(float x, float y) override;

	void            setSmartScale(float x, float y);

	void			setBorderScale(float x, float y);

	sf::Vector2f	getBorderScale();

	sf::Vector2f	getSize() override;


	void			move(Move move) override;


	void			draw() override;
};
