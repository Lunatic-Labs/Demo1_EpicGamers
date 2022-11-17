#include "../include/Player.h"
#include "../include/GameState.h"
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

		animationFrames.push_back(data->assets.GetTexture("Jump Frame 1"));
		animationFrames.push_back(data->assets.GetTexture("Jump Frame 2"));
		animationFrames.push_back(data->assets.GetTexture("Jump Frame 3"));
		animationFrames.push_back(data->assets.GetTexture("Jump Frame 4"));
		animationFrames.push_back(data->assets.GetTexture("Jump Frame 5"));
		animationFrames.push_back(data->assets.GetTexture("Jump Frame 6"));
		animationFrames.push_back(data->assets.GetTexture("Jump Frame 7"));
		animationFrames.push_back(data->assets.GetTexture("Jump Frame 8"));
		animationFrames.push_back(data->assets.GetTexture("Jump Frame 9"));
		animationFrames.push_back(data->assets.GetTexture("Jump Frame 10"));

		playerSprite.setTexture(animationFrames.at(animationIterator));
		//playerSprite.setSize(64.0f, 64.0f);
		playerSprite.setPosition((data->window.getSize().x / 6),
			(data->window.getSize().y / 2) - (playerSprite.getGlobalBounds().height / 2));
		
		playerX = (data->window.getSize().x / 4) - (playerSprite.getGlobalBounds().width / 2);
		playerY = (data->window.getSize().y - playerSprite.getGlobalBounds().height - 138.0f);
		playerState = PLAYER_STATE_STILL;
		ySpeed = 0.0f;
		movementClock.restart();

	
	}

	void Player::draw()
	{
		data->window.draw(playerSprite);
	}

	void Player::animate(float dt)
	{	//if more time has passed than the given frame rate (time spent on current frame compared to total duration)
		if (PLAYER_STATE_JUMPING == playerState || PLAYER_STATE_FALLING == playerState)
		{	//if in air (should trigger when Jump/Tap is triggered
			if (clock.getElapsedTime().asSeconds() > JUMP_DURATION / (animationFrames.size() / 2) )
			{
				if (jumping == false)
				{
					animationIterator = 10;	//Start jump animation
					jumping = true;
				}
				if (animationIterator < 19)
					animationIterator++;
				/*else
					jumping = false;*/
				else if (playerState != PLAYER_STATE_STILL)	//hold on last jump frame while still in air.
				{
					animationIterator = 18;
				}

				playerSprite.setTexture(animationFrames.at(animationIterator));
				clock.restart();
			}
		}
		
		else 
			jumping = false;

		if (clock.getElapsedTime().asSeconds() > PLAYER_ANIMATION_DURATION / (animationFrames.size() / 2) )
		{	//move forward in animation
			if (animationIterator < 9)
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
			ySpeed += GRAVITY;
			playerSprite.move(0, ySpeed * dt);
		}
		else if (PLAYER_STATE_JUMPING == playerState)
		{
			ySpeed = -JUMP_SPEED;
			playerSprite.move(0, ySpeed * dt);			

			data->assets.PlaySound("jump");
		}

		//Update State Machine based on Player's position, after Jumping
		if (playerSprite.getPosition().y >= playerY)
		{
			// play landing sound only on the 1st frame of the Still state
			if (playerState != PLAYER_STATE_STILL)
				data->assets.PlaySound("land");

			playerState = PLAYER_STATE_STILL;
		}
		else if (movementClock.getElapsedTime().asSeconds() > JUMP_DURATION)
		{
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
			//movementClock.restart();
			playerState = PLAYER_STATE_JUMPING;
			//animationIterator = 0;	//Attempted to reset the iterator immediately when ground's touched so JumpAnim called again. Caused the RunAnim to play.
		}
			
	}
	
	const sf::Sprite &Player::GetSprite() const
	{
		return playerSprite;
	}
}
