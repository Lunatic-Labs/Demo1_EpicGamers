#pragma once

#include <sstream>
#include <iostream>
#include "../include/GameOverState.h"
#include "../include/DEFINITIONS.h"

namespace EpicGamers
{
	GameOverState::GameOverState(GameDataRef data) : data(data)
	{

	}

	void GameOverState::Init()
	{
		std::cout << "Game Over State" << std::endl;
		data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

		background.setTexture(this->data->assets.GetTexture("Game Over Background"));
	}

	void GameOverState::HandleInput()
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

	void GameOverState::Update(float dt)
	{
	}

	void GameOverState::Draw(float dt)
	{
		data->window.clear();
		data->window.draw(background);
		data->window.display();
	}
}