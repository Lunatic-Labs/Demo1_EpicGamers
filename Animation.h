#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime);
	void GroundUpdate(double lastSpriteLeft, double firstSpriteLeft, double moveBy);
private:

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime, switchTime;
};

