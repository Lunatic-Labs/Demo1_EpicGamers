#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

namespace EpicGamers
{
	class Ground
	{
	public: 
		Ground(GameDataRef data);
		
		void MoveGround(float dt, float currentSpeed);
		void DrawGround();

	private:
		GameDataRef data;

		std::vector<sf::Sprite> groundSprites;
	};
}
