#include "../include/Ground.h"
#include <iostream>
//Currently WIP. Hoping to set up scroll functionality similar to Player, by reading a spritesheet

//Ground::Ground(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
//	animation(texture, imageCount, switchTime)
//{
//	this->speed = speed;
//	sf::RectangleShape groundScroll;
//	sidewalk.setSize(sf::Vector2f(128.0f, 32.0f));	//size of one sprite in pixels?
//	sidewalk.setOrigin(0.0f, -127.0f);
//	sidewalk.setTexture(texture);
//}
//
//Ground::~Ground() {
//
//}
//
//void Ground::Update(float deltaTime, float speedMultiplier) {
//	//sf::Vector2f movement(0.0f, 0.0f);
//
//	//update the sprite row, set texture, and move the sprite
//	animation.GroundUpdate(383.0f, 0.0f, 16.0f, deltaTime, speedMultiplier);	// all Ground sprites in one row, row always == 0
//	sidewalk.setTextureRect(animation.uvRect);
//	//body.move(movement);
//}
//
//void Ground::Draw(sf::RenderWindow & window) {
//	window.draw(sidewalk);
//}

Ground::Ground(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}
Ground::~Ground()
{

}
void Ground::draw(sf::RenderWindow& window)
{
	window.draw(body);
}