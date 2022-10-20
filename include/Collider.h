#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void  move(float dx, float dy) { body.move(dx, dy); }
	bool checkCollision(Collider& other, float push); //push variable allows the object to be moved 
	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body;

};

