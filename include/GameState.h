#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Hydrant.h"
#include "Ground.h"
#include "Player.h"
#include "Collider.h"
//#include "HUD.h"

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
		//HUD* hud;
		Collider collider;
		sf::Clock clock;

		int gameState;
		int score;
	};

}