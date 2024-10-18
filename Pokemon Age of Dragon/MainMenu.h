#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Text.h"
#include "Input.h"

class MainMenu : public Scene
{
	AnimatedSprite background;

	AnimatedSprite logo;

	void texture() override;

	void sprite() override;

public:

	void			start() override;

	void			update() override;

	void			events() override;

	void			render() override;
};
