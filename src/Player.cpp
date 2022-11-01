#include "../include/Player.h"
#include <iostream>

namespace EpicGamers
{
	Player::Player(GameDataRef _data) : data(_data)
	{
		animationIterator = 0;
		animationFrames.push_back(data->assets.GetTexture("Player Frame 1"));	//Repeat for every frame of Player animation in DEFINITIONS.h

		playerSprite.setTexture(animationFrames.at(animationIterator));
		playerSprite.setPosition((data->window.getSize().x / 4) - (playerSprite.getGlobalBounds().width / 2),	//set x position
			(data->window.getSize().y / 2) - (playerSprite.getGlobalBounds().height / 2));						//set y position.
		
		playerState = PLAYER_STATE_STILL;
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

	void Player::update(float dt)
	{
		if (PLAYER_STATE_STILL == playerState)			//Player is on ground
		{
			playerSprite.move(0,0);
		}
		else if (PLAYER_STATE_FALLING == playerState)	
		{
			playerSprite.move(0, GRAVITY * dt);
		}
		else if (PLAYER_STATE_JUMPING == playerState)	//Jump input received
		{
			playerSprite.move(0, -JUMP_SPEED * dt);
		}

		if (movementClock.getElapsedTime().asSeconds() > JUMP_DURATION)	//NEEDED: && position is above ground level
		{
			movementClock.restart();
			playerState = PLAYER_STATE_FALLING;
		}
	}

	void Player::tap()
	{
		movementClock.restart();
		playerState = PLAYER_STATE_JUMPING;
	}

}