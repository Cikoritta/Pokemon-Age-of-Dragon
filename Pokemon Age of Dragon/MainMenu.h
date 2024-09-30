#pragma once
#include "Scene.h"
#include "Sprite.h"

class MainMenu : public Scene
{
	AnimatedSprite sprite1;

	bool move = false;
	bool move2 = false;

	void texture() override;

	void sprite() override;

public:

	void			start() override;

	void			update() override;

	void			events() override;

	void			render() override;
};
