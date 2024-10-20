#include "SimpleText.h"

sf::Text* SimpleText::getText()
{
    return &text;
}


void SimpleText::setString(std::wstring string)
{
    text.setString(string);
}

std::wstring SimpleText::getString()
{
    return text.getString();
}


void SimpleText::setFont(std::string locate_font)
{
    font.loadFromFile(locate_font);

    text.setFont(font);
}


void SimpleText::setPosition(float x, float y)
{
    position = sf::Vector2f(x, y);

    float position_x; float position_y;

    if (x > 0.0000f)
    {
        position_x = (Window::getWindow()->getSize().x * x) - (getSize().x * getOrigin().x);
        real_position.x = Window::getWindow()->getSize().x * x;
    }
    else
    {
        position_x = Window::getWindow()->getSize().x - (getSize().x * getOrigin().x);
        real_position.x = Window::getWindow()->getSize().x;
    }

    if (y > 0.0000f)
    {
        position_y = (Window::getWindow()->getSize().y * y) - (getSize().y * getOrigin().y);
        real_position.y = Window::getWindow()->getSize().y * y;
    }
    else
    {
        position_y = Window::getWindow()->getSize().y - (getSize().y * getOrigin().y);
        real_position.y = Window::getWindow()->getSize().y;
    }

    text.setPosition(round(position_x), round(position_y));
}

void SimpleText::setPosition(sf::Sprite* start_position, float x, float y)
{
    position = sf::Vector2f(x, y);

    this->start_position = start_position;

    float position_x; float position_y;

    if (x > 0.0000f)
    {
        position_x = ((start_position->getPosition().x + (start_position->getGlobalBounds().width * x)) - (text.getGlobalBounds().width * getOrigin().x) - text.getLocalBounds().left);
        real_position.x = start_position->getPosition().x + (start_position->getGlobalBounds().width * x);
    }
    else
    {
        position_x = start_position->getPosition().x - (text.getGlobalBounds().width * getOrigin().x) - text.getLocalBounds().left;
        real_position.x = start_position->getPosition().x - text.getLocalBounds().left;
    }

    if (y > 0.0000f)
    {
        position_y = ((start_position->getPosition().y + (start_position->getGlobalBounds().height * y)) - (text.getGlobalBounds().height * getOrigin().y) - text.getLocalBounds().top);
        real_position.y = start_position->getPosition().y + (start_position->getGlobalBounds().height * y);
    }
    else
    {
        position_y = start_position->getPosition().y - (text.getGlobalBounds().height * getOrigin().y) - text.getLocalBounds().top;
        real_position.y = start_position->getPosition().y - text.getLocalBounds().top;
    }

    text.setPosition(round(position_x), round(position_y));
}

void SimpleText::setPosition(Drawable* start_drawable, float x, float y)
{
    position = sf::Vector2f(x, y);

    this->start_drawable = start_drawable;

    float position_x; float position_y;

    if (x > 0.0000f)
    {
        position_x = ((start_drawable->getRealPosition().x + (start_drawable->getSize().x * x)) - (text.getGlobalBounds().width * getOrigin().x) - text.getLocalBounds().left) - (start_drawable->getSize().x * start_drawable->getOrigin().x);
        real_position.x = start_drawable->getRealPosition().x + (start_drawable->getSize().x * x) - (start_drawable->getSize().x * start_drawable->getOrigin().x);
    }
    else
    {
        position_x = start_drawable->getRealPosition().x - (text.getGlobalBounds().width * getOrigin().x) - text.getLocalBounds().left;
        real_position.x = start_drawable->getRealPosition().x - text.getLocalBounds().left;
    }

    if (y > 0.0000f)
    {
        position_y = ((start_drawable->getRealPosition().y + (start_drawable->getSize().y * y)) - (text.getGlobalBounds().height * getOrigin().y) - text.getLocalBounds().top) - (start_drawable->getSize().y * start_drawable->getOrigin().y);
        real_position.y = start_drawable->getRealPosition().y + (start_drawable->getSize().y * y) - (start_drawable->getSize().y * start_drawable->getOrigin().y);
    }
    else
    {
        position_y = start_drawable->getRealPosition().y - (text.getGlobalBounds().height * getOrigin().y) - text.getLocalBounds().top;
        real_position.y = start_drawable->getRealPosition().y - text.getLocalBounds().top;
    }

    text.setPosition(round(position_x), round(position_y));
}

