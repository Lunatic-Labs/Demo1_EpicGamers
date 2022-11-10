#pragma once

#include <memory>
#include <string>
//#include <../External/include/SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/StateMachine.h"
#include "../include/AssetManager.h"
#include "../include/InputManager.h"

namespace EpicGamers
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};
	
	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int widht, int height, std::string title);

	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock clock;

		GameDataRef data = std::make_shared<GameData>();

		void Run();
	};
}