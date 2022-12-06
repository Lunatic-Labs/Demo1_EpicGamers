/*
	The Splash Screen state activates immediately after running the game. It shows
	a quick screen while assets load, and it then immediately enters the Main Menu
	state.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace EpicGamers
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);
		
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data;
		sf::Clock clock;
		sf::Sprite background;
	};

}