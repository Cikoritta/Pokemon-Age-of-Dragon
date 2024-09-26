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

void SimpleSprite::setPosition(sf::Sprite* start_position, float x, float y)
{
    position = sf::Vector2f(x, y);

    this->start_position = start_position;

    float position_x = (start_position->getPosition().x + (start_position->getGlobalBounds().width * x)) - (getSize().x * getOrigin().x);
    real_position.x = start_position->getPosition().x + (start_position->getGlobalBounds().width * x);

    float position_y = (start_position->getPosition().y + (start_position->getGlobalBounds().height * y)) - (getSize().y * getOrigin().y);
    real_position.y = start_position->getPosition().y + (start_position->getGlobalBounds().height * y);

    sprite.setPosition(position_x, position_y);
}

void SimpleSprite::setOrigin(float x, float y)
{
	origin = sf::Vector2f(x, y);

    if (start_position != nullptr)
    {
        setPosition(start_position, position.x, position.y);
    }
    else
    {
        setPosition(position.x, position.y);
    }
}

void SimpleSprite::setScale(float x, float y)
{
    scale = sf::Vector2f(x * Window::getScale().x, y * Window::getScale().x);

    real_scale = sf::Vector2f(x, y);

    sprite.setScale(scale.x, scale.y);

    if (start_position != nullptr)
    {
        setPosition(start_position, position.x, position.y);
    }
    else
    {
        setPosition(position.x, position.y);
    }
}

sf::Vector2f SimpleSprite::getSize()
{
    return sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

void SimpleSprite::draw()
{
    Window::getWindow()->draw(sprite);
}
