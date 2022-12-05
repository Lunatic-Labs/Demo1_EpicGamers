#include "../include/Player.h"
#include "../include/GameState.h"
#include <iostream>

namespace EpicGamers
{
	Player::Player(GameDataRef _data, sf::Color currentColor) : data(_data)
	{
		// load all of the individual animation frames
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
		playerSprite.setColor(currentColor);
		//playerSprite.setSize(64.0f, 64.0f);
		playerSprite.setPosition(0.0f,
			(data->window.getSize().y - playerSprite.getGlobalBounds().height - 138.0f));

		// initialize location and state
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
	{
		// if more time has passed than the given frame rate (time spent on current frame compared to total duration)

		// if in the air
		if (PLAYER_STATE_JUMPING == playerState || PLAYER_STATE_FALLING == playerState)
		{
			if (clock.getElapsedTime().asSeconds() > (JUMP_DURATION) / (animationFrames.size() / 2))
			{
				if (jumping == false)
				{
					// start jump animation
					animationIterator = 10;
					jumping = true;
				}
				if (animationIterator < 19)
				{
					// move to next frame
					animationIterator++;
				}
				else if (playerState != PLAYER_STATE_STILL)
				{
					// stay on the last jump frame while still airborne
					animationIterator = 18;
				}

				// match the displayed texture to the correct frame
				playerSprite.setTexture(animationFrames.at(animationIterator));
				clock.restart();
			}
		}
		// if not in the air
		else
		{
			jumping = false;
		}

		// default running animation
		if (clock.getElapsedTime().asSeconds() > PLAYER_ANIMATION_DURATION / (animationFrames.size() / 2))
		{
			if (animationIterator < 9)
			{
				// move to next frame
				animationIterator++;
			}
			else
			{
				// reset to 1st frame
				animationIterator = 0;
			}

			// match the displayed texture to the correct frame
			playerSprite.setTexture(animationFrames.at(animationIterator));
			clock.restart();
		}
	}

	void Player::update(float dt)
	{
		// move player according to the player state 
		if (PLAYER_STATE_STILL == playerState)
		{
			playerSprite.move(0, 0);
		}
		else if (PLAYER_STATE_FALLING == playerState)
		{
			ySpeed += gravity;
			playerSprite.move(0, ySpeed * dt);
		}
		else if (PLAYER_STATE_JUMPING == playerState)
		{
			ySpeed = -jumpSpeed;
			playerSprite.move(0, ySpeed * dt);

			data->assets.PlaySound("jump");
		}

		// update State Machine based on Player's position after Jumping
		if (playerSprite.getPosition().y >= playerY)
		{
			// prevent player from falling through the ground
			playerSprite.setPosition(playerSprite.getPosition().x, playerY);

			// play landing sound only on the 1st frame on the ground
			if (playerState != PLAYER_STATE_STILL) {
				data->assets.PlaySound("land");
			}

			playerState = PLAYER_STATE_STILL;
		}
		else if (movementClock.getElapsedTime().asSeconds() > jumpHeight)
		{
			playerState = PLAYER_STATE_FALLING;
		}

		// automatically move Player from left to desired X location (game Intro animation)
		if (playerSprite.getPosition().x < playerX)
		{
			playerSprite.move(2.5, 0);
		}
	}

	// updates State Machine when input received
	void Player::tap(float currentSpeed, float jumpDuration, float speedJump, float speedGravity)
	{
		if (playerState != PLAYER_STATE_JUMPING && playerState != PLAYER_STATE_FALLING)
		{
			// update the Player variables with the ones from GameState
			// movementClock.restart();
			speed = currentSpeed;
			jumpHeight = jumpDuration;
			jumpSpeed = speedJump;
			gravity = speedGravity;
			playerState = PLAYER_STATE_JUMPING;
			//animationIterator = 0;	//Attempted to reset the iterator immediately when ground's touched so JumpAnim called again. Caused the RunAnim to play.
		}
	}

	const sf::Sprite& Player::GetSprite() const
	{
		return playerSprite;
	}
}
