#include "../include/Player.h"
#include <iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;															// !! document what "row" is for
	faceRight = true;

	body.setSize(sf::Vector2f(64.0f, 64.0f));
	body.setOrigin(300.0f, -75.0f);
	//body.setPosition(0.0f, 500.0f);									// !! document why this is commented out
	body.setTexture(texture);
}

Player::~Player() {

}

void Player::Update(float  deltaTime, bool jumpInput, float speedMultiplier) {
	if (jumpInput) {
		row = 1;
		if (startJump == false && jumpTimer.getElapsedTime().asSeconds() > 0.90f) {	
			startJump = true;		// used to play jump animation from beginning. Exactly 1.0s long.
			jumpTimer.restart();	
			movement.y = 400.0f;	// set jump movement				// !! make this a variable
		}
		else                        // runs at end of jump cycle if Space is still held. Restarts cycle.
			startJump = false;
	}

	// start falling if above ground and jump animation is halfway completed
	if (body.getPosition().y > 0.0f && jumpTimer.getElapsedTime().asSeconds() > 0.50f) {	
		movement.y = -400.0f;
		startJump = false;
	}
	// resets player to ground level if below it
	else if (body.getPosition().y < 0.0f && !jumpInput && jumpTimer.getElapsedTime().asSeconds() > 0.90f) {
		movement.y = 400.0f;		
		row = 0;
		startJump = false;
	}
	// default case, player is on the ground
	else if (jumpTimer.getElapsedTime().asSeconds() > 0.90f) {
		movement.y = 0.0f;
		row = 0;
		startJump = false;
	}

	// update the sprite row
	animation.Update(row, deltaTime, startJump, speedMultiplier);
	
	// set texture
	body.setTextureRect(animation.uvRect);

	// move the player
	body.move(movement); 
}

void Player::Draw(sf::RenderWindow& window) {
	window.draw(body);
}