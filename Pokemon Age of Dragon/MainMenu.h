#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Text.h"

class MainMenu : public Scene
{
	SplitSprite sprite1;

	SimpleText text1;

	void texture() override;

	void sprite() override;

public:

	void			start() override;

	void			update() override;

	void			events() override;

	void			render() override;
};
