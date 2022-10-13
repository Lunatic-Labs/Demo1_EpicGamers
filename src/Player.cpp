#include "../include/Player.h"
#include <iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(64.0f, 64.0f));
	body.setOrigin(300.0f, -100.0f);
	//body.setPosition(0.0f, 500.0f);
	body.setTexture(texture); 
}

Player::~Player()
{

}

void Player::Update(float  deltaTime, bool jumpInput)
{
	sf::Vector2f movement(0.0f, 0.0f);
	float gravity = 100.0f;
	float jumpHeight = 400.0f;
	std::cout << "Player Update: " << jumpInput << std::endl;

	// check input (Overwriting to be read as function parameter)
	//bool jumpInput = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

	// jump
	if (jumpInput) {
		std::cout << "Jumping\n";
		movement.y -= jumpHeight * deltaTime;
		movement.x += jumpHeight * deltaTime;
	}

	// apply gravity
	movement.y += gravity * deltaTime;


	// change sprite row
	if (movement.x == 0.0f) {
		row = 0;
	}
	else {
		row = 1;
	}
		
	// update the sprite row
	animation.Update(row, 
					 deltaTime);
	
	// set texture
	body.setTextureRect(animation.uvRect);

	// move the player
	body.move(movement); 
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}