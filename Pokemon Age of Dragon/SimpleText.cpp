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

    text.setPosition(position_x, position_y);
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

    text.setPosition(position_x, position_y);
}

void SimpleText::setOrigin(float x, float y)
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


void SimpleText::draw()
{
    Window::getWindow()->draw(text);
}
