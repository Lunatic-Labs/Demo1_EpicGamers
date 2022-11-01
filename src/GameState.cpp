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
		data->assets.LoadTexture("Player Frame 1", PLAYER_FRAME_1_FILEPATH);	//load filepath for every Player frame given in DEFINTIONS.h
		data->assets.LoadTexture("Player Frame 2", PLAYER_FRAME_2_FILEPATH);	
		data->assets.LoadTexture("Player Frame 3", PLAYER_FRAME_3_FILEPATH);	
		data->assets.LoadTexture("Player Frame 4", PLAYER_FRAME_4_FILEPATH);	
		data->assets.LoadTexture("Player Frame 5", PLAYER_FRAME_5_FILEPATH);	
		data->assets.LoadTexture("Player Frame 6", PLAYER_FRAME_6_FILEPATH);	
		data->assets.LoadTexture("Player Frame 7", PLAYER_FRAME_7_FILEPATH);	
		data->assets.LoadTexture("Player Frame 8", PLAYER_FRAME_8_FILEPATH);	
		data->assets.LoadTexture("Player Frame 9", PLAYER_FRAME_9_FILEPATH);	
		data->assets.LoadTexture("Player Frame 10", PLAYER_FRAME_10_FILEPATH);	

		data->assets.LoadTexture("Hydrant", HYDRANT_FILEPATH);
		Hydrant = new Hydrant(data);

		player = new Player(data);

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
		//Insert Obstacle functionality here

		player->animate(dt);
	}

	void GameState::Draw(float dt)
	{
		data->window.clear();
		data->window.draw(background);
		Hydrant->drawHydrants( );
		
		player->draw();

		data->window.display();
	}
}