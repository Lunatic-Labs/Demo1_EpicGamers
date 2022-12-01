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
		currentSpeed = STARTING_SPEED;			//initializing speed variables to reset them when game is restart? Maybe?
		speedClock.restart();

		// load core gameplay assets
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

		data->assets.PlayMusic("levelMusic");
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (data->window.pollEvent(event))
		{
			// close window if exited
			if (sf::Event::Closed == event.type)
			{
				data->window.close();
			}
			// check for jump input and change state accordingly
			if (sf::Event::KeyPressed == event.type)
			{
				if (event.key.code == 57)
				{
					if (GameStates::eGameOver != gameState)
					{
						gameState = GameStates::ePlaying;
						player->tap(currentSpeed, jumpDuration, jumpSpeed, gravity);
					}
				}
			}
		}
	}

	void GameState::Update(float dt)
	{
		if (GameStates::ePlaying == gameState)
		{
			// move the ground
			ground->MoveGround(dt, currentSpeed);
			player->animate(dt);

			// move the hydrants and randomize their spawn frequency
			hydrant->MoveHydrants(dt, currentSpeed);
			srand(time(0));
			float spawnFrequency = rand() % 3 + 1.4;
			if (clock.getElapsedTime().asSeconds() > (spawnFrequency))
			{
				hydrant->SpawnHydrant();
				hydrant->SpawnScoringHydrant();
				clock.restart();
			}

			// then update the player
			player->update(dt);

			// handle collision for the hydrants
			std::vector<sf::Sprite> hydrantSprites = hydrant->GetSprites();
			for (int i = 0; i < hydrantSprites.size(); i++)
			{
				// if player collides with obstacle, then it's Game Over
				if (collider.CheckSpriteCollider(player->GetSprite(), 0.6f, hydrantSprites.at(i), 0.4f))
				{
					data->assets.PlaySound("death");
					gameState = GameStates::eGameOver;
					clock.restart();
				}
			}

			// handle collision for the score-triggering boxes
			std::vector<sf::Sprite>& scoringSprites = hydrant->GetScoringSprites();
			for (int i = 0; i < scoringSprites.size(); i++)
			{
				// if player collides with scoring box, then increase the score
				if (collider.CheckSpriteCollider(player->GetSprite(), 0.625f, scoringSprites.at(i), 1.0f) && GameStates::eGameOver != gameState)
				{
					data->assets.PlaySound("collectible");
					score++;
					hud->UpdateScore(score);
					scoringSprites.erase(scoringSprites.begin() + i);
				}
			}

			// increase the speed of the game over time
			if (speedClock.getElapsedTime().asSeconds() >= TIME_BEFORE_SPEED_INCREMENT)
			{
				if (currentSpeed <= MAX_SPEED)
				{
					currentSpeed += INCREMENT_SPEED_BY;
					jumpDuration -= INCREMENT_JUMP_TIME_BY;
					jumpSpeed += INCREMENT_JUMP_SPEED_BY;
					gravity += INCREMENT_GRAVITY_BY;
					std::cout << "Speed Up! New Speed: " << currentSpeed << std::endl;
					speedClock.restart();
				}
			}
		}

		if (GameStates::eGameOver == gameState)
		{
			// stop music
			data->assets.StopMusic("levelMusic");

			// change game state to GameOver after a delay
			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				data->machine.AddState(StateRef(new GameOverState(data, score)), true);
			}
		}

		
	}

	void GameState::Draw(float dt)
	{
		// clear the previous frame and draw the new one on screen
		data->window.clear();
		data->window.draw(background);
		ground->DrawGround();
		hydrant->DrawHydrants();
		player->draw();
		hud->Draw(); 

		data->window.display();
	}
}