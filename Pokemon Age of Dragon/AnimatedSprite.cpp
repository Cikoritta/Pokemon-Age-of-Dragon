#include "AnimatedSprite.h"

void AnimatedSprite::animate(Animation animation)
{
	if (state)
	{
		if (!animate_end)
		{
			if (!clock_restart)
			{
				max_left = texture.getSize().x - current_animation.pixel_interval;

				clock.restart();

				clock_restart = true;
			}

			if (clock.getElapsedTime().asSeconds() >= current_animation.time_interval)
			{
				if (current_frame.left == max_left)
				{
					if (current_animation.repeat)
					{
						current_frame.left = 0;
					}
					else
					{
						animate_end = true;

						previous_animation = animation.getID();
					}
				}
				else
				{
					current_frame.left += current_animation.pixel_interval;
				}

				sprite.setTextureRect(current_frame);

				clock.restart();
			}
		}
		else
		{
			if (current_animation.getID() != animation.getID() && previous_animation != animation.getID())
			{
				current_animation = animation;

				animate_end = false;

				current_frame = sf::IntRect(0, 0, sprite.getTextureRect().width, sprite.getTextureRect().height);
			}
		}
	}
}

void AnimatedSprite::longAnimate(LongAnimation long_animation)
{
	if (state)
	{
		if (!animate_end)
		{
			if (!clock_restart)
			{
				max_left = texture.getSize().x - current_long_animation.pixel_interval_x;

				max_top = texture.getSize().y - current_long_animation.pixel_interval_y;

				clock.restart();

				clock_restart = true;
			}

			if (clock.getElapsedTime().asSeconds() >= current_long_animation.time_interval)
			{
				if (current_frame.left == max_left)
				{
					if (current_frame.top == max_top)
					{
						if (current_long_animation.repeat)
						{
							current_frame.left = 0;

							current_frame.top = 0;
						}
						else
						{
							animate_end = true;

							previous_animation = long_animation.getID();
						}
					}
					else
					{
						current_frame.top += current_long_animation.pixel_interval_y;

						current_frame.left = 0;
					}
				}
				else
				{
					current_frame.left += current_long_animation.pixel_interval_x;
				}

				sprite.setTextureRect(current_frame);

				clock.restart();
			}
		}
		else
		{
			if (current_long_animation.getID() != long_animation.getID() && previous_animation != long_animation.getID())
			{
				current_long_animation = long_animation;

				animate_end = false;

				current_frame = sf::IntRect(0, 0, sprite.getTextureRect().width, sprite.getTextureRect().height);
			}
		}
	}
}

bool AnimatedSprite::isAnimateEnd()
{
	return animate_end;
}

void AnimatedSprite::repeatAnimation()
{
	animate_end = false;

	clock_restart = false;

	current_frame = sf::IntRect(0, 0, sprite.getTextureRect().width, sprite.getTextureRect().height);
}

LongAnimation AnimatedSprite::getCurrentAnimation()
{
	if (current_animation.getID() == 0)
	{
		return LongAnimation(current_long_animation.time_interval, current_long_animation.pixel_interval_x, current_long_animation.pixel_interval_y, current_long_animation.repeat);
	}
	else
	{
		return LongAnimation(current_animation.time_interval, current_animation.pixel_interval, 0, current_animation.repeat);
	}
}

void AnimatedSprite::setState(bool stop_play)
{
	state = stop_play;
}

bool AnimatedSprite::getState()
{
	return state;
}
