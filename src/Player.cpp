#include "../include/Player.h"
#include <iostream>

namespace EpicGamers
{
	Player::Player(GameDataRef _data) : data(_data)
	{
		animationIterator = 0;
		animationFrames.push_back(data->assets.GetTexture("Player Frame 1"));	//Repeat for every frame of Player animation in DEFINITIONS.h

		playerSprite.setTexture(animationFrames.at(animationIterator));
	}

	void Player::draw()
	{
		data->window.draw(playerSprite);
	}

	void Player::animate(float dt)
	{	//if more time has passed than the given frame rate (time spent on current frame compared to total duration)
		if (clock.getElapsedTime().asSeconds() > PLAYER_ANIMATION_DURATION / animationFrames.size())
		{	//move forward in animation
			if (animationIterator < (animationFrames.size() - 1))
				animationIterator++;
			else
				animationIterator = 0;
			
			playerSprite.setTexture(animationFrames.at(animationIterator));
			clock.restart();
		}
	}
}