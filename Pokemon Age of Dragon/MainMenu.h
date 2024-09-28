#pragma once
#include "Scene.h"
#include "Sprite.h"

class MainMenu : public Scene
{
	SimpleSprite sprite1;

	bool move = false;

	void texture() override;

	void sprite() override;

public:

	void			start() override;

	void			update() override;

	void			events() override;

	void			render() override;
};
