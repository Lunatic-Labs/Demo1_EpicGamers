#pragma once

#include <SFML/Graphics.hpp>
#include "../include/State.h"
#include "../include/Game.h"

namespace EpicGamers
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data;
		sf::Sprite background;
		//sf::Sprite gameOverTitle; 	 Cole #28 Video
		//sf::Sprite gameOverContainer;  Cole #28 Video
		//sf::Sprite retryButton;		 Cole #28 Video
	};
}