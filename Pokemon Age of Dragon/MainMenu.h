#pragma once
#include "Scene.h"
#include "SimpleSprite.h"
#include "SimpleText.h"	
#include "AnimatedSprite.h"

class MainMenu : public Scene
{
	AnimatedSprite sprite1;

	bool bol = false;

	void texture() override;

	void sprite() override;

public:

	void			start() override;

	void			update() override;

	void			events() override;

	void			render() override;
};
