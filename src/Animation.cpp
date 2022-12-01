#include "../include/Animation.h"

namespace EpicGamers {
	Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
	{
		this->imageCount = imageCount;
		this->switchTime = switchTime;
		totalTime = 0.0f;
		currentImage.x = 0;
		currentImage.y = 0;
		uvRect.width = texture->getSize().x / float(imageCount.x);
		uvRect.height = texture->getSize().y / float(imageCount.y);
	}
	Animation::~Animation()
	{

	}

	void Animation::Update(int row, float deltaTime, bool startJump, float speedMultiplier)
	{
		currentImage.y = row;
		totalTime += deltaTime;

		// change index on spritesheet
		if (row == 1 && startJump == true)
		{
			currentImage.x = 0;
		}
		if (totalTime >= (switchTime * speedMultiplier))
		{
			totalTime -= (switchTime * speedMultiplier);
			currentImage.x++;

			if (currentImage.x >= imageCount.x)
			{
				currentImage.x = 0;
			}

		}

		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top = currentImage.y * uvRect.height;

	}

	// ground doesn't use a static sprite size like player does. 
	// it increments by tile (tile width != spriteWidth) for a scrolling effect
	//void Animation::GroundUpdate(double lastSpriteLeft, double firstSpriteLeft, double moveBy, float deltaTime, float speedMultiplier) {
	//	totalTime += deltaTime;
	//	// speedMultiplier determines how fast animation plays. *1.5 is solid speed *1 is full speed, *2 is halftime
	//	if (totalTime >= (switchTime*speedMultiplier)) {	
	//		totalTime -= (switchTime*speedMultiplier);
	//		if (uvRect.left >= lastSpriteLeft)
	//			uvRect.left = firstSpriteLeft;
	//		else
	//			uvRect.left += moveBy;
	//	}
	//}
}