#pragma once
#include "Scene.h"
#include "SimpleSprite.h"
#include "SimpleText.h"

#include <SFML/Graphics.hpp>

class MainMenu : public Scene
{
	SimpleSprite sprite1;

	SimpleText sprite2;

	sf::RectangleShape a;

	void texture() override;

	void sprite() override;

public:

	void			start() override;

	void			update() override;

	void			events() override;

	void			render() override;
};
