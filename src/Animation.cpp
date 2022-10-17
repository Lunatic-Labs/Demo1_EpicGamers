#include "../include/Animation.h"

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

void Animation::Update(int row, float deltaTime, bool startJump) 
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (row == 1 && startJump == true) {
		currentImage.x = 0;
	}

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
		
		if (currentImage.x >= imageCount.x)
			currentImage.x = 0;
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;

}

//Ground doesn't use a static sprite size like player does. 
//I'm incrementing it by tile (tile width != spriteWidth) for a scrolling effect
void Animation::GroundUpdate(double lastSpriteLeft, double firstSpriteLeft, double moveBy, float deltaTime) 
{
	totalTime += deltaTime;

	if (totalTime >= (switchTime*1.5)) {	//multiplying by 1.5 to slow down animation. *1 is full speed, *2 is halftime
		totalTime -= (switchTime*1.5);
		if (uvRect.left >= lastSpriteLeft)
			uvRect.left = firstSpriteLeft;
		else
			uvRect.left += moveBy;
	}
}