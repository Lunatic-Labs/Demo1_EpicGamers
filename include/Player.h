#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime, bool jumpInput);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f getPosition() { return body.getPosition(); }

private:
	sf::RectangleShape body;
	Animation animation;
	sf::Vector2f movement{ 0.0f, 0.0f };
	sf::Clock jumpTimer;
	unsigned int row;
	float speed;
	bool faceRight, startJump{ false };
};

