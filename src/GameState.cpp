#pragma once

#include "../include/GameState.h"
#include "../include/DEFINITIONS.h"
#include "../include/Hydrant.h"
#include "../include/GameOverState.h"
#include <sstream>
#include <stdlib.h>


#include <iostream>

namespace EpicGamers
{
	GameState::GameState(GameDataRef data) : data(data)
	{

	}

	void GameState::Init()
	{
		std::cout << "Game State" << std::endl;

		data->assets.InitAudio();

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
		
		data->assets.LoadTexture("Scoring Pipe", SCORING_HYDRANT_FILEPATH);		//Part of score video
		data->assets.LoadFont("Dog Font", DOG_FONT_FILEPATH );				//Part of score video

		data->assets.LoadTexture("Hydrant", HYDRANT_FILEPATH);
		hydrant = new Hydrant(data);

		data->assets.LoadTexture("Ground", GROUND_FILEPATH);
		ground = new Ground(data);

		data->assets.LoadTexture("Jump Frame 1", JUMP_FRAME_1_FILEPATH);
		data->assets.LoadTexture("Jump Frame 2", JUMP_FRAME_2_FILEPATH);
		data->assets.LoadTexture("Jump Frame 3", JUMP_FRAME_3_FILEPATH);
		data->assets.LoadTexture("Jump Frame 4", JUMP_FRAME_4_FILEPATH);
		data->assets.LoadTexture("Jump Frame 5", JUMP_FRAME_5_FILEPATH);
		data->assets.LoadTexture("Jump Frame 6", JUMP_FRAME_6_FILEPATH);
		data->assets.LoadTexture("Jump Frame 7", JUMP_FRAME_7_FILEPATH);
		data->assets.LoadTexture("Jump Frame 8", JUMP_FRAME_8_FILEPATH);
		data->assets.LoadTexture("Jump Frame 9", JUMP_FRAME_9_FILEPATH);
		data->assets.LoadTexture("Jump Frame 10", JUMP_FRAME_10_FILEPATH);

		player = new Player(data);
		hud = new HUD( data );

		background.setTexture(this->data->assets.GetTexture("Game Background"));

		gameState = GameStates::ePlaying;

		score = 0;
		hud->UpdateScore( score );
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
			if (sf::Event::KeyPressed == event.type)
			{
				if (event.key.code == 57)
				{
					if (GameStates::eGameOver != gameState)
					{
						gameState = GameStates::ePlaying;
						player->tap();
					}
				}
			}
		}
	}

	void GameState::Update(float dt)
	{
		if (GameStates::eGameOver != gameState)
		{
			
			ground->MoveGround(dt);
			player->animate(dt);
		}
		if (GameStates::ePlaying == gameState)
		{
			hydrant->MoveHydrants(dt);
			srand(time(0));
			float spawnFrequency = rand() % 3 + 1.4;
			if (clock.getElapsedTime().asSeconds() > spawnFrequency)
			{
				hydrant->SpawnHydrant();
				hydrant->SpawnScoringHydrant();
				clock.restart();
			}
			player->update(dt);
			std::vector<sf::Sprite> hydrantSprites = hydrant->GetSprites();
			for (int i = 0; i < hydrantSprites.size(); i++)
			{
				// collision with obstacle
				if (collider.CheckSpriteCollider(player->GetSprite(), 0.6f, hydrantSprites.at(i), 0.4f))
				{
					data->assets.PlaySound("death");
					gameState = GameStates::eGameOver;
					clock.restart();
				}
			}
		}

		

		

			//Part of score video:
		if ( GameStates::ePlaying == gameState )
		{
			std::vector<sf::Sprite> &scoringSprites = hydrant->GetScoringSprites();

			for ( int i = 0; i < scoringSprites.size( ); i++ )
			{
				if ( collider.CheckSpriteCollider( player->GetSprite( ), 0.625f, scoringSprites.at( i ), 1.0f ) && GameStates::eGameOver != gameState)
				{
					score++;
					
					hud->UpdateScore( score );
					
					scoringSprites.erase( scoringSprites.begin( ) + i );
				}
			}
		}
		

		if (GameStates::eGameOver == gameState)
		{
			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				data->machine.AddState(StateRef(new GameOverState(data, score)), true);
			}
		}
	}

	void GameState::Draw(float dt)
	{
		data->window.clear();
		data->window.draw(background);
		ground->DrawGround();
		hydrant->DrawHydrants();
		player->draw();
		hud->Draw(); 

		data->window.display();
	}
}