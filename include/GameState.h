#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Hydrant.h"
#include "Ground.h"
#include "Player.h"
#include "Collider.h"
#include "HUD.h"

namespace EpicGamers
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		int randomNumber(int low, int high);
		float randomFloat(float low, float high);
		sf::Color getRandomColor();

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data;
		sf::Sprite background;

		Hydrant* hydrant;
		Ground* ground;
		Player* player;
		HUD* hud;
		Collider collider;
		sf::Clock clock;

		int gameState;
		int score;

		float currentSpeed = STARTING_SPEED;
		float jumpDuration = JUMP_DURATION;
		float jumpSpeed = JUMP_SPEED;
		float gravity = GRAVITY;
		float hydrantMinSpawnTime = HYDRANT_MIN_SPAWN_TIME;
		float hydrantMaxSpawnTime = HYDRANT_MAX_SPAWN_TIME;
		sf::Clock speedClock;
	};

}