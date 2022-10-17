#include "../include/Player.h"
#include <iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(64.0f, 64.0f));
	body.setOrigin(300.0f, -75.0f);
	//body.setPosition(0.0f, 500.0f);
	body.setTexture(texture); 
}

Player::~Player()
{

}

void Player::Update(float  deltaTime, bool jumpInput)
{
	float gravity = 100.0f;
	float jumpHeight = 400.0f;


	// jump and change sprite row
	if (jumpInput) {
		movement.y = 400.0f;	//set jump movement
		row = 1;
	}
	else if (body.getPosition().y > -75.0f && !jumpInput)
	{
		movement.y = -400.f;	//set falling movement
		row = 0;
	}
	else if (body.getPosition().y < -75.0f && !jumpInput)
	{
		movement.y = 400.f;		//corrective movement, to get back to "ground level"
		row = 0;
	}
	else {
		movement.y = 0.0f;
		row = 0;
	}

	// apply gravity - equates to <= 1, so commenting out
	//movement.y += gravity * deltaTime;

	// change sprite row
	/*if (movement.x == 0.0f) {
		row = 0;
	}
	else {
		row = 1;
	}*/
		
	// update the sprite row
	animation.Update(row, deltaTime);
	
	// set texture
	body.setTextureRect(animation.uvRect);

	// move the player
	body.move(movement); 
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}