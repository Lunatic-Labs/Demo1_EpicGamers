#pragma once

#include <SFML/Graphics.hpp>
#include "../include/State.h"
#include "../include/Game.h"
#include "../include/Hydrant.h"
#include "../include/Ground.h"
#include "../include/Player.h"
#include "../include/HUD.h"

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

		Hydrant *hydrant;
		Ground *ground;
		Player *player;
		HUD *hud; 

		sf::Clock clock;

		/*sf::SoundBuffer _jumpSoundBuffer;				//What is all this? Why is it commented out?
		sf::SoundBuffer _deathSoundBuffer;
		sf::SoundBuffer _landSoundBuffer;
		sf::SoundBuffer _collectibleSoundBuffer;*/

		/*sf::Sound _jumpSound;
		sf::Sound _deathSound;
		sf::Sound _landSound;
		sf::Sound _collectibleSound;*/

		int score;
	};

}