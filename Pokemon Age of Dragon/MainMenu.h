#pragma once
#include "Scene.h"
#include "SimpleSprite.h"

class MainMenu : public Scene
{
	SimpleSprite sprite1;

	void texture() override;

	void sprite() override;

public:

	void			start() override;

	void			update() override;

	void			events() override;

	void			render() override;
};
