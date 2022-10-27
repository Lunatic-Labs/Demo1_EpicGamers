#pragma once

#include <sstream>
#include "../include/GameState.h"
#include "../include/DEFINITIONS.h"

#include <iostream>

namespace EpicGamers
{
	GameState::GameState(GameDataRef data) : data(data)
	{

	}

	void GameState::Init()
	{
		std::cout << "Game State" << std::endl;
		data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		background.setTexture(this->data->assets.GetTexture("Game Background"));
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				data->window.close();
			}
		}
	}

	void GameState::Update(float dt)
	{
	}

	void GameState::Draw(float dt)
	{
		data->window.clear();
		data->window.draw(background);
		data->window.display();
	}
}