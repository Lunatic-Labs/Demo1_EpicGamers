#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Hydrant.h"
#include "Ground.h"
#include "Player.h"

namespace EpicGamers
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data;
		sf::Sprite background;

		Hydrant* hydrant;
		Ground* ground;
		Player *player;

		sf::Clock clock;

		/*sf::SoundBuffer _jumpSoundBuffer;
		sf::SoundBuffer _deathSoundBuffer;
		sf::SoundBuffer _landSoundBuffer;
		sf::SoundBuffer _collectibleSoundBuffer;*/

		/*sf::Sound _jumpSound;
		sf::Sound _deathSound;
		sf::Sound _landSound;
		sf::Sound _collectibleSound;*/

	};

}