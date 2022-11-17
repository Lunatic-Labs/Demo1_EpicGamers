#pragma once

#include <SFML/Graphics.hpp>
#include "../include/State.h"
#include "../include/Game.h"

namespace EpicGamers
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data); // add parameter int score);	Cole #29 Video

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef data;
		sf::Sprite background;
		sf::Sprite gameOverTitle; 		//Cole #28 Video
		sf::Sprite gameOverContainer;	//Cole #28 Video
		sf::Sprite retryButton;			//Cole #28 Video
	
		//sf::Text scoreText;			//Cole #29 Video
		//sf::Text highScoreText;		//Cole #29 Video

		//int score;					//Cole #29 Video
		//int highScore;				//Cole #29 Video
	};
}