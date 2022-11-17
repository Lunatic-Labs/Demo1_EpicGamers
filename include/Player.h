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
		const sf::Sprite& GetSprite() const;

	private:
		GameDataRef data;
		sf::Sprite playerSprite;
		std::vector<sf::Texture> animationFrames;

		unsigned int animationIterator;		//current frame being displayed
		
		/*sf::SoundBuffer _jumpSoundBuffer;
		sf::SoundBuffer _deathSoundBuffer;
		sf::SoundBuffer _landSoundBuffer;
		sf::SoundBuffer _collectibleSoundBuffer;

		sf::Sound _jumpSound;
		sf::Sound _deathSound;
		sf::Sound _landSound;
		sf::Sound _collectibleSound;*/

		sf::Clock clock;
		sf::Clock movementClock;

		int playerState = PLAYER_STATE_FALLING;
		double playerX;			//desired x-value for Player. Using in intro "animation".
		double playerY;			//desired y-value, using for Jump functionality/State machine.

		float ySpeed;					//used in Jump movement functionality
		bool jumping = false;			//used in Jump animation functionality
		bool playedJumpAnim = false;		//used in Jump animation functionality
	};
}

