#pragma once

#include <SFML/Graphics.hpp>
#include "../include/State.h"
#include "../include/Game.h"
#include "../include/Player.h"

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

		Player *player;
	};

}