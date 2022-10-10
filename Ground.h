#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

//Setting up similarly to the Player class, but only animation functionality. 
class Ground
{
public:
	Ground(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Ground();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f getPosition() { return body.getPosition(); }
private:
	sf::RectangleShape body;
	Animation animation;
	float speed;
};