void SimpleText::setOrigin(float x, float y)
{
    origin = sf::Vector2f(x, y);

    real_origin = sf::Vector2f(getSize().x * x, getSize().y * y);

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

void SimpleText::setScale(float x, float y)
{
    scale = sf::Vector2f(x * Window::getScale().x, y * Window::getScale().x);

    real_scale = sf::Vector2f(x, y);

    text.setScale(scale.x, scale.y);

    if (start_position != nullptr)
    {
        setPosition(start_position, position.x, position.y);
    }
    else
    {
        setPosition(position.x, position.y);
    }
}

sf::Vector2f SimpleText::getSize()
{
    return sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
}


void SimpleText::setTamplate(sf::Text* text)
{
    this->text.setCharacterSize(text->getCharacterSize());
    this->text.setFillColor(text->getFillColor());
    this->text.setFont(*text->getFont());
    this->text.setLetterSpacing(text->getLetterSpacing());
    this->text.setLineSpacing(text->getLineSpacing());
    this->text.setOutlineColor(text->getOutlineColor());
    this->text.setOutlineThickness(text->getOutlineThickness());
    this->text.setStyle(text->getStyle());
}

void SimpleText::move(Move move)
{
    if (!move_end)
    {
        if (!clock_restart)
        {
            if (text.getPosition().x + (getSize().x * getOrigin().x) < current_move.position.x)
            {
                move_direction.x = true;

                distance.x = abs(text.getPosition().x - current_move.position.x) - (getSize().x * getOrigin().x);
            }
            else
            {
                distance.x = abs(text.getPosition().x - current_move.position.x) + (getSize().x * getOrigin().x);
            }
            if (text.getPosition().y + (getSize().y * getOrigin().y) < current_move.position.y)
            {
                move_direction.y = true;

                distance.y = abs(text.getPosition().y - current_move.position.y) - (getSize().y * getOrigin().y);
            }
            else
            {
                distance.y = abs(text.getPosition().y - current_move.position.y) + (getSize().y * getOrigin().y);
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
            if ((move_direction.x && text.getPosition().x < end_position.x) || (!move_direction.x && text.getPosition().x > end_position.x))
            {
                if (x_larger_y)
                {
                    if (move_direction.x)
                    {
                        text.setPosition(text.getPosition().x + (current_move.pixel_interval * scale_factor), text.getPosition().y);
                    }
                    else
                    {
                        text.setPosition(text.getPosition().x - (current_move.pixel_interval * scale_factor), text.getPosition().y);
                    }
                }
                else
                {
                    if (move_direction.x)
                    {
                        text.setPosition(text.getPosition().x + current_move.pixel_interval, text.getPosition().y);
                    }
                    else
                    {
                        text.setPosition(text.getPosition().x - current_move.pixel_interval, text.getPosition().y);
                    }
                }
            }

            if ((move_direction.y && text.getPosition().y < end_position.y) || (!move_direction.y && text.getPosition().y > end_position.y))
            {
                if (x_larger_y)
                {
                    if (move_direction.y)
                    {
                        text.setPosition(text.getPosition().x, text.getPosition().y + current_move.pixel_interval);
                    }
                    else
                    {
                        text.setPosition(text.getPosition().x, text.getPosition().y - current_move.pixel_interval);
                    }
                }
                else
                {
                    if (move_direction.y)
                    {
                        text.setPosition(text.getPosition().x, text.getPosition().y + (current_move.pixel_interval * scale_factor));
                    }
                    else
                    {
                        text.setPosition(text.getPosition().x, text.getPosition().y - (current_move.pixel_interval * scale_factor));
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
            text.setPosition(end_position);

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


void SimpleText::draw()
{
    Window::getWindow()->draw(text);
}
