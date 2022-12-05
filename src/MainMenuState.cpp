/*
	The Main Menu state activates after loading the game and viewing the Spash
	Screen. This also shows the official logo for the game, functioning as the
	title screen. After clicking the Play button, the game enters GameState.
*/

#pragma once

#include <sstream>
#include "../include/MainMenuState.h"
#include "../include/GameState.h"
#include "../include/DEFINITIONS.h"

#include <iostream>

namespace EpicGamers
{
	MainMenuState::MainMenuState(GameDataRef data) : data(data)
	{

	}

	void MainMenuState::Init()
	{
		data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		
		background.setTexture(this->data->assets.GetTexture("Main Menu Background"));
		title.setTexture(this->data->assets.GetTexture("Game Title"));
		playButton.setTexture(this->data->assets.GetTexture("Play Button"));

		//title.setScale((SCREEN_WIDTH/2), (SCREEN_HEIGHT/2));

		title.setPosition((SCREEN_WIDTH) / 2 - (title.getGlobalBounds().width / 2), title.getGlobalBounds().height / 3);
		playButton.setPosition((SCREEN_WIDTH) / 2 - (playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT) / 2 - (playButton.getGlobalBounds().height / 20));

		data->assets.PlayMusic("levelAmbience");
	}


	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (data->window.pollEvent(event))
		{
			// close window if exited
			if (sf::Event::Closed == event.type)
			{
				data->window.close();
			}

			// enter a new game if the play button is clicked
			if (data->input.isSpriteClicked(playButton, sf::Mouse::Left, data->window))
			{
				//std::cout << "Go to Game Screen";
				data->machine.AddState(StateRef(new GameState(data)), true);
			}
		}
	}

	void MainMenuState::Update(float dt)
	{
		
	}

	void MainMenuState::Draw(float dt)
	{
		data->window.clear();
		data->window.draw(background);
		data->window.draw(title);
		data->window.draw(playButton);
		data->window.display();
	}
}