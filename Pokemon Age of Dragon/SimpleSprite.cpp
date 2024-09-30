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

    float position_x; float position_y;

    if (x > 0.0000f)
    {
        position_x = (Window::getWindow()->getSize().x * x) - (getSize().x * getOrigin().x);
        real_position.x = (float)Window::getWindow()->getSize().x * x;
    }
    else
    {
        position_x = Window::getWindow()->getSize().x - (getSize().x * getOrigin().x);
        real_position.x = (float)Window::getWindow()->getSize().x;
    }

    if (y > 0.0000f)
    {
        position_y = (Window::getWindow()->getSize().y * y) - (getSize().y * getOrigin().y);
        real_position.y = (float)Window::getWindow()->getSize().y * y;
    }
    else
    {
        position_y = Window::getWindow()->getSize().y - (getSize().y * getOrigin().y);
        real_position.y = (float)Window::getWindow()->getSize().y;
    }

    sprite.setPosition((int)position_x, (int)position_y);
}

void SimpleSprite::setPosition(sf::Sprite* start_position, float x, float y)
{
    position = sf::Vector2f(x, y);

    this->start_position = start_position;

    float position_x; float position_y;

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

    sprite.setPosition((int)position_x, (int)position_y);
}

void SimpleSprite::setPosition(sf::Vector2f position, sf::Vector2f size, float x, float y)
{
    position = sf::Vector2f(x, y);

    this->start_position = new sf::Sprite();

	this->start_position->setPosition(position);

    float position_x; float position_y;

    if (x > 0.0000f)
    {
        position_x = (start_position->getPosition().x + (size.x * x)) - (getSize().x * getOrigin().x);
        real_position.x = start_position->getPosition().x + (size.x * x);
    }
    else
    {
        position_x = start_position->getPosition().x - (getSize().x * getOrigin().x);
        real_position.x = start_position->getPosition().x;
    }

    if (y > 0.0000f)
    {
        position_y = (start_position->getPosition().y + (size.y * y)) - (getSize().y * getOrigin().y);
        real_position.y = start_position->getPosition().y + (size.y * y);
    }
    else
    {
        position_y = start_position->getPosition().y - (getSize().y * getOrigin().y);
        real_position.y = start_position->getPosition().y;
    }

    sprite.setPosition((int)position_x, (int)position_y);
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

void SimpleSprite::move(Move move)
{
    if (!move_end)
    {
        if (!clock_restart)
        {
            if (sprite.getPosition().x + (getSize().x * getOrigin().x) < current_move.position.x)
            {
                move_direction.x = true;

                distance.x = abs(sprite.getPosition().x - current_move.position.x) - (getSize().x * getOrigin().x);
            }
            else
            {
                distance.x = abs(sprite.getPosition().x - current_move.position.x) + (getSize().x * getOrigin().x);
            }
            if (sprite.getPosition().y + (getSize().y * getOrigin().y) < current_move.position.y)
            {
                move_direction.y = true;

				distance.y = abs(sprite.getPosition().y - current_move.position.y) - (getSize().y * getOrigin().y);
            }
            else
            {
                distance.y = abs(sprite.getPosition().y - current_move.position.y) + (getSize().y * getOrigin().y);
            }

            scale_factor = fmax(distance.x, distance.y) / fmin(distance.x, distance.y);
            
            end_position = sf::Vector2f(current_move.position.x - (getSize().x * getOrigin().x), current_move.position.y - (getSize().y * getOrigin().y));

            if (distance.x > distance.y)
            {
                x_larger_y = true;
            }

            clock.restart();

            clock_restart = true;
        }

        if (clock.getElapsedTime().asSeconds() >= current_move.time_interval)
        {
            if ((move_direction.x && sprite.getPosition().x < end_position.x) || (!move_direction.x && sprite.getPosition().x > end_position.x))
            {
                if (x_larger_y)
                {
                    if (move_direction.x)
                    {
                        sprite.setPosition(sprite.getPosition().x + (current_move.pixel_interval * scale_factor), sprite.getPosition().y);
                    }
                    else
                    {
                        sprite.setPosition(sprite.getPosition().x - (current_move.pixel_interval * scale_factor), sprite.getPosition().y);
                    }
                }
                else
                {
                    if (move_direction.x)
                    {
                        sprite.setPosition(sprite.getPosition().x + current_move.pixel_interval, sprite.getPosition().y);
                    }
                    else
                    {
                        sprite.setPosition(sprite.getPosition().x - current_move.pixel_interval, sprite.getPosition().y);
                    }
                }
            }

            if ((move_direction.y && sprite.getPosition().y < end_position.y) || (!move_direction.y && sprite.getPosition().y > end_position.y))
            {
                if (x_larger_y)
                {
                    if (move_direction.y)
                    {
                        sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + current_move.pixel_interval);
                    }
                    else
                    {
                        sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - current_move.pixel_interval);
                    }
                }
                else
                {
                    if (move_direction.y)
                    {
                        sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + (current_move.pixel_interval * scale_factor));
                    }
                    else
                    {
                        sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (current_move.pixel_interval * scale_factor));
                    }
                }
            }
            else
            {
                move_end = true;
            }

            

            clock.restart();
        }

        if (move_end)
        {
            sprite.setPosition(end_position);

            previous_move = move.getID();

            move_end = true;
        }
    }
    else
    {
        if (current_move.getID() != move.getID() && previous_move != move.getID())
        {
            current_move = move;

            x_larger_y = false;

            clock_restart = false;

            move_direction = sf::Vector2<bool>(false, false);

			move_end = false;
        }
    }
}

void SimpleSprite::draw()
{
    Window::getWindow()->draw(sprite);
}
