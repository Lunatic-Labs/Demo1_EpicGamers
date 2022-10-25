#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player {
	public:
		Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, int healthPoints);
		~Player();

		void Update(float deltaTime, bool jumpInput, float speedMultiplier);
		void Draw(sf::RenderWindow& window);
		void TakeDamage();

		sf::Vector2f getPosition() { return body.getPosition(); }
		Collider getCollider() { return Collider(body); }

	private:
		sf::RectangleShape body;
		Animation animation;
		sf::Vector2f movement{ 0.0f, 0.0f };
		sf::Clock jumpTimer;
		unsigned int row;
		float speed;
		int healthPoints;
		bool faceRight, startJump{ false };
};

