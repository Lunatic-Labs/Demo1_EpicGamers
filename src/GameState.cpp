#pragma once

#include <sstream>
#include "../include/GameState.h"
#include "../include/DEFINITIONS.h"
#include "../include/Hydrant.h"
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

		/*if (!_jumpSoundBuffer.loadFromFile(SFX_JUMP_FILEPATH))				//What is all this? Why is it commented out?
		{
			std::cout << "Error loading jump sound." << std::endl;
		}
		if (!_landSoundBuffer.loadFromFile(SFX_LAND_FILEPATH))
		{
			std::cout << "Error loading land sound." << std::endl;
		}
		if (!_deathSoundBuffer.loadFromFile(SFX_DEATH_FILEPATH))
		{
			std::cout << "Error loading death sound." << std::endl;
		}
		if (!_collectibleSoundBuffer.loadFromFile(SFX_COLLECTIBLE_FILEPATH))
		{
			std::cout << "Error loading collectible sound." << std::endl;
		}

		_jumpSound.setBuffer(_jumpSoundBuffer);
		_landSound.setBuffer(_landSoundBuffer);
		_deathSound.setBuffer(_deathSoundBuffer);
		_collectibleSound.setBuffer(_collectibleSoundBuffer);*/

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
		
		//data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);		Part of score video
		//data->assets.LoadFont("Dog Font", DOG_FONT_FILEPATH );				Part of score video

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
		//hud = new HUD( data );

		background.setTexture(this->data->assets.GetTexture("Game Background"));

		//score = 0;
		//hud->UpdateScore( score );
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
					player->tap();

					//_jumpSound.play();
				}
			}
		}
	}

	void GameState::Update(float dt)
	{
		srand(time(0));
		float spawnFrequency = rand() % 3 + 1.4;
		hydrant->MoveHydrants(dt);
		ground->MoveGround(dt);
		if (clock.getElapsedTime().asSeconds() > spawnFrequency)
		{
			hydrant->SpawnHydrant();
			//hydrant->SpawnScoringHydrant();
			std::cout <<  spawnFrequency <<"  drawing hydrant\n";
			clock.restart();
		}
		player->animate(dt);
		player->update(dt);

		/*	Part of score video:
		if ( GameStates::ePlaying == gameState )
		{
			std::vector<sf::Sprite> &scoringSprites = hydrant->GetScoringSprites();

			for ( int i = 0; i < scoring.Sprites.size( ); i++ )
			{
				if ( collision.CheckSpriteCollision( bird->GetSprite( ) **[unsure what our "bird" is]** , 0.625f, scoringSprites.at( i ), 1.0f ) )
				{
					score++;
					
					hud->UpdateScore( score );
					
					scoringSprites.erase( scoringSprites.begin( ) + i );
				}
			}
		}
		*/
	}

	void GameState::Draw(float dt)
	{
		data->window.clear();
		data->window.draw(background);
		ground->DrawGround();
		hydrant->DrawHydrants();
		player->draw();
		//hud->Draw(); 

		data->window.display();
	}
}