#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINITIONS.h"
#include "Game.h"


namespace EpicGamers
{
	class Player {
	public:
		Player(GameDataRef _data);
		void draw();
		void animate(float dt);
		void update(float dt);
		void tap();

	private:
		GameDataRef data;
		sf::Sprite playerSprite;
		std::vector<sf::Texture> animationFrames;

		unsigned int animationIterator;		//current frame being displayed

		sf::Clock clock;
		sf::Clock movementClock;

		int playerState;
	};
}

