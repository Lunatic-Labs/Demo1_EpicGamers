#pragma once

#include <sstream>
#include <iostream>
#include <fstream>
#include "../include/GameOverState.h"
#include "../include/DEFINITIONS.h"
#include "../include/GameState.h"

namespace EpicGamers
{				//int score parameter to function call  Cole #29 Video
	GameOverState::GameOverState(GameDataRef data) : data(data)//, score(score)	//Cole #29 Video
	{

	}

	void GameOverState::Init()
	{
		std::cout << "Game Over State" << std::endl;

		std::ifstream readFile;						//Cole #30 Video
		readFile.open(HIGH_SCORE_FILEPATH);			//Cole #30 Video

		// Cole #30 Video:
		/*if (readFile.is_open())
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
		writeFile.close();*/
		
	
		data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);	//Cole #28 Video
		data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);		//Cole #28 Video
		background.setTexture(this->data->assets.GetTexture("Game Over Background"));
		gameOverTitle.setTexture(this->data->assets.GetTexture("Game Over Title"));			//Cole #28 Video
		gameOverContainer.setTexture(this->data->assets.GetTexture("Game Over Body"));		//Cole #28 Video
		retryButton.setTexture(this->data->assets.GetTexture("Play Button"));				//Cole #28 Video
	
		//gameOverContainer.setPosition((data->window.getSize().x / 2) - (gameOverContainer.getGlobalBounds().width / 2),(data->window.getSize().y / 2) - (gameOverContainer.getGlobalBounds().height / 2));		//Cole #28 Video
		//gameOverTitle.setPosition((data->window.getSize().x / 2) - (gameOverTitle.getGlobalBounds().width / 2), gameOverContainer.getPosition().y - (gameOverTitle.getGlobalBounds().height * 1.2));			//Cole #28 Video
		//retryButton.setPosition((data->window.getSize().x / 2) - (retryButton.getGlobalBounds().width / 2), gameOverContainer.getPosition().y + gameOverContainer.getGlobalBounds().height + (retryButton.getGlobalBounds().height * 0.2));	//Cole #28 Video
	
		//scoreText.setFont(data->assets.GetFont("Dog Font"));		Cole #29 Video
		//scoreText.setString(std::to_string(score));				//Cole #29 Video
		//scoreText.setCharacterSize(56);							Cole #29 Video
		//scoreText.setFillColor(sf::Color::White);
		//scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);		//Cole #29 Video
		//scoreText.setPosition(data->window.getSize().x / 10 * 7.25f, data->window.getSize().y / 2.15f);				//Cole #29 Video
	
		//highScoreText.setFont(data->assets.GetFont("Dog Font"));		Cole #29 Video
		//highScoreText.setString(std::to_string(highScore));				//Cole #29 Video
		//highScoreText.setCharacterSize(56);							Cole #29 Video
		//highScoreText.setFillColor(sf::Color::White);
		//highScoreText.setOrigin(highScoreText.getGlobalBounds().width / 2, highScoreText.getGlobalBounds().height / 2);		//Cole #29 Video
		//highScoreText.setPosition(data->window.getSize().x / 10 * 7.25f, data->window.getSize().y / 1.78f);				//Cole #29 Video
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
			
			// Cole #28 Video:
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
		data->window.draw(gameOverTitle);		//Cole #28 Video
		data->window.draw(gameOverContainer);	//Cole #28 Video
		data->window.draw(retryButton);			//Cole #28 Video
		//data->window.draw(scoreText);			//Cole #29 Video
		//data->window.draw(highScoreText);		//Cole #29 Video
		data->window.display();
	}
}