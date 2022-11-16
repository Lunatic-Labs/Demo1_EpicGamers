#pragma once

#include <sstream>
#include <iostream>
#include "../include/GameOverState.h"
#include "../include/DEFINITIONS.h"
#include "../include/GameState.h"

namespace EpicGamers
{
	GameOverState::GameOverState(GameDataRef data) : data(data)
	{

	}

	void GameOverState::Init()
	{
		std::cout << "Game Over State" << std::endl;
		data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		//data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);	Cole #28 Video
		//data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);		Cole #28 Video
		background.setTexture(this->data->assets.GetTexture("Game Over Background"));
		//gameOverTitle.setTexture(this->data->assets.GetTexture("Game Over Title"));		Cole #28 Video
		//gameOverContainer.setTexture(this->data->assets.GetTexture("Game Over Body"));	Cole #28 Video
		//retryButton.setTexture(this->data->assets.GetTexture("Play Button"));				Cole #28 Video
	
		//gameOverContainer.setPosition((data->window.getSize().x / 2) - (gameOverContainer.getGlobalBounds().width / 2),(data->window.getSize().y / 2) - (gameOverContainer.getGlobalBounds().height / 2));	Cole #28 Video
		//gameOverTitle.setPosition((data->window.getSize().x / 2) - (gameOverTitle.getGlobalBounds().width / 2), gameOverContainer.getPosition().y - (gameOverTitle.getGlobalBounds().height * 1.2));			Cole #28 Video
		//retryButton.setPosition((data->window.getSize().x / 2) - (retryButton.getGlobalBounds().width / 2), gameOverContainer.getPosition().y + gameOverContainer.getGlobalBounds().height + (retryButton.getGlobalBounds().height * 0.2));	Cole #28 Video
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
			
			/* Cole #28 Video:
			if (data->input.IsSpriteClicked(retryButton, sf::Mouse::Left, data->window)) 
			{
				data->machine.AddState(StateRef(new GameState(data)), true);
			}
			*/
		}
	}

	void GameOverState::Update(float dt)
	{
	}

	void GameOverState::Draw(float dt)
	{
		data->window.clear();
		data->window.draw(background);
		//data->window.draw(gameOverTitle);		Cole #28 Video
		//data->window.draw(gameOverContainer);	Cole #28 Video
		//data->window.draw(RetryButton);		Cole #28 Video
		data->window.display();
	}
}