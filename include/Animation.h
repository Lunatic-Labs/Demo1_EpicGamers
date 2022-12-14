/*
	The Animation Player iterates through spritesheets to update textures.
	This functionality is currently handled in GameState instead.
*/

#pragma once
#include <SFML/Graphics.hpp>

namespace EpicGamers {
	class Animation
	{
	public:
		Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
		~Animation();

		void Update(int row, float deltaTime, bool startJump, float speedMultiplier);
		//void GroundUpdate(double lastSpriteLeft, double firstSpriteLeft, double moveBy, float deltaTime, float speedMultiplier);
	private:

	public:
		sf::IntRect uvRect;

	private:
		sf::Vector2u imageCount;
		sf::Vector2u currentImage;

		float totalTime, switchTime;
	};
}


