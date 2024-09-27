#pragma once
#include "SimpleSprite.h"

class Animation
{
public:

	Animation() = default;

	Animation(float time_interval, sf::Uint16 pixel_interval, bool repeat = false)
	{
		this->time_interval = time_interval;

		this->pixel_interval = pixel_interval;

		this->repeat = repeat;
	}

	float				time_interval;

	sf::Uint16			pixel_interval;

	bool				repeat = false;

	float 			getID()
	{
		return (float)pixel_interval + time_interval + (float)repeat;
	}
};

class LongAnimation
{
public:

	LongAnimation() = default;

	LongAnimation(float time_interval, sf::Uint16 pixel_interval_x, sf::Uint16 pixel_interval_y, bool repeat = false)
	{
		this->time_interval = time_interval;

		this->pixel_interval_x = pixel_interval_x;

		this->pixel_interval_y = pixel_interval_y;

		this->repeat = repeat;
	}

	float				time_interval;

	sf::Uint16			pixel_interval_x;

	sf::Uint16			pixel_interval_y;

	bool				repeat = false;

	float 			getID()
	{
		return (float)pixel_interval_x + (float)pixel_interval_y + time_interval + (float)repeat;
	}
};

class AnimatedSprite : public SimpleSprite
{
	Animation			current_animation = Animation(0, 0, false);

	LongAnimation		current_long_animation = LongAnimation(0, 0, 0, false);


	float				previous_animation;


	sf::Clock			clock;

	sf::IntRect			current_frame;

	sf::Uint16          max_left;

	sf::Uint16          max_top;


	bool				state = true;

	bool				clock_restart = false;

	bool				animate_end = true;

public:

	void				animate(Animation animation);

	void				longAnimate(LongAnimation long_animation);

	bool				isAnimateEnd();

	void				repeatAnimation();

	LongAnimation		getCurrentAnimation();


	void                setState(bool stop_play);

	bool				getState();	

};
