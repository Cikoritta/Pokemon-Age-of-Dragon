#pragma once
#include <SFML/Graphics/Image.hpp>

class Icon
{
	static sf::Image				image;

public:

	Icon() = default;

	Icon(std::string locate_icon);


	static sf::Vector2u				getSize();

	static const sf::Uint8*			getPixels();
};