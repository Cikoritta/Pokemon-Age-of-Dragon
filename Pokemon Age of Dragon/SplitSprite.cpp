#include "SplitSprite.h"

void SplitSprite::setTexture(std::string locate_texture, sf::IntRect rect[9])
{
	texture.loadFromFile(locate_texture);

	top_left.setTexture(texture);
	top_left.setTextureRect(rect[0]);

	top.setTexture(texture);
	top.setTextureRect(rect[1]);

	top_right.setTexture(texture);
	top_right.setTextureRect(rect[2]);


	left.setTexture(texture);
	left.setTextureRect(rect[3]);

	center.setTexture(texture);
	center.setTextureRect(rect[4]);

	right.setTexture(texture);
	right.setTextureRect(rect[5]);


	bottom_left.setTexture(texture);
	bottom_left.setTextureRect(rect[6]);

	bottom.setTexture(texture);
	bottom.setTextureRect(rect[7]);

	bottom_right.setTexture(texture);
	bottom_right.setTextureRect(rect[8]);
}


void SplitSprite::setPosition(float x, float y)
{
    position = sf::Vector2f(x, y);

    float position_x; float position_y;

    width = std::max(top_left.getGlobalBounds().width, std::max(left.getGlobalBounds().width, bottom_left.getGlobalBounds().width)) +
        std::max(top.getGlobalBounds().width, std::max(center.getGlobalBounds().width, bottom.getGlobalBounds().width)) +
        std::max(top_right.getGlobalBounds().width, std::max(right.getGlobalBounds().width, bottom_right.getGlobalBounds().width));

    height = std::max(top_left.getGlobalBounds().height, std::max(top.getGlobalBounds().height, top_right.getGlobalBounds().height)) +
        std::max(left.getGlobalBounds().height, std::max(center.getGlobalBounds().height, right.getGlobalBounds().height)) +
        std::max(bottom_left.getGlobalBounds().height, std::max(bottom.getGlobalBounds().height, bottom_right.getGlobalBounds().height));

    if (x > 0.0000f)
    {
        position_x = (Window::getWindow()->getSize().x * x) - (getSize().x * getOrigin().x);
        real_position.x = (float)Window::getWindow()->getSize().x * x;
    }
    else
    {
        position_x = 0.0f - (getSize().x * getOrigin().x);
        real_position.x = 0.0f;
    }

    if (y > 0.0000f)
    {
        position_y = (Window::getWindow()->getSize().y * y) - (getSize().y * getOrigin().y);
        real_position.y = (float)Window::getWindow()->getSize().y * y;
    }
    else
    {
        position_y = 0.0f - (getSize().y * getOrigin().y);
        real_position.y = 0.0f;
    }

    top_left.setPosition(round(position_x), round(position_y));
    top.setPosition(top_left.getPosition().x + top_left.getGlobalBounds().width, top_left.getPosition().y);
    top_right.setPosition(top.getPosition().x + top.getGlobalBounds().width, top.getPosition().y);

    left.setPosition(top_left.getPosition().x, top_left.getPosition().y + top_left.getGlobalBounds().height);
    center.setPosition(left.getPosition().x + left.getGlobalBounds().width, left.getPosition().y);
    right.setPosition(center.getPosition().x + center.getGlobalBounds().width, center.getPosition().y);

    bottom_left.setPosition(left.getPosition().x, left.getPosition().y + left.getGlobalBounds().height);
    bottom.setPosition(bottom_left.getPosition().x + bottom_left.getGlobalBounds().width, bottom_left.getPosition().y);
    bottom_right.setPosition(bottom.getPosition().x + bottom.getGlobalBounds().width, bottom.getPosition().y);
}

