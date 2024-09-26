#include "SimpleSprite.h"

sf::Sprite* SimpleSprite::getSprite()
{
    return &sprite;
}

void SimpleSprite::setTexture(std::string locate_texture, sf::IntRect rect)
{
	texture.loadFromFile(locate_texture);

    if (rect.width == 0 && rect.height == 0)
    {
        rect.width = texture.getSize().x;

		rect.height = texture.getSize().y;
    }

	sprite.setTexture(texture);

    sprite.setTextureRect(rect);
}

void SimpleSprite::setPosition(float x, float y)
{
    position = sf::Vector2f(x, y);

    float position_x = (Window::getWindow()->getSize().x * x) - (getSize().x * getOrigin().x);
    real_position.x = Window::getWindow()->getSize().x * x;

    float position_y = (Window::getWindow()->getSize().y * y) - (getSize().y * getOrigin().y);
	real_position.y = Window::getWindow()->getSize().y * y;

    sprite.setPosition(position_x, position_y);
}

void SimpleSprite::setOrigin(float x, float y)
{
	origin = sf::Vector2f(x, y);

    setPosition(position.x, position.y);
}

void SimpleSprite::setScale(float x, float y)
{
    scale = sf::Vector2f(x * Window::getScale().x, y * Window::getScale().x);

    real_scale = sf::Vector2f(x, y);

    sprite.setScale(scale.x, scale.y);

    setPosition(position.x, position.y);
}

sf::Vector2f SimpleSprite::getSize()
{
    return sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

void SimpleSprite::draw()
{
    Window::getWindow()->draw(sprite);
}
