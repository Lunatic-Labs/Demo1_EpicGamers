#pragma once

#include <SFML/Graphics.hpp>
#include "../include/State.h"
#include "../include/Game.h"

namespace EpicGamers
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();
		void HandleInput(); 
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data;
		sf::Sprite background;
		sf::Sprite title;
		sf::Sprite playButton;
	};

}