void SplitSprite::setPosition(sf::Sprite* start_position, float x, float y)
{
    position = sf::Vector2f(x, y);

    this->start_position = start_position;

    float position_x; float position_y;

    width = std::max(top_left.getGlobalBounds().width, std::max(left.getGlobalBounds().width, bottom_left.getGlobalBounds().width)) +
        std::max(top.getGlobalBounds().width, std::max(center.getGlobalBounds().width, bottom.getGlobalBounds().width)) +
        std::max(top_right.getGlobalBounds().width, std::max(right.getGlobalBounds().width, bottom_right.getGlobalBounds().width));

    height = std::max(top_left.getGlobalBounds().height, std::max(top.getGlobalBounds().height, top_right.getGlobalBounds().height)) +
        std::max(left.getGlobalBounds().height, std::max(center.getGlobalBounds().height, right.getGlobalBounds().height)) +
        std::max(bottom_left.getGlobalBounds().height, std::max(bottom.getGlobalBounds().height, bottom_right.getGlobalBounds().height));

    if (x > 0.0000f)
    {
        position_x = (start_position->getPosition().x + (start_position->getGlobalBounds().width * x)) - (getSize().x * getOrigin().x);
        real_position.x = start_position->getPosition().x + (start_position->getGlobalBounds().width * x);
    }
    else
    {
        position_x = start_position->getPosition().x - (getSize().x * getOrigin().x);
        real_position.x = start_position->getPosition().x;
    }

    if (y > 0.0000f)
    {
        position_y = (start_position->getPosition().y + (start_position->getGlobalBounds().height * y)) - (getSize().y * getOrigin().y);
        real_position.y = start_position->getPosition().y + (start_position->getGlobalBounds().height * y);
    }
    else
    {
        position_y = start_position->getPosition().y - (getSize().y * getOrigin().y);
        real_position.y = start_position->getPosition().y;
    }

    top_left.setPosition(round(position_x), round(position_y));
    top.setPosition(top_left.getPosition().x + top_left.getGlobalBounds().width, top_left.getPosition().y);
    top_right.setPosition(top.getPosition().x + top.getGlobalBounds().width, top.getPosition().y);

    left.setPosition(top_left.getPosition().x, top_left.getPosition().y + top_left.getGlobalBounds().height);
    center.setPosition(left.getPosition().x + left.getGlobalBounds().width, left.getPosition().y);
    right.setPosition(center.getPosition().x + center.getGlobalBounds().width, center.getPosition().y);

    bottom_left.setPosition(left.getPosition().x, left.getPosition().y + left.getGlobalBounds().height);
    bottom.setPosition(bottom_left.getPosition().x + bottom_left.getGlobalBounds().width, bottom_left.getPosition().y);
    bottom_right.setPosition(bottom.getPosition().x + bottom.getGlobalBounds().width, bottom.getPosition().y);
}

void SplitSprite::setPosition(Drawable* start_drawable, float x, float y)
{
    position = sf::Vector2f(x, y);

    this->start_drawable = start_drawable;

    this->start_position->setPosition(position);

    float position_x; float position_y;

    if (x > 0.0000f)
    {
        position_x = (start_drawable->getRealPosition().x + (start_drawable->getSize().x * x)) - (getSize().x * getOrigin().x);
        real_position.x = start_drawable->getRealPosition().x + (start_drawable->getSize().x * x);
    }
    else
    {
        position_x = start_drawable->getRealPosition().x - (getSize().x * getOrigin().x);
        real_position.x = start_drawable->getRealPosition().x;
    }

    if (y > 0.0000f)
    {
        position_y = (start_drawable->getRealPosition().y + (start_drawable->getSize().y * y)) - (getSize().y * getOrigin().y);
        real_position.y = start_drawable->getRealPosition().y + (start_drawable->getSize().y * y);
    }
    else
    {
        position_y = start_drawable->getPosition().y - (getSize().y * getOrigin().y);
        real_position.y = start_drawable->getPosition().y;
    }

    top_left.setPosition(round(position_x), round(position_y));
}

