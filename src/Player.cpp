#include "../include/Player.h"
#include <iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;			//determines which sprite row is passed to Animation class. 0 = walk, 1= jump.
	faceRight = true;

	body.setSize(sf::Vector2f(64.0f, 64.0f));
	body.setOrigin(300.0f, -75.0f);
	body.setTexture(texture);
}

Player::~Player() {

}

void Player::Update(float  deltaTime, bool jumpInput, float speedMultiplier) {
	float jumpHeight = 200.0f;

	if (jumpInput) {
		row = 1;
		if (startJump == false && jumpTimer.getElapsedTime().asSeconds() > (0.80f*speedMultiplier)) {	
			startJump = true;		// used to play jump animation from beginning. Exactly 1.0s long, * speed.
			jumpTimer.restart();	
			movement.y = -sqrtf(2.0f * 981.0f * jumpHeight);	// set jump movement
		}
		else                        // runs at end of jump cycle if Space is still held. Restarts cycle.
			startJump = false;
	}
	
	// start falling if above ground and jump animation is halfway completed
	if (body.getPosition().y < 0.0f && jumpTimer.getElapsedTime().asSeconds() > (0.50f*speedMultiplier)) {	
		movement.y = sqrtf(2.0f * 981.0f * jumpHeight);
		startJump = false;
	}
	// resets player to ground level if below it
	else if (body.getPosition().y > 0.0f && !jumpInput && jumpTimer.getElapsedTime().asSeconds() > (0.80f*speedMultiplier)) {
		movement.y = -body.getPosition().y;	//position - 0, which is just position.
		row = 0;
		startJump = false;
	}
	// default case, player is on the ground
	else if (jumpTimer.getElapsedTime().asSeconds() > (0.80f*speedMultiplier)) {
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