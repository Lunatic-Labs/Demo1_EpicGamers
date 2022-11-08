#include "../include/Player.h"
#include <iostream>

namespace EpicGamers
{
	Player::Player(GameDataRef _data) : data(_data)
	{
		animationIterator = 0;
		animationFrames.push_back(data->assets.GetTexture("Player Frame 1"));	//Repeat for every frame of Player animation in DEFINITIONS.h
		animationFrames.push_back(data->assets.GetTexture("Player Frame 2"));
		animationFrames.push_back(data->assets.GetTexture("Player Frame 3"));
		animationFrames.push_back(data->assets.GetTexture("Player Frame 4"));
		animationFrames.push_back(data->assets.GetTexture("Player Frame 5"));
		animationFrames.push_back(data->assets.GetTexture("Player Frame 6"));
		animationFrames.push_back(data->assets.GetTexture("Player Frame 7"));
		animationFrames.push_back(data->assets.GetTexture("Player Frame 8"));
		animationFrames.push_back(data->assets.GetTexture("Player Frame 9"));
		animationFrames.push_back(data->assets.GetTexture("Player Frame 10"));	//Assuming we'll also need to repeat this for the Jump animation frames.

		playerSprite.setTexture(animationFrames.at(animationIterator));
		//playerSprite.setSize(64.0f, 64.0f);
		playerSprite.setPosition((data->window.getSize().x / 6),
			(data->window.getSize().y / 2) - (playerSprite.getGlobalBounds().height / 2));
		
		playerX = (data->window.getSize().x / 4) - (playerSprite.getGlobalBounds().width / 2);
		playerY = (data->window.getSize().y - playerSprite.getGlobalBounds().height - 138.0f);
		playerState = PLAYER_STATE_STILL;
		movementClock.restart();
	
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
		//Movement responses to State Machine 
		if (PLAYER_STATE_STILL == playerState)
		{
			playerSprite.move(0, 0);
		}
		else if (PLAYER_STATE_FALLING == playerState)
		{
			playerSprite.move(0, GRAVITY * dt);
		}
		else if (PLAYER_STATE_JUMPING == playerState)
		{
			playerSprite.move(0, -JUMP_SPEED * dt);
		}

		//Update State Machine based on Player's position, after Jumping
		if (playerSprite.getPosition().y >= playerY)
		{
			playerState = PLAYER_STATE_STILL;
		}
		else if (movementClock.getElapsedTime().asSeconds() > JUMP_DURATION)
		{
			movementClock.restart();
			playerState = PLAYER_STATE_FALLING;
		}
		//Bring Player from left to desired X, intro functionality
		if (playerSprite.getPosition().x < playerX)
		{
			playerSprite.move(playerX - playerSprite.getPosition().x, 0);
		}
	}

	void Player::tap()	//Update State Machine when input received
	{
		if (playerState != PLAYER_STATE_JUMPING && playerState != PLAYER_STATE_FALLING)
		{
			movementClock.restart();
			playerState = PLAYER_STATE_JUMPING;
		}
	}
}
