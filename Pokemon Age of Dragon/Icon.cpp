#include "Icon.h"

sf::Image Icon::image;


Icon::Icon(std::string locate_icon)
{
	image.loadFromFile(locate_icon);
}


sf::Vector2u Icon::getSize()
{
	return image.getSize();
}

const sf::Uint8* Icon::getPixels()
{
	return image.getPixelsPtr();
}