void SplitSprite::setOrigin(float x, float y)
{
    origin = sf::Vector2f(x, y);

    if (start_position != nullptr)
    {
        setPosition(start_position, position.x, position.y);
    }
    else if (start_drawable != nullptr)
    {
        setPosition(start_drawable, position.x, position.y);
    }
    else
    {
        setPosition(position.x, position.y);
    }
}

void SplitSprite::setScale(float x, float y)
{
    scale = sf::Vector2f(x * Window::getScale().x, y * Window::getScale().x);

    real_scale = sf::Vector2f(x, y);

    top_left.setScale(scale.x, scale.y);
	top.setScale(scale.x, scale.y);
	top_right.setScale(scale.x, scale.y);

	left.setScale(scale.x, scale.y);
	center.setScale(scale.x, scale.y);
	right.setScale(scale.x, scale.y);

	bottom_left.setScale(scale.x, scale.y);
	bottom.setScale(scale.x, scale.y);
	bottom_right.setScale(scale.x, scale.y);

    if (start_position != nullptr)
    {
        setPosition(start_position, position.x, position.y);
    }
    else
    {
        setPosition(position.x, position.y);
    }
}

void SplitSprite::setSmartScale(float x, float y)
{
    scale = sf::Vector2f(x * Window::getScale().x, y * Window::getScale().x);

    real_scale = sf::Vector2f(x, y);

    float scale_factor = fmax(x, y) / fmin(x, y);

    if (x >= y)
    {
        top_left.setScale(scale.x * border_scale.x, scale.y * scale_factor * border_scale.y);
        top.setScale(scale.x, scale.y * scale_factor * border_scale.y);
        top_right.setScale(scale.x * border_scale.x, scale.y * scale_factor * border_scale.y);

        left.setScale(scale.x * border_scale.x, scale.y);
        center.setScale(scale.x, scale.y);
        right.setScale(scale.x * border_scale.x, scale.y);

        bottom_left.setScale(scale.x * border_scale.x, scale.y * scale_factor * border_scale.y);
        bottom.setScale(scale.x, scale.y * scale_factor * border_scale.y);
        bottom_right.setScale(scale.x * border_scale.x, scale.y * scale_factor * border_scale.y);
    }
    else
    {
        top_left.setScale(scale.x * scale_factor * border_scale.x, scale.y * border_scale.y);
        top.setScale(scale.x, scale.y * border_scale.y);
        top_right.setScale(scale.x * scale_factor * border_scale.x, scale.y * border_scale.y);

        left.setScale(scale.x * scale_factor * border_scale.x, scale.y);
        center.setScale(scale.x, scale.y);
        right.setScale(scale.x * scale_factor * border_scale.x, scale.y);

        bottom_left.setScale(scale.x * scale_factor * border_scale.x, scale.y * border_scale.y);
        bottom.setScale(scale.x, scale.y * border_scale.y);
        bottom_right.setScale(scale.x * scale_factor * border_scale.x, scale.y * border_scale.y);
    }

    if (start_position != nullptr)
    {
        setPosition(start_position, position.x, position.y);
    }
    else
    {
        setPosition(position.x, position.y);
    }
}

void SplitSprite::setBorderScale(float x, float y)
{
    border_scale = sf::Vector2f(x, y);

    setSmartScale(real_scale.x, real_scale.y);
}

sf::Vector2f SplitSprite::getBorderScale()
{
    return border_scale;
}

sf::Vector2f SplitSprite::getSize()
{
    return sf::Vector2f(width, height);
}


void SplitSprite::move(Move move)
{

}

void SplitSprite::draw()
{
	Window::getWindow()->draw(top_left);
	Window::getWindow()->draw(top);
	Window::getWindow()->draw(top_right);

	Window::getWindow()->draw(left);
	Window::getWindow()->draw(center);
    Window::getWindow()->draw(right);

	Window::getWindow()->draw(bottom_left);
	Window::getWindow()->draw(bottom);
	Window::getWindow()->draw(bottom_right);
}
