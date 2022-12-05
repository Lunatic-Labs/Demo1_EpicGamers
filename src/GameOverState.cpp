/*
	The Game Over state activates after the player dies.
*/

#pragma once

#include <sstream>
#include <iostream>
#include <fstream>
#include "../include/GameOverState.h"
#include "../include/DEFINITIONS.h"
#include "../include/GameState.h"

namespace EpicGamers
{
	GameOverState::GameOverState(GameDataRef data, int score) : data(data)
	{
		GameOverState::score = score;
	}

	void GameOverState::Init()
	{
		std::cout << "Game Over State" << std::endl;
		std::cout << "Game Over Score :" << score << std::endl;
		std::ifstream readFile;
		readFile.open(HIGH_SCORE_FILEPATH);

		// read and modify high score, if changed
		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> highScore;
			}
		}
		readFile.close();
		std::ofstream writeFile(HIGH_SCORE_FILEPATH);
		if (writeFile.is_open())
		{
			if (score > highScore)
			{
				highScore = score;
			}
			writeFile << highScore;
		}
		writeFile.close();
		
		// load assets for Game Over screen
		data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
		data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
		background.setTexture(this->data->assets.GetTexture("Game Over Background"));
		gameOverTitle.setTexture(this->data->assets.GetTexture("Game Over Title"));
		gameOverContainer.setTexture(this->data->assets.GetTexture("Game Over Body"));
		retryButton.setTexture(this->data->assets.GetTexture("Play Button"));
		retryButton.setPosition((SCREEN_WIDTH) / 2 - (retryButton.getGlobalBounds().width / 2), data->window.getSize().y - retryButton.getGlobalBounds().height - 70.0f);

		scoreText.setFont(data->assets.GetFont("Dog Font"));
		scoreText.setString(std::to_string(score));
		scoreText.setCharacterSize(56);
		scoreText.setFillColor(sf::Color(210, 111, 93));
		scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);
		scoreText.setPosition(data->window.getSize().x / 16 * 7.25f, data->window.getSize().y / 1.41f);
	
		highScoreText.setFont(data->assets.GetFont("Dog Font"));
		highScoreText.setString(std::to_string(highScore));
		highScoreText.setCharacterSize(56);
		highScoreText.setFillColor(sf::Color(210, 111, 93));
		highScoreText.setOrigin(highScoreText.getGlobalBounds().width / 2, highScoreText.getGlobalBounds().height / 2);
		highScoreText.setPosition(data->window.getSize().x / 11 * 7.25f, data->window.getSize().y / 1.41f);
	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (data->window.pollEvent(event))
		{
			// close window if exited
			if (sf::Event::Closed == event.type)
			{
				data->window.close();
			}
			
			// return to GameState when button is clicked
			if (data->input.isSpriteClicked(retryButton, sf::Mouse::Left, data->window)) 
			{
				data->machine.AddState(StateRef(new GameState(data)), true);
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
		data->window.draw(gameOverTitle);
		data->window.draw(gameOverContainer);
		data->window.draw(retryButton);
		data->window.draw(scoreText);
		data->window.draw(highScoreText);
		data->window.display();
	}
}